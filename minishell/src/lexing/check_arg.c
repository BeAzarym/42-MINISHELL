/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:31:16 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/05 15:52:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_redir(t_token *lst)
{
	if (lst->next && lst->next->type == 'W')
		lst = lst->next;
	else if (lst->next && lst->next->next && (lst->next->type == 'I'
			|| lst->next->type == 'O'))
	{
		if (lst->next->next && lst->next->next->type == 'W')
			lst = lst->next->next;
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	is_valid_cmd_line(t_tkn_lst *lst)
{
	t_token		*cpy;
	int			status;

	status = 1;
	cpy = lst->head;
	if (lst->head->type == 'P')
		return (0);
	while (cpy)
	{
		if (cpy->type == 'P' && !cpy->next)
			return (0);
		if (cpy->next && cpy->type == 'P' && (cpy->next->type == 'P'
				|| cpy->next->type != 'W'))
			return (status = 0);
		if (cpy->type == 'I' || cpy->type == 'O')
		{
			status = is_valid_redir(cpy);
		}
		cpy = cpy->next;
	}
	return (status);
}
