/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/17 18:13:19 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	compute_len(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep))
			i++;
		else
			break ;
	}
	return (i);
}

char	*extract_word_sep(char *str, char *sep)
{
	char	*res;

	if (!str)
		return (NULL);
	res = ft_substr(str, 0, compute_len(str, sep));
	if (!res)
		return (NULL);
	return (res);
}
