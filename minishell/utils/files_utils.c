/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:20:02 by angassin          #+#    #+#             */
/*   Updated: 2023/09/05 15:16:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/execute.h"

/*
	Check if the infile is the stdin
	Otherwise, loops over all the infiles to check that they exist,
	if all valids, save the last one in memory

*/
void	get_input_output(t_cmd_lst *cmd_table)
{
	t_redir_lst	*in;
	t_redir_lst	*out;
	// int			fd_pipes[2][2];

	// fd_pipes[0][0] = -1;
	// fd_pipes[0][1] = -1;
	// fd_pipes[1][0] = -1;
	// fd_pipes[1][1] = -1;
	printf("get input\n");
	in = cmd_table->head->redir_in;
	if (in->head == NULL)
	{
		printf("redir_in == STDIN\n");
		cmd_table->head->fdin = STDIN_FILENO;
	}
	else if (in->head->type == HEREDOC)
	{
		cmd_table->head->type_in = in->head->type;
		cmd_table->head->fdin = STDIN_FILENO;
	}
	else
	{
		while (in->head != NULL)
		{
			if (access(in->head->file, R_OK) != OK)
				error_exit(in->head->file);
			in->head = in->head->next;
		}
		cmd_table->head->type_in = in->tail->type;
		printf("type of in : %c\n", cmd_table->head->type_in);
		cmd_table->head->infile = in->tail->file;
		printf("infile in get_input : %s\n", cmd_table->head->infile);
	}
	if (cmd_table->head->redir_out->head == NULL)
		cmd_table->head->fdout = STDOUT_FILENO;
	else
	{
		out = cmd_table->head->redir_out;
		while (out->head != NULL)
		{
			if (out->head->type == TRUNCATE)
				cmd_table->head->fdout = outfile_truncate_open(out->head->file);
			else if (out->head->type == APPEND)
				cmd_table->head->fdout = outfile_append_open(out->head->file);
			out->head = out->head->next;
		}
	}
	if (cmd_table->head->type_in == INFILE)
		cmd_table->head->fdin = infile_open(cmd_table->head->infile);
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

int	outfile_truncate_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("outfile_truncate fd : %i\n", fd);
	if (fd == -1)
		error_exit(file);
	return (fd);
}

int	outfile_append_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		error_exit(file);
	return (fd);
}
