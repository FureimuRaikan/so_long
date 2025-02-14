/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:20:17 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 16:09:32 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sclst_max(t_sclist *sclist)
{
	t_sclist	*begin;
	int			max;

	begin = sclist;
	if (!sclist)
		return (0);
	max = sclist->value;
	while (sclist->next != begin)
	{
		sclist = sclist->next;
		if (sclist->value > max)
			max = sclist->value;
	}
	return (max);
}
