/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:31:47 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 13:44:20 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	int		n;
	int		ac;
	int		pid;
	int		flag;
	int		count;
	int		pipe[2];
	int		**multipipe;
	int		here_pipe[2];
	char	**av;
	char	**env;
}	t_struct;

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);

void	ft_multipipe(t_struct *s);
void	ft_close_pipes(t_struct *s);
void	ft_do_cmd(char *av, t_struct *s);

char	*ft_gnl(void);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *h, const char *n, size_t len);

#endif
