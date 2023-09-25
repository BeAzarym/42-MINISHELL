/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:13:59 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/25 15:22:10 by cchabeau         ###   ########.fr       */
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
	while (cpy)
	{
		if (cpy->key && cpy->value)
			printf("%s=%s\n", cpy->key, cpy->value);
		cpy = cpy->next;
	}
}

void	print_cmd(t_cmd_lst *lst)
{
	t_cmd	*cpy;

	if (!lst)
		return ;
	cpy = lst->head;
	printf("[CMD TABLE]\n");
	while (cpy)
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

void	clear_env_lst(t_env_lst *lst)
{
	t_env	*tmp;

	if (!lst->head)
		return ;
	while (lst->head)
	{
		free(lst->head->key);
		free(lst->head->value);
		tmp = lst->head->next;
		free(lst->head);
		lst->head = tmp;
	}
	free(lst);
}

void	clear_tkn_lst(t_tkn_lst *lst)
{
	t_token	*tmp;

	if (!lst)
		return ;
	if (lst->head)
	{
		while (lst->head)
		{
			free(lst->head->value);
			tmp = lst->head->next;
			free(lst->head);
			lst->head = tmp;
		}
	}
	free(lst);
}
