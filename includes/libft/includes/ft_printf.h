/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:25:34 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/09/10 13:39:20 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putnbr_base(unsigned long long nbr, char *base, int base_len, char n);

int	ft_printf_putchar_fd(char c, int fd);

int	ft_printf_putstr_fd(char *s, int fd);

int	ft_printf_putnbr_fd(int n, int fd);

int	ft_putunbr_fd(unsigned int n, int fd);

#endif