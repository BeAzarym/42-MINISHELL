/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:55:06 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/24 16:55:45 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_simple(t_token *lst, t_redir_node *node)
{
	if (lst->type == 'I')
		node->type = 'I';
	else
		node->type = 'O';
	node->file = ft_strdup(lst->next->value);
	if (!node->file)
		return ;
}

static void	handle_double(t_token *lst, t_redir_node *node)
{
	if (lst->type == 'I')
		node->type = 'H';
	else
		node->type = 'A';
	node->file = ft_strdup(lst->next->next->value);
	if (!node->file)
		return ;
}

t_token	*handle_redirect(t_token *lst, t_cmd *cmd_node)
{
	t_redir_node	*node;

	node = init_redir_node();
	if (!lst || !!have_redirect_arg(lst))
		return (NULL);
	if (have_redirect_arg(lst) == 1)
		handle_simple(lst, node);
	else if (have_redirect_arg(lst) == 2)
		handle_double(lst, node);
	if (!node->file)
		return (NULL);
	if (lst->type == 'I')
		add_redir_lst(cmd_node->redir_in, node);
	else
		add_redir_lst(cmd_node->redir_out, node);
	if (node->type == 'H' || node->type == 'A')
		lst = lst->next->next->next;
	else
		lst = lst->next->next;
	return (lst);
}

int	have_redirect_arg(t_token *lst)
{
	if (!lst)
		return (0);
	if ((lst->type == 'I' || lst->type == 'O') && lst->next)
	{
		if (lst->next->type == 'W')
			return (1);
		else if ((lst->next->type == 'I' || lst->next->type == 'O')
			&& lst->next->next)
		{
			if (lst->next->next->type == 'W')
				return (2);
		}
	}
	return (0);
}
