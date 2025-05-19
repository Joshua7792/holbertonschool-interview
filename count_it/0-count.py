#!/usr/bin/python3
"""
Module to count keyword occurrences in Reddit hot article titles
"""
import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    """
    Recursively query Reddit API and count occurrences
    of keywords in hot article titles

    Args:
        subreddit (str): The subreddit to search
        word_list (list): List of keywords to count
        after (str, optional): Token for pagination. Defaults to None.
        count_dict (dict, optional): Dictionary to
        track counts. Defaults to None.

    Returns:
        None: Prints the results as specified
    """
    # Initialize count_dict on first call
    if count_dict is None:
        # Convert word list to lowercase and create counter dictionary
        word_list = [word.lower() for word in word_list]
        count_dict = {}
        for word in word_list:
            # If the word already exists in the dictionary, increment its count
            if word in count_dict:
                continue
            count_dict[word] = 0

    # Set up the headers and parameters for the API request
    headers = {'User-Agent': 'Mozilla/5.0 ('
               'Windows NT 10.0; Win64; x64) AppleWebKit/537.36'}
    params = {'limit': 100}
    if after:
        params['after'] = after

    # Make the request to the Reddit API
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    # Check if the subreddit is valid
    if response.status_code != 200:
        return

    # Parse the response
    data = response.json().get('data', {})
    children = data.get('children', [])
    after = data.get('after')

    # Process each post and count keyword occurrences
    for child in children:
        title = child.get('data', {}).get('title', '').lower()
        # Split the title into words
        title_words = title.split()

        # Clean the words by removing any trailing punctuation
        clean_title_words = []
        for word in title_words:
            # Remove trailing punctuation but keep the word itself
            clean_word = word
            while clean_word and not clean_word[-1].isalnum():
                clean_word = clean_word[:-1]

            # Remove leading punctuation
            while clean_word and not clean_word[0].isalnum():
                clean_word = clean_word[1:]

            if clean_word:
                clean_title_words.append(clean_word)

        # Count occurrences
        for word in word_list:
            count_dict[word] += clean_title_words.count(word)

    # If there are more posts to process, make a recursive call
    if after:
        return count_words(subreddit, word_list, after, count_dict)
    else:
        # Sort and print the results
        # Filter out words with zero occurrences
        filtered_counts = {k: v for k, v in count_dict.items() if v > 0}

        # Sort by count (descending) and then by keyword (alphabetically)
        sorted_counts = sorted(filtered_counts.items(),
                               key=lambda x: (-x[1], x[0]))

        # Print the results
        for word, count in sorted_counts:
            print(f"{word}: {count}")
