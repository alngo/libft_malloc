/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:56 by alngo             #+#    #+#             */
/*   Updated: 2020/01/27 15:51:04 by alngo            ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>
#include <limits.h>

typedef struct		s_meta
{
	size_t			data;
	void			*next;
}					t_meta;

typedef struct		s_arena
{
	void			*tiny;
	void			*small;
	void			*large;
}					t_arena;

t_arena				arenas;

void				*malloc(size_t size);

#endif
