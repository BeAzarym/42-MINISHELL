/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/10/04 16:02:07 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/execute.h"

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
	char	*to_expand;

	if (cmd[1] == NULL)
	{
		to_expand = ft_strdup("$HOME");
		return (cd_to_expanded_path(to_expand, env));
	}
	else if (ft_strcmp(cmd[1], "-") == OK)
	{
		to_expand = ft_strdup("$OLDPWD");
		pwd_builtin();
		return (cd_to_expanded_path(to_expand, env));
	}
	else if (chdir(cmd[1]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", cmd[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	cd_to_expanded_path(char *to_expand, t_env_lst *env)
{
	char	*expanded;

	expanded = expand(to_expand, env);
	if (chdir(expanded) == -1)
	{
		printf("minishell: cd: %s: expanded not set\n", expanded);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
	{
		printf("Error getcwd can't find current location.");
		return (1);
	}
	printf("%s\n", res);
	free(res);
	return (0);
}
