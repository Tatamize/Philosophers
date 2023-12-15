/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:40:33 by kito          #+#    #+#                 */
/*   Updated: 2020/12/01 16:59:13 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ifnodata(t_list *list, t_list *prev, void (*del)(void *))
{
	t_list	*temp;

	temp = NULL;
	while (list != prev)
	{
		temp = list->next;
		del(list->content);
		free(list);
		list = temp;
	}
	del(list->content);
	free(list);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new_start;
	t_list	*prev;

	prev = NULL;
	while (lst != NULL)
	{
		newlist = NULL;
		newlist = ft_calloc(1, sizeof(t_list));
		if (prev == NULL)
		{
			if (!newlist)
				return (NULL);
			new_start = newlist;
		}
		if (!newlist)
			return (ifnodata(new_start, prev, del));
		newlist->content = f(lst->content);
		if (prev != NULL)
			prev->next = newlist;
		prev = newlist;
		lst = lst->next;
	}
	return (new_start);
}
