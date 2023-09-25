/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/09/24 17:18:13 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static int	cd_to_expanded_path(char *to_expand, t_env_lst *env);

/*
		The following operands shall be supported:

       directory An absolute or relative pathname of the directory that
                 shall become the new working directory. The
                 interpretation of a relative pathname by cd depends on
                 the CDPATH and PWD environment variables. 
					If directory is an empty string, the results
                 are unspecified.

       -         When a <hyphen-minus> is used as the operand, this
                 shall be equivalent to the command:

                     cd "$OLDPWD" && pwd

                 which changes to the previous working directory and
                 then writes its name.
*/
// unset home and cd .. /bin
// printf("cmd 1 : %s\n", expanded);
// cd -
int	cd(char **cmd, t_env_lst *env)
{
	if (cmd[1] == NULL)
		return (cd_to_expanded_path("$HOME", env));
	else if (strcmp(cmd[1], "-") == OK)
	{
		pwd_builtin();
		return (cd_to_expanded_path("$OLDPWD", env));
	}
	else if (chdir(cmd[1]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", cmd[1]);
		return (1);
	}
	return (0);
}

static int	cd_to_expanded_path(char *to_expand, t_env_lst *env)
{
	char	*expanded;

	expanded = expand(to_expand, env, 0);
	if (chdir(expanded) == -1)
	{
		printf("minishell: cd: %s: expanded not set\n", expanded);
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
