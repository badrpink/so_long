/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:34:58 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 09:07:31 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
