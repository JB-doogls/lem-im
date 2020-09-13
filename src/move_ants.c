/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 01:52:24 by user              #+#    #+#             */
/*   Updated: 2020/09/13 03:07:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "lem_parser.h"

/*
**		
*/

void		set_ants_on_paths(t_frame *stor)
{
	t_path		*path_copy;
	int			ants_ct;

	ants_ct = stor->start->ants;
	path_copy = stor->paths;
	while (ants_ct != 0)
	{
		while (path_copy->next && path_copy->len + path_copy->ants_togo <=
		path_copy->next->len + path_copy->next->ants_togo)
		{
			path_copy->ants_togo++;
			ants_ct--;
		}
		if (!path_copy->next)
		{
			path_copy->ants_togo++;
			ants_ct--;
		}
		path_copy = path_copy->next ? path_copy->next : stor->paths;
	}
	// print_path_list(stor);	// tmp func for testing	**** DELETE
}

void		handle_ants_move(t_frame *stor)
{
	set_ants_on_paths(stor);
}