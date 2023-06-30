/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/30 15:51:56 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// t_token *create_token(char *word, char type, t_token *lst)
// {
// 	if (!word)
// 		return (NULL);

// 	t_token *tmp;

// 	tmp = malloc(sizeof(t_token));
// 	if (!tmp)
// 		return (NULL);
// 	tmp->next = NULL;
// 	tmp->value = ft_strdup(word);
// 	if (!tmp->value)
// 		return (NULL);
// 	tmp->type = type;
// 	add_back(lst, tmp);
// 	return (lst);
// }

// void tokenize(char **arr)
// {
	
// }