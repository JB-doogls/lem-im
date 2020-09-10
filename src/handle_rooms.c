/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:58:45 by user              #+#    #+#             */
/*   Updated: 2020/09/10 21:39:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_start_end_room(t_frame *stor, t_room *room)
{
	if (stor->cmd == START_SIG)
	{
		stor->start = room; //ft_strdup(room->name);
		room->level = 0;
		stor->cmd = NO_SIG;
	}
	if (stor->cmd == END_SIG)
	{
		stor->end = room; //ft_strdup(room->name);
		room->level = INT_MAX;
		stor->cmd = NO_SIG;
	}
}

t_room		*create_room(t_frame *stor, char *line)
{
	t_room	*room;
	char	**split;

	if (!line || !(room = ft_memalloc(sizeof(t_room))))
		lem_error(ROOM_ADD_ERR, stor);
	if (!(split = ft_strsplit(line, ' ')) ||
	!(room->name = ft_strdup(split[0])))
	{
		ft_free_splited(split);
		lem_error(ROOM_ADD_ERR, stor);
	}
	room->coord[0] = ft_atoi(split[1]);
	room->coord[1] = ft_atoi(split[2]);
	room->level = -1;
	room->num_links = 0;
	room->visit = 0;
	room->next = NULL;
	room->link = NULL;
	get_start_end_room(stor, room);
	ft_free_splited(split);
	stor->num_rooms++;
	return (room);
}

/*
**	Держим указатель на head всегда возвращая room.
**	Прокручиваемся от него в конец через копию
**	и добавляем в конец списка new_room
*/

t_room		*add_room(t_room *room, t_room *new_room, t_frame *stor)
{
	t_room	*tmp;

	if (!new_room)
		lem_error(ROOM_ADD_ERR, stor);
	if (!room)
		return (new_room);
	tmp = room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_room;
	return (room);

}
