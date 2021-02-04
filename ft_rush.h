
#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		*g_number;
char	*g_operator;
int		g_i;
int		g_i2;
int		g_j;
int		g_len;
void	ft_putchar(char c);
int		isope(char c);
int		ft_atoi(char *str);
int		isnum(char c);
int		is_space(char c);
int		getdigit(int num);
int		calc(int num1, int num2, char op);
void	exec_every_single_op();
int		ft_strlen(char *str);
void	ft_putnbr(int num);
int		eval_expr_rec(char *str, int ope_count);

#endif
