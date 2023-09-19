/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/09/19 16:31:13 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

//echo -nnnnnnnnn -n -nnn -nnnn yann
int	echo(char *cmd)
{
	bool	newline_char;

	newline_char = true;
	if (ft_strncmp(cmd, "-n ", 3) == OK)
	{
		newline_char = false;
		cmd += 3; 
	}
	printf("%s", cmd);
	if (newline_char == true)
		printf("%c", '\n');
	return (EXIT_SUCCESS);
}

// void exit(int);
// {
// 	// return (EXIT_SUCCESS);
// }

int	cd(char *cmd)
{
	if (chdir(cmd) == -1)
	{
		printf("wrong path\n");
		return (1);
	}
	return (0);
}

int env_builtins(t_env_lst *env)
{
	print_env(env);
	return (0);
}

int pwd_builtins()
{
	char *res;

	res = getcwd(NULL, 0);
	if (!res)
		return (-1);
	printf("%s\n", res);
	free(res);
	return (0);
}
