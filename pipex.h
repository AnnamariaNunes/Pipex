/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:10:43 by aangelic          #+#    #+#             */
/*   Updated: 2023/05/20 16:05:38 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(void);
void	pid2_process(char **argv, int *pdf, char **envp);
void	pid_process(char **argv, int *pdf, char **envp);
void	clean_up(char **things);
void	execute(char *cmd, char **envp);
char	*organized_path(char **envp, char *cmd);

#endif