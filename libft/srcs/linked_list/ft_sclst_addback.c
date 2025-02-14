/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:42:36 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/05 16:09:20 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sclst_addback(t_sclist **stack, t_sclist *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		if (ft_sclst_last(*stack))
		{
			ft_sclst_last(*stack)->next = new;
			if (new)
				new->next = *stack;
		}
	}
}
