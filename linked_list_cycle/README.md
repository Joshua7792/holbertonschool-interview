# Linked List Cycle Detection

## Description
This project is a technical interview preparation task focused on detecting cycles in a singly linked list using Floyd's cycle detection algorithm (tortoise and hare approach).

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compilation on Ubuntu 14.04 LTS using `gcc 4.8.4`
- Compilation flags: `-Wall -Werror -Wextra -pedantic`
- Code follows the Betty coding style
- No global variables allowed
- Maximum of 5 functions per file
- Header file `lists.h` must be include-guarded

## Files
- `0-check_cycle.c` - Function to check if a linked list has a cycle
- `0-main.c` - Main file to test the function
- `0-linked_lists.c` - Helper functions to manage the linked list
- `lists.h` - Header file containing function prototypes and the struct definition

## Compilation
```sh
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

## Usage
Run the compiled program:
```sh
./cycle
```
Expected output:
```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Algorithm Explanation
The function `check_cycle` uses two pointers:
1. `slow` moves one step at a time.
2. `fast` moves two steps at a time.
3. If `slow` and `fast` meet, there is a cycle.
4. If `fast` reaches `NULL`, the list has no cycle.

## Complexity Analysis
- **Time Complexity:** `O(n)` in the worst case.
- **Space Complexity:** `O(1)` (only two pointers are used).