/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:45:51 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/29 16:13:02 by cchabeau         ###   ########.fr       */
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

t_cmd_dllst	*init_cmd_dllst(void)
{
	t_cmd_dllst	*dllst;

	dllst = malloc(sizeof(t_cmd_dllst));
	if (!dllst)
		return (NULL);
	dllst->head = NULL;
	dllst->tail = NULL;
	dllst->size = 0;
	return (dllst);
}

t_cmd_dllst	*add_cmd_dllst(t_cmd_dllst *dllst, t_cmd *cmd)
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

void clear_cmd_ddlst(t_cmd_dllst *lst)
{
	if (!lst)
		return ;
	while (lst->head)
	{
		free(lst->head->infile);
		free(lst->head->outfile);
		clear_redir_lst(lst->head->redir_in);
		clear_redir_lst(lst->head->redir_out);
		ft_array_clear(lst->head->cmd);
		lst->head = lst->head->next;
	}
	free(lst->head);
	free(lst);
}