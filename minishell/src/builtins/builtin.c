/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/09/22 01:20:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static bool	has_newline(char *arg);

/*
	 Behaves like echo in bash 3.2
	 The index starts at 1 to skip printing "echo"
*/
int	echo(char **cmd)
{
	bool	newline_char;
	size_t	i;

	i = 1;
	newline_char = has_newline(cmd[1]);
	if (!newline_char)
		i = 2;
	while (cmd[i] != NULL && has_newline(cmd[i]) == false)
		++i;
	while (cmd[i] != NULL)
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		++i;
	}
	if (newline_char)
		printf("%c", '\n');
	return (EXIT_SUCCESS);
}

static bool	has_newline(char *arg)
{
	size_t	i;

	if (arg == NULL)
		return (true);
	if (ft_strncmp(arg, "-n", 2) != OK)
		return (true);
	i = 2;
	while (arg[i] != '\0')
	{
		if (arg[i] != 'n')
			return (true);
		++i;
	}
	return (false);
}

// void exit(int);
// {
// 	// return (EXIT_SUCCESS);
// }

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

int	env_builtins(t_env_lst *env)
{
	print_env(env);
	return (0);
}

int	pwd_builtins(void)
{
	char	*res;

	res = getcwd(NULL, 0);
	if (!res)
		return (-1);
	printf("%s\n", res);
	free(res);
	return (0);
}
