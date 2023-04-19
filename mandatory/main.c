/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:23:45 by ecolin            #+#    #+#             */
/*   Updated: 2022/05/04 11:48:19 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	err_msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	close_canal(int write, int read)
{
	close(write);
	close(read);
}

int	main(int arc, char *arv[], char *envp[])
{
	int		can[2];
	t_proc	proc1;
	t_proc	proc2;

	if (arc != 5)
		return (err_msg(ERR_INPUT));
	if (pipe(can) == -1)
		return (err_msg(ERR_PIPE));
	proc1 = create_proc(open(arv[1], O_RDONLY), can[1], can[0]);
	proc2 = create_proc(can[0],
			open(arv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644), can[1]);
	if (proc1.infile < 0 || proc2.outfile < 0)
		return (close_canal(can[1], can[0]), err_msg(ERR_FILE));
	proc1.pid = fork();
	if (!proc1.pid)
		workfork(arv[2], proc1, envp);
	proc2.pid = fork();
	if (!proc2.pid)
		workfork(arv[3], proc2, envp);
	close_canal(can[1], can[0]);
	waitpid(proc1.pid, NULL, 0);
	waitpid(proc2.pid, NULL, 0);
	return (0);
}
