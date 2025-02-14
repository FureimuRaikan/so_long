/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:10:10 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 12:17:38 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_error(char *Error_message, char **map)
{
	ft_putendl_fd(Error_message, 2);
	ft_print_rules(2);
	if (map)
		ft_free_split(map);
	exit(1);
}
