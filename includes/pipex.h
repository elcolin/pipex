/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:27:35 by ecolin            #+#    #+#             */
/*   Updated: 2022/05/09 16:24:59 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_FILE "File error\n"
# define ERR_INPUT "Invalid number of arguments\n"
# define ERR_CMD "Command not found\n"
# define ERR_PIPE "Pipe error\n"
# define ERR_PATH "Path error\n"
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <sys/uio.h>

typedef struct s_proc
{
	pid_t	pid;
	int		infile;
	int		outfile;
	int		close_can;
}t_proc;
char	**find_cmd(char *arv, char **paths);
int		pipex(int f1, int f2, char **arv, char **env);
char	**freetab(char **tab);
t_proc	create_proc(int infile, int outfile, int close_can);
void	workfork(char *arv, t_proc proc, char *envp[]);
char	**find_paths(char **env);
int		err_msg(char *err);
#endif
