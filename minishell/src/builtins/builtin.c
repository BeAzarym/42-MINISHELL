/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:32 by angassin          #+#    #+#             */
/*   Updated: 2023/08/25 15:57:10 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

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
