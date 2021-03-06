/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedintlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 15:14:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/12/31 15:24:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_unsignedintlen(unsigned int x)
{
	if (x > 99999)
	{
		if (x > 9999999)
		{
			if (x > 999999999)
				return (10);
			return (x > 99999999 ? 9 : 8);
		}
		return (x > 999999 ? 7 : 6);
	}
	else
	{
		if (x > 999)
			return (x > 9999 ? 5 : 4);
		else
		{
			if (x > 99)
				return (3);
			return (x > 9 ? 2 : 1);
		}
	}
}
