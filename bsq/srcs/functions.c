/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:05:30 by ymeng             #+#    #+#             */
/*   Updated: 2017/02/02 14:05:39 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
extern int g_linenbr;
extern char g_syml[3];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		min(int a, int b, int c)
{
	int m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

int		**malloc_2d(void)
{
	int x;
	int **p;

	x = 0;
	p = (int **)malloc(g_linenbr * sizeof(int *));
	while (x < g_linenbr)
	{
		p[x] = (int *)malloc(g_linenbr * sizeof(int));
		x++;
	}
	return (p);
}

int		validator(char *buf)
{
	g_linenbr = ft_atoi(buf);
	if (gridchk(buf)&& chksymb(buf)&& chckall(buf))
		return (1);
	else
		errorprinter();
	return (0);
}

int		**returnedges(int **star)
{
	int i;
	int j;
	int **d;

	i = 0;
	j = 0;
	d = malloc_2d();
	while (i < g_linenbr)
	{
		d[i][0] = star[i][0];
		i++;
	}
	while (j < g_linenbr)
	{
		d[0][j] = star[0][j];
		j++;
	}
	return (d);
}
