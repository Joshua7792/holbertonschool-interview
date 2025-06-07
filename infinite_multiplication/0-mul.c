#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * print_error - prints error message and exits
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * is_digit_string - checks if string contains only digits
 * @str: string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit_string(char *str)
{
	int i;

	if (!str || *str == '\0')
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * skip_leading_zeros - skips leading zeros in result
 * @result: result array
 * @len: length of result
 *
 * Return: index of first non-zero digit
 */
int skip_leading_zeros(int *result, int len)
{
	int i;

	for (i = 0; i < len - 1; i++)
	{
		if (result[i] != 0)
			break;
	}
	return (i);
}

/**
 * print_result - prints the multiplication result
 * @result: array containing result digits
 * @len: length of result array
 */
void print_result(int *result, int len)
{
	int i, start;

	start = skip_leading_zeros(result, len);

	for (i = start; i < len; i++)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');
}

/**
 * multiply_numbers - multiplies two number strings
 * @num1: first number string
 * @num2: second number string
 */
void multiply_numbers(char *num1, char *num2)
{
	int len1, len2, len_result;
	int *result;
	int i, j, carry, sum;
	int digit1, digit2;

	len1 = strlen(num1);
	len2 = strlen(num2);
	len_result = len1 + len2;

	result = calloc(len_result, sizeof(int));
	if (!result)
		print_error();

	/* Multiply each digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			sum = digit1 * digit2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i] += carry;
	}

	print_result(result, len_result);
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		print_error();

	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
		print_error();

	multiply_numbers(argv[1], argv[2]);

	return (0);
}
