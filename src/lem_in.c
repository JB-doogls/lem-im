/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:44:30 by user              #+#    #+#             */
/*   Updated: 2020/09/11 01:28:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	TODO:	handle duplicate links
*/


t_frame		*create_map()
{
	t_room		*map;
	t_input		*input;
	t_frame		*stor;

	if (!(input = read_input()))
	{
		free_input(input);
		lem_error(READ_ERR, NULL);
	}
	stor = init_storage(&input);
	if (!(map = parse_input(input, stor)) || !is_valid_map(stor))
		lem_error(NOT_ENOUGH_ERR, stor);
	// lem_free(stor);
	return (stor);
}

int			main(int ac, char **av)
{
	t_frame		*stor;

	errno = 0;
	// if (ac >= 2) 	// Here is to handle possible bonus-flags
	// {				// --help, --verbose, --debug, etc
	// }
	if (ac == 1)
		stor = create_map();
	// else
	// 	lem_error(SMTH_HERE)
	
	return(0);
}
