
#include "ft_rush.h"

int		getdigit(int num)
{
	int		digit;

	digit = 1;
	if (num < 0)
	{
		digit++;
		num *= -1;
	}
	while (num >= 10)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}

int		calc(int num1, int num2, char op)
{
	if (op == '+')
		return (num1 + num2);
	if (op == '-')
		return (num2 - num1);
	if (op == '*')
		return (num1 * num2);
	if (op == '/')
		return (num2 / num1);
	else
		return (num2 % num1);
}

void	exec_every_single_op(void)
{
	int		num1;
	int		num2;
	char	op;

	num1 = g_number[--g_i];
	g_number[g_i] = 0;
	num2 = g_number[--g_i];
	op = g_operator[--g_i2];
	g_number[g_i++] = calc(num1, num2, op);
}

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putnbr(int num)
{
	char	tmp;

	tmp = 0;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		tmp = num % 10 + '0';
		write(1, &tmp, 1);
	}
	else
	{
		tmp = num + '0';
		write(1, &tmp, 1);
	}
}
