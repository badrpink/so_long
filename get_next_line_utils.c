/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:05:31 by mel-ward          #+#    #+#             */
/*   Updated: 2023/12/04 10:16:11 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	count_len(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_nl(char *str)
{
	if (!str)
		return (1);
	while (*str)
		if (*(str++) == '\n')
			return (0);
	return (1);
}

void	copy_it(char *dest, char *src)
{
	if (!src)
		return ;
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}
