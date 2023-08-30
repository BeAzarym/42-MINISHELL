/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:13:59 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/30 13:44:36 by angassin         ###   ########.fr       */
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
	t_env	*cpy;

	if (!lst)
		return ;
	cpy = lst->head;
	printf("[ENV]\n");
	while (cpy)
	{
		printf(">> [KEY] : %s	>> [VALUE] : %s\n", cpy->key, cpy->value);
		cpy = cpy->next;
	}
}

void	print_cmd(t_cmd_lst *dllst)
{
	t_cmd *cpy;
	
	if (!dllst)
		return ;
	cpy = dllst->head;
	printf("[CMD TABLE]\n");
	while(cpy)
	{
		printf("--------------------------------------\n");
		printf("--------------[REDIR IN]--------------\n");
		print_redir(cpy->redir_in);
		printf("--------------[REDIR OUT]-------------\n");
		print_redir(cpy->redir_out);
		printf("--------------[CMD  TABLE]------------\n");
		ft_array_print(cpy->cmd);
		printf("--------------------------------------\n\n");
		cpy = cpy->next;
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
