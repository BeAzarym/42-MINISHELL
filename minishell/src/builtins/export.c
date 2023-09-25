/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:47:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/25 17:17:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	check_arg(char *arg)
{
	int	i;

	if (ft_isdigit(arg[0]))
		return (0);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	check_assignation(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	process_export(char *arg, t_env_lst *env)
{
	char	**tmp;

	if (!check_assignation(arg))
	{
		env = add_lst_env(arg, NULL, env);
		return (0);
	}
	else if (check_assignation(arg) == 1)
	{
		tmp = envp_split(arg);
		if (search_in_env(tmp[0], env))
			replace_value_env(tmp[0], tmp[1], env);
		else
			env = add_lst_env(tmp[0], tmp[1], env);
		ft_array_clear(tmp);
		return (0);
	}
	return (1);
}

int	export_builtins(char **arg, t_env_lst *env)
{
	int	i;
	int	status;

	if (ft_arraylen(arg) == 1)
	{
		print_env(env);
		return (0);
	}
	i = 1;
	while (arg[i])
	{
		if (!check_arg(arg[i]))
		{
			ft_putstr_fd("export: key is not valid.\n", 2);
			return (1);
		}
		else
			status = process_export(arg[i], env);
		i++;
	}
	return (status);
}
