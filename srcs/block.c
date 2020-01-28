/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:03:38 by alngo             #+#    #+#             */
/*   Updated: 2020/01/28 15:11:21 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*first_fit(void *heap, size_t size)
{
	void	*block;
	void	*next;
	t_meta	*block_meta;
	size_t	aligned_size;

	block = get_payload(heap);
	next = NULL;
	while (block)
	{
		block_meta = get_meta(block);
		if (!(block_meta->flags & INUSE))
		{
			if (block_meta->size == 0 || block_meta->size >= size)
			{
				aligned_size = size_alignment(size, sizeof(void *));
				next = block + sizeof(t_meta) + aligned_size;
				if (next > (heap + get_meta(heap)->size))
					next = NULL;
				set_meta(block, size, INUSE, next);
				break ;
			}
		}
		block = block_meta->next;
	}
	return (block);
}

void		*large_fit(void *heap, size_t size)
{
	t_meta	*heap_meta;

	heap_meta = get_meta(heap);
	if (heap_meta->flags & INUSE)
		return (NULL);
	set_meta(heap, size, INUSE | MMAPD, NULL);
	return (get_payload(heap));
}

void		*get_block(void **heap, size_t size)
{
	void	*block;

	if (!*heap && !(*heap = init_heap(size)))
		return (NULL);
	if (size > SMALL)
		block = large_fit(*heap, size);
	else
		block = first_fit(*heap, size);
	if (block)
		return (block);
	return (get_block(&((t_meta *)(*heap))->next, size));
}