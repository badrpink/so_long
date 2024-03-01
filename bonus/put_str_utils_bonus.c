/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:07:58 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 17:26:09 by mel-ward         ###   ########.fr       */
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
int main()
{
	
}