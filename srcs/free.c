/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:20:19 by alngo             #+#    #+#             */
/*   Updated: 2020/02/19 17:19:57 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		free(void *ptr)
{
	void	*block;
	void	*heap;
	uint8_t	is_large;

	pthread_mutex_lock(&g_lock);
	if (DCALL)
		debug_call("free", (size_t)ptr, 16);
	heap = NULL;
	if (!ptr || !(block = get_block(ptr, &heap)))
		return ;
	is_large = meta(block)->flags == (INUSE | MMAPD);
	set_meta(meta(block), meta(block)->size,
			meta(block)->flags ^ INUSE, meta(block)->next);
	if (is_empty_heap(is_large ? heap : payload(heap)))
		delete_heap(heap);
	if (DEBUG)
		debug_output("free");
	pthread_mutex_unlock(&g_lock);
}
