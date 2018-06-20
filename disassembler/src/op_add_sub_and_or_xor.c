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

#include "disassembler.h"

/*
**	Math - takes reg reg reg
**	- - - - - - - - - -
**	Add, Sub, XOR, OR, AND
*/

uint16_t	math_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t	*eb;

	eb = parse_encoding_byte(*(content++));
	if (BAD_EB || EB0 != REGISTER || EB1 != REGISTER || EB2 != REGISTER)
		INSTR_ERR(ft_str128(2, op->name, " -- invalid encoding byte"));
	if (content[0] > REG_NUMBER || content[0] < 1)
		INSTR_ERR(ft_str128(2, op->name, " -- arg 1 is not a valid register"));
	if (content[1] > REG_NUMBER || content[1] < 1)
		INSTR_ERR(ft_str128(2, op->name, " -- arg 2 is not a valid register"));
	if (content[2] > REG_NUMBER || content[2] < 1)
		INSTR_ERR(ft_str128(2, op->name, " -- arg 3 is not a valid register"));
	write_instruction(fd, op);
	write_reg(fd, content[0], 1);
	write_reg(fd, content[1], 1);
	write_reg(fd, content[2], 0);
	return (4);
}
