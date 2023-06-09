/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:10:40 by aangelic          #+#    #+#             */
/*   Updated: 2023/05/23 13:31:43 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_process(char **argv, int *pfd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error();
	close(pfd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	close(infile);
	execute(argv[2], envp);
}

void	pid2_process(char **argv, int *pfd, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error();
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pfd[0]);
	close(outfile);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		status;
	pid_t	pid;
	pid_t	pid2;

	if (argc != 5)
	{
		write(1, "You need to have 5 arguments, bro\n", 34);
		exit(EXIT_FAILURE);
	}
	if (pipe(pfd) < 0)
		error();
	pid = fork();
	if (pid < 0)
		error();
	if (pid == 0)
		pid_process(argv, pfd, envp);
	pid2 = fork();
	if (pid2 < 0)
		error();
	if (pid2 == 0)
		pid2_process(argv, pfd, envp);
	waitpid(-1, &status, 0);
	return (0);
}
