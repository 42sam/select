/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 02:10:49 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/03 02:10:54 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**lst_to_array(t_list *lst)
{
	char	**array;
	int		len;
	int		i;
	int		varlen;

	if (lst == NULL)
		return (NULL);
	i = 0;
	len = ft_lstlen(lst);
	array = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		varlen = LEN(lst->name) + LEN(lst->value) + 2;
		array[i] = (char *)malloc(varlen);
		ft_strcpy(array[i], lst->name);
		ft_strcat(array[i], "=");
		ft_strcat(array[i], lst->value);
		lst = lst->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
