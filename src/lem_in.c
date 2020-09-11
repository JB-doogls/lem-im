/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:44:30 by user              #+#    #+#             */
/*   Updated: 2020/09/11 22:04:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "lem_parser.h"

/*
**	TODO:
*/

int			main(int ac, char **av)
{
	t_frame		*stor;
	t_path		*path;

	errno = 0;
	// if (ac >= 2) 	// Here is to handle possible bonus-flags
	// {				// --help, --verbose, --debug, etc
	// }
	if (ac == 1)
	{
		stor = create_map();
		// path = create_path(stor);
	}
	// else
	// 	lem_error(SMTH_HERE)

	lem_free(stor);	
	return(0);
}
