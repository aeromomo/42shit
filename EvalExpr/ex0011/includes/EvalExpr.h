/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:04:11 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 22:58:19 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../srcs/libs.c"
// #include "../srcs/printlibs.c"
// // #include "../srcs/evaluate.c"
// #include "../srcs/consumelibs.c"
// #include <stdlib.h>
// #include <stdio.h>
// #include "./structs.h"


// extern unsigned int G_STRING_ITERATOR = 0;
typedef struct
{
	int terminal;
	struct expression* expr[2];
} Data;

typedef struct expression
{
	char op;
	Data data;
} Expr;

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
int			ft_atoi(char *str);
int			ft_is_whitespace(char c);
char		*split_white_space(char *shit);
int			ft_isdigit(char c);
// int		evaluate(Expr* expr);
extern char	consume_char(const char* string, char c);
extern int	consume_int(char* string);
