/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:39:09 by user              #+#    #+#             */
/*   Updated: 2020/09/10 18:58:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Check input funcs
*/

int			is_valid_ants(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '0' || !ft_isposint_str(str))
		lem_error(NO_ANTS_ERR);
	return (1);
}

int			is_link(char *line)
{	
	char	**split;

	if (!line)
		lem_error(READ_ERR);
	if (!(split = ft_strsplit(line, '-')))
		lem_error(ALLOC_ERR);
	if (ft_len_splited(split) != 2 || !is_room_name(split[0]) ||
	!is_room_name(split[1]))
	{
		ft_free_splited(split);
		return (0);
	}
	ft_free_splited(split);
	return (1);
}

int			is_hash(char *line)
{
	if (!line)
		lem_error(READ_ERR);
	return (line[0] == '#'); 
}

int			is_room_name(char *line)
{
	if (!line)
		lem_error(READ_ERR);
	return (line[0] != 'L' || line[0] != '#');
}

int			is_room(char *line)
{
	char	**split;
	int		res;

	res = 1;
	if (!line)
		lem_error(READ_ERR);
	if (!(split = ft_strsplit(line, ' ')))
		lem_error(ALLOC_ERR);
	if (ft_len_splited(split) != 3 || !is_room_name(split[0]) ||
	!ft_isint_str(split[1]) || !ft_isint_str(split[2]))
		res = 0;
	ft_free_splited(split);
	return (res);
}
