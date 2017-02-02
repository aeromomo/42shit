/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:06:22 by ymeng             #+#    #+#             */
/*   Updated: 2017/02/02 14:06:25 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
int g_linenbr = 0;
char	g_syml[3];

int		**rd_from_file(char *buf)
{
	int	ptr;
	int	x;
	int y;
	int **game;

	game = malloc_2d();
	ptr = 0;
	x = 0;
	y = 0;
	while (buf[ptr] != '\n')
		ptr++;
	ptr++;
	while (buf[ptr] != '\0')
	{
		while (buf[ptr] != '\n')
		{
			if (buf[ptr] == g_syml[0])
				game[x][y] = 1;
			else
				game[x][y] = 0;
			x++;
			ptr++;
		}
		x = 0;
		y++;
		ptr++;
	}
	return (game);
}

void	printsizesubmatrix(int i2, int j2, int s, int **map)
{
	int h;
	int k;

	h = 0;
	k = 0;
	while (h < g_linenbr)
	{
		while (k < g_linenbr)
		{
			if (k <= j2 && h <= i2 && k >= (j2 - s + 1) && h >= (i2 - s + 1))
				ft_putchar(g_syml[2]);
			else if (map[k][h] != 0)
				ft_putchar(g_syml[0]);
			else
				ft_putchar(g_syml[1]);
			k++;
		}
		k = 0;
		ft_putchar('\n');
		h++;
	}
	ft_putchar('\n');
}

void	printmaxsubsquare(int **map)
{
	int **d;
	int s;
	int ip;
	int jp;

	s = 0;
	d = returnedges(map);
	d = minesweeper(map, d);
	s = findmatrixandcord(d, &ip, &jp);
	printsizesubmatrix(ip, jp, s, map);
}

int		display_file(char *fname)
{
	int		fp;
	// int		ptr;
	char	*buf;

	buf=(char*)malloc(sizeof(*buf) * (BUF_SZ + 1));
	fp = open(fname, O_RDONLY);
	if (fp == -1)
	{
		errorprinter();
		return (1);
	}
	read(fp, buf, BUF_SZ);
		if (validator(buf))
			printmaxsubsquare(rd_from_file(buf));
	if (close(fp) == -1)
	{
		errorprinter();
		return (1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc == 1)
		write(1, "File name missing\n", 18);
	if (argc >= 2)
	{
		while (argv[i])
		{
			g_linenbr = 0;
			display_file(argv[i]);
			i++;
		}
	}
	return (0);
}
