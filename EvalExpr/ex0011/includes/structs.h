/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:06:42 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 22:45:09 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned int G_STRING_ITERATOR = 0;

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
