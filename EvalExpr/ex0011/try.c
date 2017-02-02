/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:56:09 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 22:58:30 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/EvalExpr.h"
// #include "./includes/structs.h"

// #include "./includes/structs.h"

// unsigned int G_STRING_ITERATOR = 0;

/*
* expr:= term term_tail
* term_tail := add_op term term_tail | e
* term:= factor factor_tail
* factor_tail := mult_op factor factor_tail | e
* factor:= ( expr ) | number
* add_op:= + | -
* mult_op := * | /
*/

/* Will "consume" a character from the input,
* (such as +, -, *, etc.) and return it.
* By consume, I'm really just moving the pointer
* forward and disregarding the character for
* future purposes.
*/
extern unsigned int G_STRING_ITERATOR = 0;



Expr* expression(char* string);

Expr* factor(char* string, Expr* expr)
{
	if(string[G_STRING_ITERATOR] == '(')
	{
		expr->op = consume_char(string, '(');
		expr->data.expr[0] = expression(string);
		consume_char(string, ')');
	}
	else if(ft_isdigit(string[G_STRING_ITERATOR]))
	{
		expr->op = 'd';
		expr->data.terminal = consume_int(string);
	}
	return expr;
}

Expr* factor_tail(char* string, Expr* expr)
{
	Expr* new_expr;

	if ((string[G_STRING_ITERATOR] == '*') || (string[G_STRING_ITERATOR] == '%') || (string[G_STRING_ITERATOR] == '/'))
	{
		if(NULL == (new_expr = (Expr*)malloc(sizeof(Expr))))
		exit(1);
		if(NULL == (new_expr->data.expr[1] = (Expr*)malloc(sizeof(Expr))))
		exit(1);
		new_expr->op = consume_char(string, string[G_STRING_ITERATOR]);
		new_expr->data.expr[0] = expr;
		new_expr->data.expr[1] = factor(string, new_expr->data.expr[1]);
		new_expr = factor_tail(string, new_expr);
		return new_expr;
	}
	else if ((string[G_STRING_ITERATOR] == '+') || (string[G_STRING_ITERATOR] == '-') || (string[G_STRING_ITERATOR] == ')') || (string[G_STRING_ITERATOR] == 0))
		return expr;
	else
		exit(1);
	return (NULL);
}

Expr* term(char* string, Expr* expr)
{
	if(string[G_STRING_ITERATOR] == '(' || ft_isdigit(string[G_STRING_ITERATOR]))
	{
		expr = factor(string, expr);
		expr = factor_tail(string, expr);
		return expr;
	}
	else
		exit(1);
	return (NULL);
}

Expr* term_tail(char* string, Expr* expr)
{
	Expr* new_expr;
	if ((string[G_STRING_ITERATOR] == '+') || (string[G_STRING_ITERATOR] == '-'))
	{
		if(NULL == (new_expr = (Expr*)malloc(sizeof(Expr))))
		exit(1);
		if(NULL == (new_expr->data.expr[1] = (Expr*)malloc(sizeof(Expr))))
		exit(1);
		new_expr->op = consume_char(string, string[G_STRING_ITERATOR]);
		new_expr->data.expr[0] = expr;
		new_expr->data.expr[1] = term(string, new_expr->data.expr[1]);
		new_expr = term_tail(string, new_expr);
		return new_expr;
	}
	else if ((string[G_STRING_ITERATOR] == ')') || (string[G_STRING_ITERATOR] == 0))
		return expr;
	else
		exit(1);
	return (NULL);
}

Expr* expression(char* string)
{
	Expr* expr;

	if(string[G_STRING_ITERATOR] == '(' || ft_isdigit(string[G_STRING_ITERATOR]))
	{
		if(NULL == (expr = (Expr*)malloc(sizeof(Expr) +9)))
		exit(1);
		expr = term(string, expr);
		expr = term_tail(string, expr);
		return expr;
	}
	else
		exit(1);
	return (NULL);
}

/* Runs through the AST, evaluating and freeing
* the tree as it goes.
*/
// int evaluate(Expr* expr)
// {
// 	int ret;
// 	if (expr->op == '(')
// 	{
// 		ret = evaluate(expr->data.expr[0]);
// 		free(expr->data.expr[0]);
// 	}
// 	if ((expr->op == '*') || (expr->op == '/') || (expr->op == '+') || (expr->op == '-') || (expr->op == '%'))
// 	{
// 		if (expr->op == '*')
// 			ret = evaluate(expr->data.expr[0]) * evaluate(expr->data.expr[1]);
// 		if (expr->op == '/')
// 			ret = evaluate(expr->data.expr[0]) / evaluate(expr->data.expr[1]);
// 		if (expr->op == '+')
// 			ret = evaluate(expr->data.expr[0]) + evaluate(expr->data.expr[1]);
// 		if (expr->op == '-')
// 			ret = evaluate(expr->data.expr[0]) - evaluate(expr->data.expr[1]);
// 		if (expr->op == '%')
// 			ret = evaluate(expr->data.expr[0]) % evaluate(expr->data.expr[1]);
// 		free(expr->data.expr[0]);
// 		free(expr->data.expr[1]);
// 	}
// 	if (expr->op == 'd')
// 		ret = expr->data.terminal;
// 	return ret;
// }

int main(int argc, char** argv)
{
	Expr* expr = NULL;

	if(argc > 1)
	{
		expr = expression(split_white_space(argv[1]));
		printf("%d\n", evaluate(expr));
		free(expr);
	}
	return 0;
}
