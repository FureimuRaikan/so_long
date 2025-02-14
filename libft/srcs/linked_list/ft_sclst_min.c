/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:20:24 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 16:09:32 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sclst_min(t_sclist *sclist)
{
	t_sclist	*begin;
	int			min;

	begin = sclist;
	if (!sclist)
		return (0);
	min = sclist->value;
	while (sclist->next != begin)
	{
		sclist = sclist->next;
		if (sclist->value < min)
			min = sclist->value;
	}
	return (min);
}
