/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:21:55 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/25 16:03:37 by angassin         ###   ########.fr       */
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
	t_redir_lst	*cpy;

	if (!lst)
		return ;
	cpy = lst;
	printf("[REDIR]\n");
	while (cpy->head)
	{
		printf(">> [TYPE] : %c	>> [FILE] : %s\n", cpy->head->type, cpy->head->file);
		cpy->head = cpy->head->next;
	}
}