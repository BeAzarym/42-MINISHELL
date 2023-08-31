/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:20:02 by angassin          #+#    #+#             */
/*   Updated: 2023/08/31 17:20:41 by angassin         ###   ########.fr       */
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
	// t_redir_lst	*out;

	printf("get input\n");
	if (cmd_table->head->redir_in->head == NULL)
	{
		printf("redir_in == NULL\n");
		cmd_table->head->type_in = STDIN_OUT;
	}
	else
	{
		in = cmd_table->head->redir_in;
		while (in->head != NULL)
		{
			if (access(in->head->file, R_OK) != OK)
				error_exit("");
			in->head = in->head->next;
		}
		cmd_table->head->type_in = in->tail->type;
		printf("type of in : %c\n", cmd_table->head->type_in);
		cmd_table->head->infile = in->tail->file;
		printf("infile in get_input : %s\n", cmd_table->head->infile);
	}
	if (cmd_table->head->redir_out->head == NULL)
		cmd_table->head->type_out = STDIN_OUT;
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
