/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:26:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 16:09:32 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sclst_size(t_sclist *sclist)
{
	t_sclist	*begin;
	int			count;

	begin = sclist;
	if (!sclist)
		return (0);
	count = 1;
	while (sclist->next != begin)
	{
		sclist = sclist->next;
		count++;
	}
	return (count);
}
