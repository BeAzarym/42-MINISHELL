/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:20:02 by angassin          #+#    #+#             */
/*   Updated: 2023/10/04 15:37:47 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execute.h"
#include "../includes/minishell.h"

bool	can_access_infiles(t_cmd *cmd_table)
{
	t_redir_node	*in;

	in = cmd_table->redir_in->head;
	while (in != NULL)
	{
		if (access(in->file, R_OK) != OK)
		{
			perror(in->file);
			return (false);
		}
		in = in->next;
	}
	return (true);
}

int	infile_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(file);
	return (fd);
}

//printf("outfile_truncate fd : %i\n", fd);
int	outfile_truncate_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

int	outfile_append_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}
