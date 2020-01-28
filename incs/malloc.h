/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:56 by alngo             #+#    #+#             */
/*   Updated: 2020/01/28 13:36:09 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/mman.h>

typedef enum		e_malloc_mask
{
	INUSE = 0x4,
	MMAPD = 0x2,
	PREVINUSE = 0x1
}					t_malloc_mask;

typedef enum		e_malloc_type
{
	TINY = 128,
	SMALL = 1024,
	LARGE = 4096
}					t_malloc_type;

typedef struct		s_meta
{
	size_t			size: 61;
	unsigned char	flags: 3;
	void			*next;
}					t_meta;

typedef struct		s_arena
{
	void			*tiny;
	void			*small;
	void			*large;
}					t_arena;

extern t_arena		g_arena;

void				*malloc(size_t size);

/*
** block.c
*/

void				*get_block(void **heap, size_t size);
void				*first_fit(void *heap, size_t size);

/*
** heap.c
*/

size_t				get_heap_size(size_t size);
void				*init_heap(size_t size);

/*
** utils.c
*/

void				*get_payload(void *ptr);
t_meta				*get_meta(void *ptr);
t_meta				*set_meta(void *ptr, size_t size,
					unsigned char flags, void *next);
size_t				size_alignment(size_t size, size_t alignment);

#endif