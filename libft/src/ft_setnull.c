/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:41:33 by bpierce           #+#    #+#             */
/*   Updated: 2017/08/18 12:47:21 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_setnull(void *a, void *b, void *c, void *d)
{
	if (a)
		a = NULL;
	if (b)
		b = NULL;
	if (c)
		c = NULL;
	if (d)
		d = NULL;
	return ;
}