/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:14:33 by ecolin            #+#    #+#             */
/*   Updated: 2022/05/09 16:18:05 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	workfork(char *arv, t_proc proc, char *envp[])
{
	char	**cmd;
	char	**paths;

	paths = find_paths(envp);
	cmd = find_cmd(arv, paths);
	if (!cmd && !paths)
	{
		err_msg(ERR_PATH);
		exit(1);
	}
	freetab(paths);
	if (!cmd)
	{
		err_msg(ERR_CMD);
		exit(1);
	}
	close(proc.close_can);
	dup2(proc.infile, STDIN_FILENO);
	dup2(proc.outfile, STDOUT_FILENO);
	execve(cmd[0], cmd, envp);
}

t_proc	create_proc(int infile, int outfile, int close_can)
{
	t_proc	proc;

	proc.infile = infile;
	proc.outfile = outfile;
	proc.close_can = close_can;
	return (proc);
}

char	**find_paths(char *envp[])
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (!tmp && envp[i])
		tmp = ft_strnstr(envp[i++], "PATH=", 5);
	if (!tmp)
		return (0);
	return (ft_split(&tmp[5], ':'));
}

char	**find_cmd(char *arv, char **paths)
{
	char	**cmd;
	char	*tmp;
	int		a;

	a = -1;
	cmd = ft_split(arv, ' ');
	if (!paths || !cmd || ft_strchr(cmd[0], '/'))
	{
		if (!access(cmd[0], X_OK))
			return (cmd);
		return (freetab(cmd));
	}
	tmp = ft_strjoin("/", cmd[0]);
	while (*paths && a)
	{
		free(cmd[0]);
		cmd[0] = ft_strjoin(*(paths++), tmp);
		a = access(cmd[0], X_OK);
	}
	if (tmp)
		free(tmp);
	if (!a)
		return (cmd);
	cmd = freetab(cmd);
	return (0);
}

char	**freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}
