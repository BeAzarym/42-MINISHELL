/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:38:16 by angassin          #+#    #+#             */
/*   Updated: 2023/09/22 02:41:29 by angassin         ###   ########.fr       */
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
