/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:21:55 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/25 15:18:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir_lst	*init_redir_lst(void)
{
	t_redir_lst	*new;

	new = malloc(sizeof(t_redir_lst));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

t_redir_node	*init_redir_node(void)
{
	t_redir_node	*new;

	new = malloc(sizeof(t_redir_node));
	if (!new)
		return (NULL);
	new->file = NULL;
	new->next = NULL;
	return (new);
}

t_redir_lst	*add_redir_lst(t_redir_lst *lst, t_redir_node *node)
{
	if (!node)
		return (NULL);
	if (!lst->head)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		lst->tail = node;
	}
	lst->size++;
	return (lst);
}

void	print_redir(t_redir_lst *lst)
{
	t_redir_node	*cpy;

	if (!lst)
		return ;
	cpy = lst->head;
	while (cpy)
	{
		printf(">> [TYPE] : %c	>> [FILE] : %s\n", cpy->type, cpy->file);
		cpy = cpy->next;
	}
}

void	clear_redir_lst(t_redir_lst *lst)
{
	t_redir_node	*tmp;

	if (!lst)
		return ;
	while (lst->head)
	{
		free(lst->head->file);
		tmp = lst->head->next;
		free(lst->head);
		lst->head = tmp;
	}
	free(lst);
}
