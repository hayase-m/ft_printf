#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	print_test_header(const char *test_name)
{
	printf("\n========================================\n");
	printf(">>> TESTING: %s\n", test_name);
	printf("========================================\n");
}

static void	print_return_values(const char *func_name, int ret_ft, int ret_std,
		const char *case_desc)
{
	printf("[%s] Case: %s\n", func_name, case_desc);
	printf("ft_printf returned: %d\n", ret_ft);
	printf("   printf returned: %d\n", ret_std);
	if (ret_ft == ret_std)
	{
		printf("Return values: MATCH\n");
	}
	else
	{
		printf("Return values: MISMATCH <<<<<<<<<<<<\n");
	}
	printf("----------------------------------------\n");
}

void	test_char_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%c Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("Char: %c, Next: %c, Last: %c\n", 'A', '7', '$');
	printf("   printf: ");
	std_ret = printf("Char: %c, Next: %c, Last: %c\n", 'A', '7', '$');
	print_return_values("%%c", ft_ret, std_ret, "Basic chars");
	printf("ft_printf: ");
	ft_ret = ft_printf("%c", '\0');
	printf("\n   printf: ");
	std_ret = printf("%c", '\0');
	printf("\n");
	print_return_values("%%c", ft_ret, std_ret,
		"Null char (beware of terminal behavior)");
}

void	test_string_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%s Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("String: %s\n", "Hello World!");
	printf("   printf: ");
	std_ret = printf("String: %s\n", "Hello World!");
	print_return_values("%%s", ft_ret, std_ret, "Basic string");
	printf("ft_printf: ");
	ft_ret = ft_printf("Empty string: \"%s\"\n", "");
	printf("   printf: ");
	std_ret = printf("Empty string: \"%s\"\n", "");
	print_return_values("%%s", ft_ret, std_ret, "Empty string");
	printf("ft_printf: ");
	ft_ret = ft_printf("NULL string: %s\n", NULL);
	printf("   printf: ");
	std_ret = printf("NULL string: %s\n", (char *)NULL);
	print_return_values("%%s", ft_ret, std_ret, "NULL string");
}

void	test_pointer_conversions(void)
{
	int		ft_ret;
	int		std_ret;
	int		num;
	char	*str;

	num = 42;
	str = "Test";
	print_test_header("%p Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("Pointer to int: %p\n", &num);
	printf("   printf: ");
	std_ret = printf("Pointer to int: %p\n", &num);
	print_return_values("%%p", ft_ret, std_ret, "Pointer to int");
	printf("ft_printf: ");
	ft_ret = ft_printf("Pointer to char*: %p\n", str);
	printf("   printf: ");
	std_ret = printf("Pointer to char*: %p\n", str);
	print_return_values("%%p", ft_ret, std_ret, "Pointer to char*");
	printf("ft_printf: ");
	ft_ret = ft_printf("NULL pointer: %p\n", NULL);
	printf("   printf: ");
	std_ret = printf("NULL pointer: %p\n", NULL);
	print_return_values("%%p", ft_ret, std_ret, "NULL pointer");
}

void	test_decimal_integer_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%d and %i Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("%d %i\n", 123, -456);
	printf("   printf: ");
	std_ret = printf("%d %i\n", 123, -456);
	print_return_values("%%d %%i", ft_ret, std_ret, "Positive and negative");
	printf("ft_printf: ");
	ft_ret = ft_printf("Zero: %d, Zero: %i\n", 0, 0);
	printf("   printf: ");
	std_ret = printf("Zero: %d, Zero: %i\n", 0, 0);
	print_return_values("%%d %%i", ft_ret, std_ret, "Zero");
	printf("ft_printf: ");
	ft_ret = ft_printf("INT_MAX: %d\n", INT_MAX);
	printf("   printf: ");
	std_ret = printf("INT_MAX: %d\n", INT_MAX);
	print_return_values("%%d", ft_ret, std_ret, "INT_MAX");
	printf("ft_printf: ");
	ft_ret = ft_printf("INT_MIN: %d\n", INT_MIN);
	printf("   printf: ");
	std_ret = printf("INT_MIN: %d\n", INT_MIN);
	print_return_values("%%d", ft_ret, std_ret, "INT_MIN");
}

void	test_unsigned_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%u Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("%u\n", 12345);
	printf("   printf: ");
	std_ret = printf("%u\n", 12345);
	print_return_values("%%u", ft_ret, std_ret, "Positive unsigned");
	printf("ft_printf: ");
	ft_ret = ft_printf("Zero: %u\n", 0);
	printf("   printf: ");
	std_ret = printf("Zero: %u\n", 0);
	print_return_values("%%u", ft_ret, std_ret, "Zero unsigned");
	printf("ft_printf: ");
	ft_ret = ft_printf("UINT_MAX: %u\n", UINT_MAX);
	printf("   printf: ");
	std_ret = printf("UINT_MAX: %u\n", UINT_MAX);
	print_return_values("%%u", ft_ret, std_ret, "UINT_MAX");
}

void	test_hex_lower_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%x Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("%x\n", 0xabcdef12);
	printf("   printf: ");
	std_ret = printf("%x\n", 0xabcdef12);
	print_return_values("%%x", ft_ret, std_ret, "Basic hex");
	printf("ft_printf: ");
	ft_ret = ft_printf("Zero: %x\n", 0);
	printf("   printf: ");
	std_ret = printf("Zero: %x\n", 0);
	print_return_values("%%x", ft_ret, std_ret, "Zero hex");
	printf("ft_printf: ");
	ft_ret = ft_printf("INT_MAX as hex: %x\n", INT_MAX);
	printf("   printf: ");
	std_ret = printf("INT_MAX as hex: %x\n", INT_MAX);
	print_return_values("%%x", ft_ret, std_ret, "INT_MAX as hex");
	printf("ft_printf: ");
	ft_ret = ft_printf("Number 255: %x\n", 255);
	printf("   printf: ");
	std_ret = printf("Number 255: %x\n", 255);
	print_return_values("%%x", ft_ret, std_ret, "Number 255");
}

void	test_hex_upper_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%X Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("%X\n", 0xABCDEF12);
	printf("   printf: ");
	std_ret = printf("%X\n", 0xABCDEF12);
	print_return_values("%%X", ft_ret, std_ret, "Basic hex upper");
	printf("ft_printf: ");
	ft_ret = ft_printf("Zero: %X\n", 0);
	printf("   printf: ");
	std_ret = printf("Zero: %X\n", 0);
	print_return_values("%%X", ft_ret, std_ret, "Zero hex upper");
	printf("ft_printf: ");
	ft_ret = ft_printf("INT_MAX as hex upper: %X\n", INT_MAX);
	printf("   printf: ");
	std_ret = printf("INT_MAX as hex upper: %X\n", INT_MAX);
	print_return_values("%%X", ft_ret, std_ret, "INT_MAX as hex upper");
	printf("ft_printf: ");
	ft_ret = ft_printf("Number 255: %X\n", 255);
	printf("   printf: ");
	std_ret = printf("Number 255: %X\n", 255);
	print_return_values("%%X", ft_ret, std_ret, "Number 255 upper");
}

void	test_percent_conversions(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("%% Conversion");
	printf("ft_printf: ");
	ft_ret = ft_printf("%%\n");
	printf("   printf: ");
	std_ret = printf("%%\n");
	print_return_values("%%", ft_ret, std_ret, "Single percent");
	printf("ft_printf: ");
	ft_ret = ft_printf("%% %%%% %%%%%%\n");
	printf("   printf: ");
	std_ret = printf("%% %%%% %%%%%%\n");
	print_return_values("%%", ft_ret, std_ret, "Multiple percents");
}

void	test_multiple_args_and_conversions(void)
{
	int		ft_ret;
	int		std_ret;
	char	*p;

	p = "pointer";
	print_test_header("Multiple Arguments and Mixed Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("%d %s %c %x %p %u %% %X %i\n", 1, "two", '3', 4, p, 5u,
			6, -7);
	printf("   printf: ");
	std_ret = printf("%d %s %c %x %p %u %% %X %i\n", 1, "two", '3', 4, p, 5u, 6,
			-7);
	print_return_values("Mixed", ft_ret, std_ret, "Various types mixed");
	printf("ft_printf: ");
	ft_ret = ft_printf("No args here %% just percent.\n");
	printf("   printf: ");
	std_ret = printf("No args here %% just percent.\n");
	print_return_values("Mixed", ft_ret, std_ret, "Sentence with percent");
}

void	test_conversions_in_sentence(void)
{
	int	ft_ret;
	int	std_ret;

	print_test_header("Conversions in a Sentence");
	printf("ft_printf: ");
	ft_ret = ft_printf("Value is %d and char is %c.\n", 999, 'Q');
	printf("   printf: ");
	std_ret = printf("Value is %d and char is %c.\n", 999, 'Q');
	print_return_values("Sentence", ft_ret, std_ret,
		"Int and char in sentence");
	printf("ft_printf: ");
	ft_ret = ft_printf("String: %s, Hex: %x, Pointer: %p.\n", "test", 0xcafe,
			NULL);
	printf("   printf: ");
	std_ret = printf("String: %s, Hex: %x, Pointer: %p.\n", "test", 0xcafe,
			NULL);
	print_return_values("Sentence", ft_ret, std_ret, "String, hex,\
		pointer in sentence");
}

void	test_combined_and_consecutive_conversions(void)
{
	int	ft_ret;
	int	std_ret;
	int	var;

	var = 123;
	print_test_header("Combined and Consecutive Conversions");
	printf("ft_printf: ");
	ft_ret = ft_printf("%d%s%p%x%X%%%c%u%i\n", 10, "str", &var, 0xff, 0xEE, 'Z',
			99u, -100);
	printf("   printf: ");
	std_ret = printf("%d%s%p%x%X%%%c%u%i\n", 10, "str", &var, 0xff, 0xEE, 'Z',
			99u, -100);
	print_return_values("Combined", ft_ret, std_ret, "All types consecutively");
	printf("ft_printf: ");
	ft_ret = ft_printf("%d%d%d\n", 1, 22, 333);
	printf("   printf: ");
	std_ret = printf("%d%d%d\n", 1, 22, 333);
	print_return_values("Consecutive", ft_ret, std_ret, "Consecutive %d");
	printf("ft_printf: ");
	ft_ret = ft_printf("%s%s\n", "one", "two");
	printf("   printf: ");
	std_ret = printf("%s%s\n", "one", "two");
	print_return_values("Consecutive", ft_ret, std_ret, "Consecutive %s");
}

void	test_max_int_overflow_error(void)
{
	int			ft_ret;
	long long	overflow_val;
	long long	underflow_val;

	overflow_val = (long long)INT_MAX + 1;
	underflow_val = (long long)INT_MIN - 1;
	print_test_header("MAXINT Overflow 'Error' Test (ft_printf specific)");
	printf("Attempting to print INT_MAX + 1 (as %s): \n", "%d");
	printf("ft_printf output: ");
	fflush(stdout);
	ft_ret = ft_printf("%d\n", overflow_val);
	printf("ft_printf returned: %d\n", ft_ret);
	printf("Standard printf for comparison (casts to int): %d\n",
		(int)overflow_val);
	printf("Check if ft_printf printed 'Error' above as per specification.\n");
	printf("----------------------------------------\n");
	printf("Attempting to print INT_MIN - 1 (as %s): \n", "%d");
	printf("ft_printf output: ");
	fflush(stdout);
	ft_ret = ft_printf("%d\n", underflow_val);
	printf("ft_printf returned: %d\n", ft_ret);
	printf("Standard printf for comparison (casts to int): %d\n",
		(int)underflow_val);
	printf("Check if ft_printf printed 'Error' above as per specification.\n");
}

int	main(void)
{
	printf("Initiating ft_printf test suite...\n");
	test_char_conversions();
	test_string_conversions();
	test_pointer_conversions();
	test_decimal_integer_conversions();
	test_unsigned_conversions();
	test_hex_lower_conversions();
	test_hex_upper_conversions();
	test_percent_conversions();
	test_multiple_args_and_conversions();
	test_conversions_in_sentence();
	test_combined_and_consecutive_conversions();
	test_max_int_overflow_error();
	printf("\nAll ft_printf tests concluded.\n");
	return (0);
}
