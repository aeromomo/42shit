/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morefunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:05:45 by ymeng             #+#    #+#             */
/*   Updated: 2017/02/02 14:05:48 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

extern int g_linenbr;
extern char g_syml[3];

int		**minesweeper(int **map, int **d)
{
	int i;
	int j;

	i = 1;
	while (i < g_linenbr)
	{
		j = 1;
		while (j < g_linenbr)
		{
			if (map[i][j] == 1)
				d[i][j] = min(d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]) + 1;
			else
				d[i][j] = 0;
			j++;
		}
		i++;
	}
	return (d);
}

int		findmatrixandcord(int **d, int *ia, int *jb)
{
	int i;
	int j;
	int s;

	s = 0;
	i = 0;
	while (i < g_linenbr)
	{
		j = 0;
		while (j < g_linenbr)
		{
			if (s < d[j][i])
			{
				s = d[j][i];
				*ia = i;
				*jb = j;
			}
			j++;
		}
		i++;
	}
	return (s);
}

void	errorprinter(void)
{
	write(1, "map error\n", 10);
}

int		ft_atoi(const char *str)
{
	int i;
	int is_pos;
	int num;

	i = 0;
	is_pos = 1;
	num = 0;
	while (str[i] && ((str[i] == ' ') || (str[i] == '\n')))
		i++;
	if (str[i] == '-')
	{
		is_pos = -is_pos;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= is_pos;
	return (num);
}
