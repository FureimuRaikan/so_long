/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:29:28 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/10 14:52:11 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_printf(const char *str, ...);
void	ft_print_array_str(char **array);
int		ft_putchar_len(int c);
int		ft_putnbr_hex_len(unsigned int n);
int		ft_putnbr_hex_len_up(unsigned int n);
int		ft_putnbr_len(int n);
int		ft_putunbr_len(unsigned int n);
int		ft_putptr_len(void *ptr);
int		ft_putstr_len(char *str);

#endif