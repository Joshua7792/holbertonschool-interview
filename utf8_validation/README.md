# UTF-8 Validation

## Description
This project implements a function to validate whether a given data set represents a valid UTF-8 encoding.

## Requirements
- The script must be written in Python 3.4.3.
- Code must follow PEP 8 (version 1.7.x) style guide.
- All files must be executable.
- The function should handle UTF-8 characters that are 1 to 4 bytes long.
- Each integer in the input list represents one byte of data.

## Usage
To test the function, create a `0-main.py` file with the following content:

```python
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))  # True

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True

data = [229, 65, 127, 256]
print(validUTF8(data))  # False
```

Run the test with:
```bash
chmod +x 0-main.py
./0-main.py
```

## Repository Structure
```
utf8_validation/
│── README.md
│── 0-validate_utf8.py
│── 0-main.py
```

- Holberton School Interview Preparation