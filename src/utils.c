/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:13:59 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/07 11:25:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void print_token(t_token *lst)
{
	if (!lst)
		return ;
	printf("[TOKEN]\n");
	while (lst)
	{
		printf(">> TYPE : %c	>> VALUE : %s\n", lst->type, lst->value);
		lst = lst->next;
	}
}

void print_env(t_env_lst *lst)
{
	if (!lst)
		return ;
	t_env_lst *cpy;
	cpy = lst;
	printf("[ENV]\n");
	while (cpy->head)
	{
		printf(">> [KEY] : %s	>> [VALUE] : %s\n", cpy->head->key, cpy->head->value);
		cpy->head = cpy->head->next;
	}
}

void	clear_env_lst(t_env *lst)
{
	if (!lst)
		return;
	while (lst)
	{
		free(lst->key);
		free(lst->value);
		lst = lst->next;
	}
	free(lst);
}

void	clear_tkn_lst(t_token *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		free(lst->value);
		lst = lst->next;
	}
	free(lst);
}