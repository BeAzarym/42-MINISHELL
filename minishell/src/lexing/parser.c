/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:41:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/29 13:33:00 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_dllst	*parsing(t_tkn_lst *lst, t_cmd_dllst *cmd_table)
{
	t_token	*cpy;
	t_cmd		*node;

	cpy = lst->head;
	while (cpy)
	{
		node = init_cmd_struct();
		cpy = exctrat_data(cpy, node);
		cmd_table = add_cmd_dllst(cmd_table, node);
		if (cpy)
			cpy = cpy->next;
	}
	clear_tkn_lst(lst->head);
	return (cmd_table);
}

t_token *exctrat_data(t_token *lst, t_cmd *node)
{
	if (!lst || !node)
		return (NULL);
	while (lst && lst->type != 'P')
	{
		while (lst && (lst->type == 'I' || lst->type == 'O'))
			lst = handle_redirect(lst, node);
		if (!lst)
			return (NULL);
		while (lst && lst->type == 'W')
		{
			node->cmd = array_add_back(node->cmd, lst->value);
			lst = lst->next;
		}
		if (lst && lst->type == 'W')
			lst = lst->next;
		if (lst && lst->type == 'P')
			return (lst);
	}
	return (lst);
}
