/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 05:19:26 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		tablen(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
