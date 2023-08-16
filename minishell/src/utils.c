/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:13:59 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/16 16:54:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_token(t_token *lst)
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

void	print_env(t_env_lst *lst)
{
	t_env_lst	*cpy;

	if (!lst)
		return ;
	cpy = lst;
	printf("[ENV]\n");
	while (cpy->head)
	{
		printf(">> [KEY] : %s	>> [VALUE] : %s\n", cpy->head->key,
					cpy->head->value);
		cpy->head = cpy->head->next;
	}
}

void	print_cmd(t_cmd_dllst *dllst)
{
	t_cmd_dllst *cpy;
	
	if (!dllst)
		return ;
	cpy = dllst;
	printf("[CMD TABLE]\n");
	while(cpy->head)
	{
		printf("---\n");
		printf(">> INFILE %s\n", cpy->head->infile);
		ft_array_print(cpy->head->cmd);
		printf("---\n");
		cpy->head = cpy->head->next;
	}
}

void	clear_env_lst(t_env *lst)
{
	if (!lst)
		return ;
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


