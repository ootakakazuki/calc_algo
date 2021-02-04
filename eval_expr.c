
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_rush.h"

void	stack_num(char *str, int *flag2)
{
	if (str[g_j] == '(')
	{
		g_j++;
		eval_expr_rec(str, g_i2);
		if (*flag2)
		{
			g_number[g_i] *= -1;
			*flag2 = 0;
		}
		while (g_j < g_len && str[g_j] != ')')
			g_j++;
		if (g_j < g_len && str[g_j] == ')')
			g_j++;
		g_i++;
	}
	else if (str[g_j] && isnum(str[g_j]))
	{
		g_number[g_i] = ft_atoi(str);
		if (*flag2)
		{
			g_number[g_i] *= -1;
			*flag2 = 0;
		}
		g_i++;
	}
}

void	stack_op(char *str, int *flag, int *flag2)
{
	if (isope(str[g_j]))
	{
		if (str[g_j] == '*' || str[g_j] == '/' || str[g_j] == '%')
		{
			*flag = 1;
			g_operator[g_i2++] = str[g_j];
		}
		else if (str[g_j] == '-')
		{
			*flag2 = 1;
			if (is_space(str[g_j + 1]))
				g_operator[g_i2++] = '+';
		}
		else if (str[g_j] == '+')
		{
			g_operator[g_i2++] = '+';
		}
		g_j++;
	}
}

int		eval_expr_rec(char *str, int ope_count)
{
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	while (g_j < g_len && str[g_j] != ')')
	{
		while (g_j < g_len && is_space(str[g_j]))
			g_j++;
		stack_num(str, &flag2);
		if (flag)
		{
			exec_every_single_op();
			flag = 0;
		}
		stack_op(str, &flag, &flag2);
	}
	while (g_i2 != ope_count)
		exec_every_single_op();
	g_i--;
	return (g_number[g_i]);
}

int		eval_expr(char *str)
{
	int		res;

	g_len = ft_strlen(str);
	g_number = (int *)malloc(sizeof(int) * g_len);
	g_operator = (char *)malloc(sizeof(char) * g_len + 1);
	if (g_number == NULL)
		return (0);
	if (g_operator == NULL)
	{
		free(g_number);
		return (0);
	}
	res = eval_expr_rec(str, 0);
	free(g_number);
	free(g_operator);
	return (res);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
