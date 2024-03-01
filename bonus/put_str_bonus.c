/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:07:58 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 17:44:08 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char    *ft_strdup(char *s1)
{
        char    *ret;

        ret = (char *)malloc(sizeof(char) * (count_len(s1) + 1));
        if (!ret)
                return (NULL);
        copy_it(ret, s1);
        return (ret);
}
static int      count_digit(int nb)
{
        int     count;

        count = 1;
        while (nb / 10)
        {
                count++;
                nb /= 10;
        }
        return (count);
}

static int      cal(int nb)
{
        int     count;

        count = 1;
        while (--nb > -1)
                count *= 10;
        return (count);
}

static void     alloc(char *ret, int count, unsigned int nb, int i)
{
        while (count--)
        {
                ret[i] = nb / cal(count) + 48;
                nb %= cal(count);
                i++;
        }
		ret[i] = '\0';
}

char    *ft_itoa(int n)
{
        unsigned int    nb;
        char                    *ret;
        int                             i;
        int                             count;
        int                             p;

        p = 1;
        nb = n;
        i = 0;
        if (n < 0)
                p++;
        if (!n)
                return (ft_strdup("0"));
        count = count_digit(n);
        ret = (char *)malloc(sizeof(char)* (count + p));
        if (!ret)
                return (NULL);
        alloc(ret, count, nb, i);
        return (ret);
}
char *put_moves(int moves)
{
	char *s1 = "MOVES ";
	char *s2 = ft_itoa(moves);
	char *ret = malloc(count_len(s1)+count_len(s2)+1);
	copy_it(ret,s1);
	copy_it(ret+count_len(s1),s2);
	free(s2);
	return(ret);
}
