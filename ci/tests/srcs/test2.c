/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:17:48 by alngo             #+#    #+#             */
/*   Updated: 2020/02/24 16:50:40 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/malloc.h"

int			main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char *)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return (0);
}
