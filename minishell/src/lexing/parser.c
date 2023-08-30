/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:41:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/30 13:44:36 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_lst	*parsing(t_tkn_lst *lst, t_cmd_lst *cmd_table)
{
	t_tkn_lst	*cpy;
	t_cmd		*node;

	cpy = lst;
	while (cpy->head)
	{
		node = init_cmd_struct();
		extract_data(lst, node);
		cmd_table = add_cmd_dllst(cmd_table, node);
		if (cpy->head)
			cpy->head = cpy->head->next;
	}
	return (cmd_table);
}

void	extract_data(t_tkn_lst *lst, t_cmd *node)
{
	if (!lst || !node)
		return ;
	while (lst->head && lst->head->type != 'P')
	{
		while (lst->head && (lst->head->type == 'I' || lst->head->type == 'O'))
			lst = handle_redirect(lst, node);
		if (!lst->head)
			return ;
		while (lst->head && lst->head->type == 'W')
		{
			node->cmd = array_add_back(node->cmd, lst->head->value);
			lst->head = lst->head->next;
		}
		if (lst->head && lst->head->type == 'W')
			lst->head = lst->head->next;
		if (lst->head && lst->head->type == 'P')
			return ;
	}
}
