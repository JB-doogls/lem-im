/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:49:46 by user              #+#    #+#             */
/*   Updated: 2020/09/10 18:57:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_error(char *str)
{
	if (errno == 0)
		perror(str);
	else
		ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void		free_map(t_room *room)
{
	t_room		*tmproom;
	t_link		*tmplink;

	while (room)
	{
		free(room->name);
		tmproom = room;
		while (room->link)
		{
			tmplink = room->link;
			room->link = room->link->next;
			free(tmplink);
		}
		room = room->next;
		free(tmproom);
	}
	ft_memdel((void*)room);
}

void		free_stor(t_frame *stor)
{
	free(stor->start);
	free(stor->end);
	ft_memdel((void**)stor);
}

void		free_input(t_input *input)
{
	t_input		*tmp;

	while (input)
	{
		free(input->line);
		tmp = input;
		input = input->next;
		free(tmp);
	}
	ft_memdel((void*)input);
}

void		lem_free(t_input *input, t_frame *stor, t_room *room)
{
	if (input)
		free_input(input);
	if (stor)
		free_stor(stor);
	if (room)
		free_map(room);
}
