/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:13:59 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/08/16 16:19:36 by angassin         ###   ########.fr       */
=======
/*   Updated: 2023/07/10 18:24:42 by cchabeau         ###   ########.fr       */
>>>>>>> env update
=======
/*   Updated: 2023/08/07 11:25:14 by cchabeau         ###   ########.fr       */
>>>>>>> cleaning main
=======
/*   Updated: 2023/08/09 16:04:15 by cchabeau         ###   ########.fr       */
>>>>>>> phoenix
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

<<<<<<< HEAD
<<<<<<< HEAD
void	print_token(t_token *lst)
=======
void print_token(t_token *lst)
>>>>>>> env update
=======
void	print_token(t_token *lst)
>>>>>>> phoenix
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

<<<<<<< HEAD
<<<<<<< HEAD
void	print_env(t_env_lst *lst)
{
	t_env_lst	*cpy;

	if (!lst)
		return ;
=======
void print_env(t_env_lst *lst)
=======
void	print_env(t_env_lst *lst)
>>>>>>> phoenix
{
	t_env_lst	*cpy;

	if (!lst)
		return ;
<<<<<<< HEAD
	t_env_lst *cpy;
>>>>>>> env update
=======
>>>>>>> phoenix
	cpy = lst;
	printf("[ENV]\n");
	while (cpy->head)
	{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> phoenix
		printf(">> [KEY] : %s	>> [VALUE] : %s\n", cpy->head->key,
					cpy->head->value);
		cpy->head = cpy->head->next;
	}
}

void	print_cmd(t_cmd_node *node)
{
	t_cmd_node *cpy;
	
	if (!node)
		return ;
	cpy = node;
	printf("[CMD TABLE]\n");
	while(cpy->head)
	{
		printf("---\n");
		printf(">> INFILE %s\n", cpy->head->infile);
		ft_array_print(cpy->head->cmd);
		printf("---\n");
<<<<<<< HEAD
=======
		printf(">> [KEY] : %s	>> [VALUE] : %s\n", cpy->head->key, cpy->head->value);
>>>>>>> env update
=======
>>>>>>> phoenix
		cpy->head = cpy->head->next;
	}
}

void	clear_env_lst(t_env *lst)
{
	if (!lst)
<<<<<<< HEAD
<<<<<<< HEAD
		return ;
=======
		return;
>>>>>>> env update
=======
		return ;
>>>>>>> phoenix
	while (lst)
	{
		free(lst->key);
		free(lst->value);
		lst = lst->next;
	}
	free(lst);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> cleaning main
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
<<<<<<< HEAD
<<<<<<< HEAD
}


=======
}
>>>>>>> env update
=======
}
>>>>>>> cleaning main
=======
}


>>>>>>> phoenix
