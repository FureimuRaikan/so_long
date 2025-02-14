/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:56 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/10 14:51:46 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_str(char **array)
{
	int	i;

	if (!array || !*array)
		return ;
	i = -1;
	while (array[++i])
		ft_putendl_fd(array[i], 1);
}
