/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:27:11 by angassin          #+#    #+#             */
/*   Updated: 2023/10/03 16:24:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static bool	ft_isnumber(char *cmd);

int	exit_builtin(char **cmd)
{
	int	argc;

	printf("exit\n");
	argc = 0;
	while (cmd[argc] != NULL)
		++argc;
	if (argc > 2 && ft_isnumber(cmd[1]))
	{
		printf("minishell: exit: too many arguments\n");
		exit (1);
	}
	else if (cmd[1] != NULL && !ft_isnumber(cmd[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
		exit (255);
	}
	exit(g_stat.status);
}

static bool	ft_isnumber(char *cmd)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	while (cmd[i] == '-' || cmd[i] == '+')
	{
		++sign;
		++i;
	}
	while (cmd[i])
	{
		if (cmd[i] < '0' || cmd[i] > '9')
			return (false);
		++i;
	}
	return (sign <= 1);
}
