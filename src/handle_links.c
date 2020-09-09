/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:42:43 by user              #+#    #+#             */
/*   Updated: 2020/09/10 01:42:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*create_link(t_room *room)
{
	t_link	*link;

	if (!(link = ft_memalloc(sizeof(t_room))))
		lem_error(LINKS_ERR);
	link->room = room;
	link->next = NULL;
	return (link);

}	

void		set_links(t_room *room1, t_room *room2)
{
	t_link		*link;

	if (!(link = room1->link))
	{
		if (!(room1->link = create_link(room2)))
			lem_error(LINKS_ERR);
		room1->num_links++;
		return;
	}
	while (link->next)
	{
		if (!ft_strcmp(link->room->name, room1->name) ||
		!ft_strcmp(link->room->name, room2->name))
			return;
		link = link->next;
	}
	room1->num_links++;
	if (!(link->next = create_link(room2)))
		lem_error(LINKS_ERR);
	return;
}

void		find_rooms(t_room *room, const char *r1, const char *r2)
{
	t_room		*copy;
	t_room		*room1;
	t_room		*room2;

	room1 = NULL;
	room2 = NULL;
	copy = room;
	while (copy && (!room1 || !room2))
	{
		if (!ft_strcmp(copy->name, r1))
			room1 = copy;
		else if (!ft_strcmp(copy->name, r2))
			room2 = copy;
		copy = copy->next;
	}
	if (!room1 || !room2)
		lem_error(LINKS_ERR);
	set_links(room1, room2);
	set_links(room2, room1);
	
}

void		handle_links(t_room *room, char *line)
{
	char		*room1;
	char		*room2;
	char		**split;

	if (!(split = ft_strsplit(line, '-')))
		lem_error(ALLOC_ERR);
	if (!(room1 = split[0]) || !(room2 = split[1]))
		return;
	find_rooms(room, room1, room2);
}
