/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:16:13 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/27 14:27:42 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *dest, char *src){
	int i=0;
	while (*src) {
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = *src;
	return (dest-i);
}
int main() {
	char a[20]="";
	printf("%s\n",ft_strcpy(a,"i like ike") );
	return 0;
}
