/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:45:23 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:28:58 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    loop(t_corewar *core)
{
	uint8_t		board_value;
	t_process	*process;

	while (1)
	{
		while (!isemptys(&PROCESS_STACK[CURRENT_CYCLE]))
		{
			process = pop(&PROCESS_STACK[CURRENT_CYCLE]);
			process->instruct(core, process);
			board_value = ZERO_AT_BAD_INSTR(process->curr_pc->value);
			process->instruct = core->op[board_value].instruct;
			insert_process(core, &core->process_stack[(core->env.cycle + core->op[board_value].wait_time) % PROCESS_STACK_LEN], process);
		}
        cycle_handle(core);
        key_hit(core);
        game_speed(core->env.game_speed); // 1 is fast, 50 is slow
	}
}

void    loop_viz(t_corewar *core)
{
	uint8_t		board_value;
	t_process	*process;

	while (1)
	{
		while (!isemptys(&PROCESS_STACK[CURRENT_CYCLE]))
		{
			process = pop(&PROCESS_STACK[CURRENT_CYCLE]);
			pop_process_cursor(core, process);
			print_process_info(&core->ncur, process);
			process->instruct(core, process);
			board_value = ZERO_AT_BAD_INSTR(process->curr_pc->value);
			process->instruct = core->op[board_value].instruct;
			insert_process(core, &core->process_stack[(core->env.cycle + core->op[board_value].wait_time) % PROCESS_STACK_LEN], process);
			wrefresh(core->ncur.playa[process->player->player_num - 1]);
			if (smash_bytes(process->reg[4]) > 0)
				DBI(core->env.cycle);
		}
		print_game_info(core);
		wrefresh(core->ncur.bored);
		cycle_handle(core);
        game_speed(core->env.game_speed);
        if (core->env.cycle > 0)
			key_hit(core);

	}
}

void    game_speed(uint8_t speed)
{
    int j = 0;

    while (j++ < ((speed * PROCESS_STACK_LEN * 10) << 3))
        for (int64_t d = 0; d < speed; d++){}
}