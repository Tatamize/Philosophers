/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 10:28:12 by kito          #+#    #+#                 */
/*   Updated: 2020/12/01 09:32:58 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_list;
	t_list	*next;

	p_list = *lst;
	next = p_list;
	while (p_list->next != NULL)
	{
		next = p_list->next;
		del(p_list->content);
		free(p_list);
		p_list = next;
	}
	del(p_list->content);
	free(p_list);
	*lst = NULL;
}
