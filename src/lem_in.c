/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:44:30 by user              #+#    #+#             */
/*   Updated: 2020/09/10 21:57:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void		lem_in()
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
	if (!(map = parse_input(input, stor)) || !check_parsing(stor))
		lem_error(INP_ERR, stor);
	// find_path()	- bfs
	// pass_ants()
	lem_free(stor);

}

int			main(int ac, char **av)
{
	errno = 0;

	// if (ac >= 2) 	// Here is to handle possible bonus-flags
	// {				// --help, --verbose, --debug, etc
	// }
	if (ac == 1)
		lem_in();
	// else
	// 	lem_error(SMTH_HERE)
	
	return(0);
}
