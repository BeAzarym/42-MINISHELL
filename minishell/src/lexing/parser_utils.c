/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:45:51 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/30 13:44:36 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	new->redir_in = init_redir_lst();
	new->redir_out = init_redir_lst();
	if (!new->redir_in || !new->redir_out)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_cmd_lst	*init_cmd_lst(void)
{
	t_cmd_lst	*dllst;

	dllst = malloc(sizeof(t_cmd_lst));
	if (!dllst)
		return (NULL);
	dllst->head = NULL;
	dllst->tail = NULL;
	dllst->size = 0;
	return (dllst);
}

t_cmd_lst	*add_cmd_dllst(t_cmd_lst *dllst, t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (!dllst->head)
	{
		dllst->head = cmd;
		dllst->tail = cmd;
	}
	else
	{
		dllst->tail->next = cmd;
		dllst->tail = cmd;
	}
	dllst->size++;
	return (dllst);
}
