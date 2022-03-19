/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:20:13 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/16 20:08:06 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*n)
		return ((char *)(h + i));
	while (i < len && h[i])
	{
		j = 0;
		if (h[i] == n[j])
		{
			while (h[i + j] == n[j] && (i + j < len) && n[j])
				j++;
			if (!n[j])
				return ((char *)(h + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (ss1 == NULL || ss2 == NULL)
		return (1);
	if (*ss1 == 0 || *ss2 == 0)
		return (1);
	while (*ss1 != '\n' && *ss2)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}

char	*ft_gnl(void)
{
	char	*res;
	char	*buf;

	res = NULL;
	buf = malloc(2);
	while (read(0, buf, 1) == 1 && buf[0] != '\0')
	{
		buf[1] = '\0';
		res = ft_strjoin(res, buf);
		if (buf[0] == '\n')
			break ;
	}
	free(buf);
	return (res);
}
