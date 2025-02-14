/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:57:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 16:09:32 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sclst_clean(t_sclist **sclst)
{
	t_sclist	*tmp;
	t_sclist	*begin;

	begin = *sclst;
	while ((*sclst)->next != begin)
	{
		tmp = *sclst;
		*sclst = (*sclst)->next;
		free(tmp);
	}
	free(*sclst);
	free(sclst);
}
