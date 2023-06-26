/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:14:31 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/26 14:29:47 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void add_back(t_token *src, t_token *new)
{
	t_token *last; 
	
	if (!new)
		return ;
	if (!src)
	{
		src = new;
		src->next = NULL;
	}
	else
	{
		last = get_lstlast(src);
		last->next = new;
	}
}

t_token	*get_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	clear_lst(t_token *lst)
{
	if (!lst)
		return;
	while (lst)
	{
		free(lst->value);
		lst = lst->next;
	}
	free(lst);
}