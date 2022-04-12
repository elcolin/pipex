/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:24:34 by ecolin            #+#    #+#             */
/*   Updated: 2022/04/12 17:28:48 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdio.h>
#include <string.h> //A SUPPRIMER ET METTRE STRDUP
int main(int argc, char *argv[], char *env[])
{
	char	**paths;
	char	*r_path;
	char	**cmd;
	char	*p_cmd;
	int		a;
	int		i;

	(void) argc;
	(void) env;
	i = 0;
	a = 1;
	r_path = NULL;
	cmd = ft_split(argv[2], ' ');
	p_cmd = ft_strjoin("/", cmd[0]);
	paths = ft_split(chemin, ':');
	r_path = ft_strjoin(paths[i], p_cmd);
	while(a && paths[i++])
	{
		r_path = ft_strjoin(paths[i], p_cmd);
		a = access(r_path, X_OK);
	}
	execve(r_path, cmd, env);
}
