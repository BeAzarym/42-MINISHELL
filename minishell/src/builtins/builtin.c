/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/09/22 18:18:09 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	exit_builtin(char **cmd, int status)
{
	int	argc;

	printf("exit\n");
	argc = 0;
	while (cmd[argc] != NULL)
		++argc;
	// if (argc > 2 && ft_isnumber(cmd[1]))
	// {
	// 	printf("minishell: exit: too many arguments\n");
	// 	return (1);
	// }
	printf("argc : %d\n", argc);
	exit(status);
}

// unset home and cd .. /bin
// printf("cmd 1 : %s\n", home);
// cd -
int	cd(char **cmd, t_env_lst *env)
{
	char	*home;

	if (cmd[1] == NULL)
	{
		home = expand("$HOME", env, 0);
		if (chdir(home) == -1)
		{
			printf("minishell: cd: %s: HOME not set\n", home);
			return (1);
		}
	}
	else if (chdir(cmd[1]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", cmd[1]);
		return (1);
	}
	return (0);
}

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
		return (-1);
	printf("%s\n", res);
	free(res);
	return (0);
}
