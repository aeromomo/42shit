/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andmore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:04:54 by ymeng             #+#    #+#             */
/*   Updated: 2017/02/02 14:05:10 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.h"
extern int g_linenbr;
extern char g_syml[3];

int		chksymb(char *buf)
{
	int		symlnbr;
	int		chk;

	chk = 0;
	symlnbr = 0;
	while (*buf != '\n' && (symlnbr < 4))
	{
		if (!is_nbr(*buf))
		{
			g_syml[symlnbr] = *buf;
			symlnbr++;
		}
		buf++;
		if (symlnbr == 3 && (*buf != '\n'))
			return (0);
	}
	buf++;
	while (*buf)
	{
		if ((*buf == g_syml[0]) || (*buf == g_syml[1]) || (*buf == '\n'))
		chk++;
		else
			return (0);
		buf++;
	}
	return (1);
}

int		chckall(char *buf)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (*buf != '\n')
	buf++;
	buf++;
	while (*buf)
	{
		if (*buf == g_syml[0])
		a++;
		if (*buf == g_syml[1])
		b++;
		buf++;
	}
	return (a && b);
}
int		is_nbr(char n)
{
	if (('0' <= n) && (n <= '9'))
		return (1);
	else
		return (0);
}

int		gridchk(char *buf)
{
	int		colm;
	int		line;

	line = 0;
	colm = 0;
	while (*buf != '\n')
	buf++;
	buf++;
	while (*buf)
	{
		if (*buf != '\n')
		colm++;
		if (*buf == '\n')
		{
			if ((*(buf+g_linenbr+1) != '\n') && ((g_linenbr-1) != line))
			return (0);
			line++;
		}
		buf++;
	}
	if ((colm == (line * g_linenbr)) &&( colm == (line * line)) && (colm == (g_linenbr * g_linenbr)))
	return (1);
	else
	return (0);
}
