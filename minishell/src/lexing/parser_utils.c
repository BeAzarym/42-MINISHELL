/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:45:51 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/09 16:05:04 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*init_cmd_struct(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = NULL;
	new->infile = NULL;
	new->outfile = NULL;
	new->type_in = -1;
	new->type_out = -1;
	new->next = NULL;
	return (new);
}

t_cmd_node	*init_cmd_node(void)
{
	t_cmd_node	*node;

	node = malloc(sizeof(t_cmd_node));
	if (!node)
		return (NULL);
	node->head = NULL;
	node->tail = NULL;
	node->size = 0;
	return (node);
}

t_cmd_node	*add_cmd_node(t_cmd_node *node, t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (!node->head)
	{
		node->head = cmd;
		node->tail = cmd;
	}
	else
	{
		node->tail->next = cmd;
		node->tail = cmd;
	}
	node->size++;
	return (node);
}
