/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:27:11 by angassin          #+#    #+#             */
/*   Updated: 2023/10/06 18:06:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static bool	ft_isnumber(char *cmd);
static int	exit_atoi(char *str);

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
	else if ((cmd[1] != NULL && !ft_isnumber(cmd[1]))
		|| (cmd[1] != NULL && exit_atoi(cmd[1]) >= 255))
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
		exit (255);
	}
	else if (cmd[1] != NULL && ft_isnumber(cmd[1]))
		exit(exit_atoi(cmd[1]));
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

static int	exit_atoi(char *str)
{
	int		i;
	int		sign;
	long	nb;
	long	tmp;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = nb;
		nb = nb * 10 + str[i++] - '0';
		if (nb - (sign == -1) < tmp)
			return (256);
	}
	return (nb * sign);
}
