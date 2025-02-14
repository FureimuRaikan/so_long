/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:53:52 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/21 23:03:49 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *nptr);
int		ft_atoi_arg_mix(const char *nptr, int *next_nbr);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ulitoa_base(unsigned long int n, const char *base);
size_t	ft_unblen_base(unsigned long int n, const char *base);
long	ft_atol(const char *nptr);
long	ft_atol_arg_mix(const char *nptr, int *next_nbr);

#endif