/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:27:11 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 16:51:00 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static bool	ft_isnumber(char *cmd);

/*
	Exits the shell.
	Exits with the status specified by the user.
	Exits with the status of the last command if no status is specified.
*/
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
		g_status = 1;
		return (g_status);
	}
	else if (cmd[1] != NULL && !ft_isnumber(cmd[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
		exit (255);
	}
	else if (cmd[1] != NULL && ft_isnumber(cmd[1]))
		exit(ft_atoi(cmd[1]));
	exit(g_status);
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
