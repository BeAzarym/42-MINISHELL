/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 15:56:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/execute.h"

int	env_builtin(t_env_lst *env)
{
	print_env(env);
	return (0);
}

int	pwd_builtin(void)
{
	char	*res;

	res = getcwd(NULL, 0);
	if (!res)
	{
		printf("Error getcwd can't find current location.");
		return (1);
	}
	printf("%s\n", res);
	free(res);
	return (0);
}
