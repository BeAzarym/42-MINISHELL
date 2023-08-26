/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:20:02 by angassin          #+#    #+#             */
/*   Updated: 2023/08/26 14:40:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/execute.h"

void	get_input_output(t_cmd_dllst *cmd_table)
{
	t_redir_lst	*in;
	t_redir_lst	*out;

	in = NULL;
	printf("get input\n");
	if (cmd_table->head->redir_in)
		in = cmd_table->head->redir_in;
	while (in->head != NULL)
	{
		if (access(in->head->file, R_OK) != OK)
			error_exit("");
		printf("%s\n", in->head->file);
		in->head = in->head->next;
	}
	printf("%c\n", in->head->type);
	cmd_table->head->type_in = 
	// cmd_table->head->infile = in->head->file;
	if (cmd_table->head->redir_out)
		out = cmd_table->head->redir_out;
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
