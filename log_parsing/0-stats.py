#!/usr/bin/python3
"""
Log Parsing Script

This script reads lines from stdin, extracts file sizes and HTTP status codes,
and prints statistics every 10 lines or upon receiving a keyboard interrupt.
"""

import sys
import re

def print_stats(total_size, status_codes):
    """Print accumulated statistics."""
    print("File size:", total_size)
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

def extract_info(line):
    """Extracts status code and file size from a log line if it's in the correct format."""
    try:
        line = line.strip()
        pattern = r'^\S+ - \[.*\] "GET /projects/260 HTTP/1.1" (\d{3}) (\d+)$'
        match = re.match(pattern, line)
        if match:
            return int(match.group(1)), int(match.group(2))
    except Exception:
        pass
    return None, None  # Return None if the line format is incorrect

def main():
    """Main function to process log lines."""
    total_size = 0
    line_count = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    try:
        for line in sys.stdin:
            status_code, file_size = extract_info(line)

            # Only process valid lines (both status_code and file_size must be valid)
            if status_code is None or file_size is None:
                continue  # Skip malformed lines

            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_codes)

if __name__ == "__main__":
    main()
