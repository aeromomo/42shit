/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumelibs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:58:18 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/29 22:46:20 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
// #include "../includes/EvalExpr.h"

/* Will "consume" a character from the input,
* (such as +, -, *, etc.) and return it.
* By consume, I'm really just moving the pointer
* forward and disregarding the character for
* future purposes.
*/
extern unsigned int G_STRING_ITERATOR = 0;

int		ft_isdigit2(char c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	else
		return (0);
}

void parse_error(const char* string)
{
	unsigned int i;
	fprintf(stderr, "Unexpected symbol '%c' at position %u.\n\n", string[G_STRING_ITERATOR], G_STRING_ITERATOR);
	fprintf(stderr, "String: '%s'\n", string);
	fprintf(stderr, "Problem: ");
	for(i = 0; i < G_STRING_ITERATOR; ++i)
	fprintf(stderr, " ");
	fprintf(stderr, "^\n");
	exit(1);
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

	if(!ft_isdigit2(string[G_STRING_ITERATOR]))
		exit(1);
	/* I don't have to pass in the start of the string
	* into atoi, but only where I want it to start
	* scanning for an integer.
	*/
	i = ft_atoi(string + G_STRING_ITERATOR);
	while(ft_isdigit2(string[G_STRING_ITERATOR]))
		++G_STRING_ITERATOR;
	return i;
}
