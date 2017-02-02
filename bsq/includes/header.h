/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:05:20 by ymeng             #+#    #+#             */
/*   Updated: 2017/02/02 14:05:22 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUF_SZ 3276800

int		**malloc_2d(void);
int		**returnedges(int **star);
int		findmatrixandcord(int **d, int *ia, int *jb);
int		is_nbr(char n);
int		**minesweeper(int **map, int **d);
int		gridchk(char *buf);
int		chksymb(char *buf);
int		ft_atoi(const char *str);
int		min(int a, int b, int c);
int		validator(char *buf);
void	ft_putchar(char c);
void	errorprinter(void);
int		chckall(char *buf);

#endif
