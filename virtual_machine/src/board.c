/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:36 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 22:44:57 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    create_board(t_board_node **brd, t_board_node **add, t_board_node **rev)
{
	int				i;
	t_board_node	*tmp;
	t_board_node	*tmpprev;

	i = -1;
	tmp = NULL;
	tmpprev = NULL;
	while (++i < MEM_SIZE)
	{
		tmp = ft_memalloc(sizeof(t_board_node));
		if (!tmp)
			corewar_error("Failed to create a board node", 0);
		add[i] = tmp;
		rev[MEM_SIZE - i - 1] = tmp;
		if (tmpprev)
			tmpprev->next = tmp;
		tmp->prev = tmpprev;
		if (!(*brd))
			*brd = tmp;
		tmp->index = i;
		tmpprev = tmp;
		tmp = tmp->next;
	}
	(*brd)->prev = tmp;
	tmpprev->next = *brd;
}

void	init_board(t_corewar *core)
{
	uint8_t		p;
	uint8_t		k;
	uint16_t	i;
	uint16_t	j;
	char		*instruction;

	create_board(&core->board, core->node_addresses, core->node_addresses_rev);
	p = -1;
	k = 0;
	while (++p < 4)
	{
		if (core->player[p].player_num)
		{
			j = ((++k - 1) * (MEM_SIZE / core->env.num_players));
			push(&core->process_stack[0], new_process(&core->player[p],
				core->node_addresses[j], NULL));
			i = 0;
			while (i < core->player[p].instruction_size)
			{
				instruction = &core->player[p].header.instructions[i++];
				ft_memcpy(&core->node_addresses[j]->value, instruction, 1); // change this to core->node_addresses[j++]->value = (uint8_t)core->player[p].header.instructions[i++];
				VIZ(draw_to_bored(core, core->player[p].player_num, j, 1));
				++j;
			}
		}
	}
}

// void	init_board(t_corewar *core)
// {
// 	uint8_t		p;
// 	uint16_t	i;
// 	uint16_t	j;
// 	char		*instruction;

// 	create_board(&core->board, core->node_addresses, core->node_addresses_rev);
// 	p = 4;
// 	while (p > 0)
// 	{
// 		--p;
// 		if (core->player[p].player_num)
// 		{
// 			j = p * (1024 + 1024);
// 			push(&core->process_stack[p][0], new_process(&core->player[p],
// 				core->node_addresses[j], NULL));
// 			i = 0;
// 			while (i < core->player[p].instruction_size)
// 			{
// 				instruction = &core->player[p].header.instructions[i++];
// 				ft_memcpy(&core->node_addresses[j]->value, instruction, 1); // change this to core->node_addresses[j++]->value = (uint8_t)core->player[p].header.instructions[i++];
// 				VIZ(draw_to_bored(core, core->player[p].player_num, j, 1));
// 				++j;
// 			}
// 		}
// 	}
// }
