/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:15:44 by mel-ward          #+#    #+#             */
/*   Updated: 2023/12/06 18:31:50 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_str(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	i = 0;
	if (!s2 && !s1)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len = count_len(s1) + count_len(s2) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (free(s1), free(s2), NULL);
	copy_it(ret, s1);
	copy_it(ret + count_len(s1), s2);
	free(s1);
	free(s2);
	return (ret);
}

char	*get_full(char *str)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (free(str), NULL);
	while (len--)
		*(ret + i++) = *(str++);
	ret[i] = '\0';
	if (!*ret)
		return (free(ret), free(str), NULL);
	return (ret);
}

char	*get_rest(char *str)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * (count_len(str + i) + 1));
	if (!ret)
		return (free(str), NULL);
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	free(str);
	if (!*ret)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*rest;
	char		*temp;
	ssize_t		ln;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	ln = 1;
	while (ln && check_nl(rest))
	{
		temp = (char *)malloc(sizeof(char) * ((size_t)(BUFFER_SIZE) + 1));
		if (!temp)
			return (free(rest), rest = NULL, NULL);
		ln = read(fd, temp, BUFFER_SIZE);
		if (ln == -1)
			return (free(rest), free(temp), rest = NULL, NULL);
		temp[ln] = '\0';
		rest = add_str(rest, temp);
		if (ln < BUFFER_SIZE)
			break ;
	}
	ret = get_full(rest);
	if (!ret)
		return (rest = NULL, NULL);
	return (rest = get_rest(rest), ret);
}
