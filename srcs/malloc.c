/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:18:41 by alngo             #+#    #+#             */
/*   Updated: 2020/01/28 14:30:57 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_arena		g_arena = {NULL, NULL, NULL};

void		*malloc(size_t size)
{
	void	*block;

	if (size <= 0 || size > (~(size_t)0 >> 3))
		return (NULL);
	if (size <= TINY)
		block = get_block(&g_arena.tiny, size);
	else if (size <= SMALL)
		block = get_block(&g_arena.small, size);
	else
		return (get_block(&g_arena.large, size));
	if (block)
		return (get_payload(block));
	return (NULL);
}