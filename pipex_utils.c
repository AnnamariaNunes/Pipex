/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:10:35 by aangelic          #+#    #+#             */
/*   Updated: 2023/05/22 16:00:54 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("you are doing something wrong");
	exit(EXIT_FAILURE);
}

void	clean_up(char **things)
{
	int	i;

	i = 0;
	while (things[i])
		free(things[i++]);
	free(things);
}

void	execute(char *cmd, char **envp)
{
	char	**exec_cmd;
	char	*path;
	int		i;

	exec_cmd = ft_split(cmd, ' ');
	cmd = *exec_cmd;
	path = organized_path(envp, cmd);
	if (!path)
	{
		i = 0;
		while (exec_cmd[i++])
			free(exec_cmd[i]);
		free(exec_cmd);
		error();
	}
	if (execve(path, exec_cmd, envp) == -1)
		error();
}

char	*organized_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	*temp;
	char	**mypaths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	mypaths = ft_split(path, ':');
	free(path);
	i = 0;
	while (mypaths[i])
	{
		temp = ft_strjoin(mypaths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, F_OK) != -1)
			return (path);
		free(temp);
		free(path);
		i++;
	}
	clean_up(mypaths);
	return (cmd);
}
