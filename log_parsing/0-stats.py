#!/usr/bin/python3
"""
Log Parsing Script

Reads stdin line by line, extracts file size and status codes, 
and prints statistics every 10 lines or upon a keyboard interrupt.
"""

import sys
import re

# Dictionary to store count of each status code
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
total_size = 0
line_count = 0

def print_stats():
    """Prints the accumulated metrics."""
    print("File size:", total_size)
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

try:
    for line in sys.stdin:
        try:
            parts = line.split()
            if len(parts) < 9:
                continue
            
            file_size = int(parts[-1])
            status_code = int(parts[-2])
            
            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1
            
            line_count += 1
            if line_count % 10 == 0:
                print_stats()
        except (ValueError, IndexError):
            continue
except KeyboardInterrupt:
    print_stats()
    raise
