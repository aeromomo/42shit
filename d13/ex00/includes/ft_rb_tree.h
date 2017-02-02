/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeng <ymeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:57:46 by ymeng             #+#    #+#             */
/*   Updated: 2017/01/27 12:17:56 by ymeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum	e_rb_color
	{
	RB_BLACK,
	RB_RED
	};
typedef struct		s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*right;
	struct s_rb_node	*left;
	void				*data;

}
