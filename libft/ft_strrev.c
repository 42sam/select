/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:04:56 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	char t;
	char *s2;
	char *e;

	e = s + strlen(s);
	s2 = s;
	while (e-- > s)
	{
		t = *s;
		*s++ = *e;
		*e = t;
	}
	return (s2);
}
