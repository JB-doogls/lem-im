/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:01:22 by user              #+#    #+#             */
/*   Updated: 2020/08/26 19:55:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_frame		*init_storage(t_input **input)
{
	t_frame		*stor;

	if (!(stor = ft_memalloc(sizeof(t_frame))))
		return (NULL);
	while ((*input)->line[0] == '#')
		(*input) = (*input)->next;
	
	if (ft_isdigit((*input)->line[0]) && !is_valid_ants((*input)->line))
		stor->num_ants = ft_atoi((*input)->line);
	else
		lem_error(NO_ANTS);
	stor->num_rooms = 0;
	stor->end = NULL;
	stor->start = NULL;
	return (stor);
	
}

t_room		*parse_input(t_frame *stor, t_input *input)
{
	t_room		*room;

	stor = init_storage(&input);

	return (room);
}