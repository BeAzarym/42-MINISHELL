/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:11:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/08 20:26:56 by angassin         ###   ########.fr       */
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
int	cd(char **cmd, t_env_lst *env)
{
	char	*to_expand;
	char	*new_pwd;

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
	new_pwd = getcwd(NULL, 0);
	if (new_pwd == NULL)
		return (EXIT_FAILURE);
	update_pwd(new_pwd, env);
	return (EXIT_SUCCESS);
}

static int	cd_to_expanded_path(char *to_expand, t_env_lst *env)
{
	char	*expanded;
	char	*new_pwd;

	expanded = expand(to_expand, env);
	if (chdir(expanded) == -1)
	{
		printf("minishell: cd: %s: expanded not set\n", expanded);
		return (EXIT_FAILURE);
	}
	new_pwd = getcwd(NULL, 0);
	if (new_pwd == NULL)
		return (EXIT_FAILURE);
	update_pwd(new_pwd, env);
	free(expanded);
	return (EXIT_SUCCESS);
}

void	update_pwd(char *pwd, t_env_lst *env)
{
	char	*old_pwd;

	old_pwd = get_key_value("PWD", env);
	if (old_pwd == NULL)
		return ;
	update_value_env("OLDPWD", old_pwd, env);
	update_value_env("PWD", pwd, env);
}
