/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:13:59 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/24 19:18:24 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void print_chained(t_token *lst)
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