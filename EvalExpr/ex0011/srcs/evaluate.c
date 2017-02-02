/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:16:09 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 22:46:48 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"


int evaluate(Expr* expr)
{
	int ret;
	if (expr->op == '(')
	{
		ret = evaluate(expr->data.expr[0]);
		free(expr->data.expr[0]);
	}
	if ((expr->op == '*') || (expr->op == '/') || (expr->op == '+') || (expr->op == '-') || (expr->op == '%'))
	{
		if (expr->op == '*')
			ret = evaluate(expr->data.expr[0]) * evaluate(expr->data.expr[1]);
		if (expr->op == '/')
			ret = evaluate(expr->data.expr[0]) / evaluate(expr->data.expr[1]);
		if (expr->op == '+')
			ret = evaluate(expr->data.expr[0]) + evaluate(expr->data.expr[1]);
		if (expr->op == '-')
			ret = evaluate(expr->data.expr[0]) - evaluate(expr->data.expr[1]);
		if (expr->op == '%')
			ret = evaluate(expr->data.expr[0]) % evaluate(expr->data.expr[1]);
		free(expr->data.expr[0]);
		free(expr->data.expr[1]);
	}
	if (expr->op == 'd')
		ret = expr->data.terminal;
	return ret;
}
