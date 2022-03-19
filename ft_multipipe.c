/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multipipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:25:36 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/17 12:48:23 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipes(t_struct *s)
{
	int	i;

	i = -1;
	if (s->multipipe)
	{
		while (++i < s->ac - 5)
		{
			close(s->multipipe[i][0]);
			close(s->multipipe[i][1]);
		}
		i = -1;
		while (++i < s->ac - 5)
			free(s->multipipe[i]);
		free(s->multipipe);
	}
	close(s->pipe[0]);
	close(s->pipe[1]);
}

void	ft_create_pipes(t_struct *s)
{
	int	i;

	i = -1;
	s->multipipe = malloc(sizeof(int *) * s->ac - 5);
	if (!s->multipipe)
		exit (1);
	while (++i < s->ac - 5)
	{
		s->multipipe[i] = malloc(sizeof(int) * 2);
		if (!s->multipipe[i])
			exit (1);
		pipe(s->multipipe[i]);
	}
}

void	ft_multipipe(t_struct *s)
{
	int	i;
	int	pid;

	i = -1;
	if (s->flag)
		s->ac--;
	ft_create_pipes(s);
	while (++i < s->ac - 5)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				dup2(s->pipe[0], 0);
			else
				dup2(s->multipipe[i - 1][0], 0);
			dup2(s->multipipe[i][1], 1);
			ft_close_pipes(s);
			if (s->flag)
				ft_do_cmd(s->av[i + 4], s);
			ft_do_cmd(s->av[i + 3], s);
		}
	}
	dup2(s->multipipe[i - 1][0], 0);
}
