/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:16:13 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/27 16:54:01 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// char    *ft_strcpy(char *dest, char *src){
// 	int i=0;
// 	while (*src) {
// 		*dest = *src;
// 		dest++;
// 		src++;
// 		i++;
// 	}
// 	*dest = *src;
// 	return (dest-i);
// }
char *ft_strrev(char *str){
	char temp;
	int i,j;
	j=0;
	i=-1;
	while (str[j]) {
		j++;
	}
	while (++i < --j ) {
		temp = str[i];
		str[i] = str[j];
		str[j] =temp;
	}
	return(str);
}
// char		*ft_strrev(char *str)
// {
// 	int		i;
// 	int		l;
// 	char	t;
//
// 	l = 0;
// 	while (str[l] != '\0')
// 		l++;
// 	i = -1;
// 	while (++i < --l)
// 	{
// 		t = str[i];
// 		str[i] = str[l];
// 		str[l] = t;
// 	}
// 	return (str);
// }
int main() {
	char c[5]="abcde";
	// ft_strrev(c);
	// char a[20]="";
	printf("%s\n",ft_strrev(c) );
	return 0;
}
