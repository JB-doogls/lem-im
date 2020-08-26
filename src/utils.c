/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:39:09 by user              #+#    #+#             */
/*   Updated: 2020/08/26 19:59:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_valid_ants(char *str)
{
	int		ct;

	ct = 0;
	if (str[0] == '0')
		return (1);
	while (str[ct])
		if (!ft_isdigit(str[ct++]))
			return (1);
	if (ft_strlen(str) > MAXINT_LEN ||
		(ft_strlen(str) == MAXINT_LEN && str[MAXINT_LEN - 1] + '0' > 7))
		lem_error(BIG_ANT);
		// return (1);
	return (0);
}

void		lem_error(char *str)
{
	if (errno == 0)
		perror(str);
	else
		ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}