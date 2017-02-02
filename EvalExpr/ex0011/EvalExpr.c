/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:02:22 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 21:46:09 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "/includes/EvalExpr.h"



#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


int		ft_isdigit(char c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	else
		return (0);
}
