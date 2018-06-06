/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:56:15 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x04 - ADD
**	- - - - - - - - - -
**	Takes 3 registers. Adds content of first two, and stores it in reg 3
*/

void		add_(t_corewar *core, t_process *process)
{
	uint32_t	additive_result;

	(void)core;
	additive_result = 0;
	DB("adding");
	if (!parse_encoding_byte(process))
		return ; // Do we just treat the next argument as an operation?
	if (EB0 != REGISTER || EB1 != REGISTER || EB2 != REGISTER)
		return ;
	if (!parse_arguments(process))
		return ;
	additive_result = smash_bytes(process->reg[process->args[0][0]]);
	additive_result += smash_bytes(process->reg[process->args[1][0]]);
	ft_printf("additive result: %.8x\n", additive_result);
	process->reg[process->args[2][0]][0] = (uint8_t)(additive_result >> 24);
	process->reg[process->args[2][0]][1] = (uint8_t)(additive_result >> 16);
	process->reg[process->args[2][0]][2] = (uint8_t)(additive_result >> 8);
	process->reg[process->args[2][0]][3] = (uint8_t)(additive_result >> 0);
}