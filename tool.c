#include "ft_rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		isope(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		ft_atoi(char *str)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	if (str[g_j] == '-')
	{
		sign = -1;
		g_j++;
	}
	while (str[g_j] && str[g_j] >= '0' && str[g_j] <= '9')
	{
		res = res * 10 + (str[g_j] - '0');
		g_j++;
	}
	return (res * sign);
}

int		isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}
