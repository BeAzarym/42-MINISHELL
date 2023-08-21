/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:55:06 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/20 23:49:47 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tkn_lst 	*handle_redirect(t_tkn_lst *lst, t_cmd *cmd_node)
{
	t_redir_node *node;

	node = init_redir_node();
	if (!lst)
		return (NULL);
	if (!have_redirect_arg(lst))
		return (NULL);
	if (have_redirect_arg(lst) == 1)
	{
		if (lst->head->type == 'I')
			node->type = 'I';
		else
			node->type = 'O';
		node->file = ft_strdup(lst->head->next->value);
		if (!node->file)
			return (NULL);
	}
	if (have_redirect_arg(lst) == 2)
	{
		if (lst->head->type == 'I')
			node->type = 'H';
		else
			node->type = 'A';
		node->file = ft_strdup(lst->head->next->next->value);
		if (!node->file)
			return (NULL);
	}
	if (lst->head->type == 'I')
		add_redir_lst(cmd_node->redir_in, node);
	else
		add_redir_lst(cmd_node->redir_out, node);
	if (node->type == 'H' || node->type == 'A')
		lst->head = lst->head->next->next->next;
	else
		lst->head = lst->head->next->next;
	return (lst);
}

int	have_redirect_arg(t_tkn_lst *lst)
{
	if (!lst)
		return (0);
	if ((lst->head->type == 'I' || lst->head->type == 'O') && lst->head->next)
	{
		if (lst->head->next->type == 'W')
			return (1);
		else if ((lst->head->next->type == 'I' || lst->head->next->type == 'O')
				&& lst->head->next->next)
		{
			if (lst->head->next->next->type == 'W')
				return (2);
		}
	}
	return (0);
}
