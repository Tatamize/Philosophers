/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:52:27 by kito          #+#    #+#                 */
/*   Updated: 2020/12/01 07:35:57 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*p_newlist;

	p_newlist = ft_calloc(1, sizeof(t_list));
	if (p_newlist == NULL)
		return (NULL);
	p_newlist->content = content;
	p_newlist->next = NULL;
	return (p_newlist);
}
