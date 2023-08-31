/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:45:51 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/31 17:09:22 by angassin         ###   ########.fr       */
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
	t_cmd_lst	*lst;

	lst = malloc(sizeof(t_cmd_lst));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return (lst);
}

t_cmd_lst	*add_cmd_lst(t_cmd_lst *lst, t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (!lst->head)
	{
		lst->head = cmd;
		lst->tail = cmd;
	}
	else
	{
		lst->tail->next = cmd;
		lst->tail = cmd;
	}
	lst->size++;
	return (lst);
}

void clear_cmd_lst(t_cmd_lst *lst)
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