/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 06:37:16 by kito          #+#    #+#                 */
/*   Updated: 2020/12/01 16:41:42 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p_list;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p_list = *lst;
	while (p_list->next != NULL)
	{
		p_list = p_list->next;
	}
	p_list->next = new;
}
