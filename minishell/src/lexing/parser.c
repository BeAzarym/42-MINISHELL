/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:41:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:08:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// t_cmd_node	*parsing(t_tkn_lst *lst)
// {
// 	t_cmd_node	*node;
// 	t_tkn_lst	*cpy;
// 	t_cmd		*cmd;

// 	cpy = lst;
// 	node = init_cmd_node();
// 	cmd = init_cmd_struct();
// 	while (cpy->head)
// 	{
// 		if (cpy->head->type == 'I')
// 		{
// 			cmd->infile = ft_strdup(cpy->head->next->value);
// 			cpy->head = cpy->head->next->next;
// 		}
// 		while (cpy->head && cpy->head->type != 'P')
// 		{
// 			cmd->cmd = array_add_back(cmd->cmd, cpy->head->value);
// 			cpy->head = cpy->head->next;
// 		}
// 		add_cmd_node(node, cmd);
// 		break;
// 		if (cpy->head)
// 			cpy->head = cpy->head->next;
// 	}
// 	return (node);
// }

// char **cmd_table_split(t_tkn_lst *lst)
// {

// }
