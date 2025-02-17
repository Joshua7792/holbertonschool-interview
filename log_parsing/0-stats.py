#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics.

This script processes input logs and extracts file size and HTTP status code
It prints the total file size and a count of valid status codes every 10 lines.
"""

from sys import stdin

if __name__ == "__main__":
    total_size = 0  # Stores the total file size processed
    status_codes = {}  # Dictionary to track the count of each HTTP status code
    list_status_codes = [
            "200", "301", "400", "401", "403", "404", "405", "500"]

    # Initialize status code dictionary with 0 counts
    for status in list_status_codes:
        status_codes[status] = 0

    count = 0  # Tracks the number of lines processed

    try:
        for line in stdin:
            try:
                args = line.split(" ")  # Split log line into components
                if len(args) != 9:  # Ensure log line has expected format
                    pass

                # Check if the status code is valid and increment its count
                if args[-2] in list_status_codes:
                    status_codes[args[-2]] += 1

                # Handle newline character in file size value
                if args[-1][-1] == '\n':
                    args[-1][:-1]

                # Accumulate total file size
                total_size += int(args[-1])
            except (IndexError, ValueError):
                pass  # Ignore lines that do not match the expected format

            count += 1  # Increment processed line count

            # Print statistics every 10 lines
            if count % 10 == 0:
                print("File size: {}".format(total_size))
                for status in sorted(status_codes.keys()):
                    if status_codes[status] != 0:
                        print("{}: {}".format(
                            status, status_codes[status]))

        # Print final statistics after processing all input
        print("File size: {}".format(total_size))
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))

    except KeyboardInterrupt as err:
        # Handle keyboard interrupt and print final statistics before exiting
        print("File size: {}".format(total_size))
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))
        raise  # Re-raise the exception to terminate execution

if __name__ == "__main__":
    main()
