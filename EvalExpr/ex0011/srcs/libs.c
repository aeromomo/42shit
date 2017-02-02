/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:26:09 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 22:58:18 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/structs.h"
extern unsigned int G_STRING_ITERATOR = 0;
int		ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int	i;
	int	res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			sign = (str[i] == '+') ? 1 : -1;
			i++;
		}
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + sign * (str[i++] - '0');
	return (res);
}

char	*split_white_space(char *shit) {
	char *shomeshit;
	int i = 0;
	int j = 0;
	int k = 0;

	while (shit[k] != '\0')
	{
		k++;
	}
	shomeshit = (char*)malloc(sizeof(*shomeshit) * (k + 1));
	while (shit[i] != '\0')
	{
		if (!ft_is_whitespace(shit[i]))
		{
			shomeshit[j] = shit[i];
			i++;
			j++;
		}
		else
			i++;
	}
	shomeshit[j] ='\0';
	return (shomeshit);
}

char consume_char(const char* string, char c)
{
	if(string[G_STRING_ITERATOR] != c)
		exit(1);
	++G_STRING_ITERATOR;
	return c;
}

/* Same as consume_char, except for integers.
*/
int consume_int(char* string)
{
	int i;

	if(!ft_isdigit(string[G_STRING_ITERATOR]))
		exit(1);
	/* I don't have to pass in the start of the string
	* into atoi, but only where I want it to start
	* scanning for an integer.
	*/
	i = ft_atoi(string + G_STRING_ITERATOR);
	while(ft_isdigit(string[G_STRING_ITERATOR]))
		++G_STRING_ITERATOR;
	return i;
}
int		ft_isdigit(char c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	else
		return (0);
}
