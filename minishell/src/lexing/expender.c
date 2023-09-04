/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/04 13:05:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int need_substitute(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) == 1 || str[i + 1] == '_'))
			return (1);
		i++;
	}
	return (0);
}
