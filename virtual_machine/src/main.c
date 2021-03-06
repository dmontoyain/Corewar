/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 13:46:18 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_corewar	core;

	if (argc == 1)
		corewar_error(USAGE, 1);
	ft_bzero(&core, sizeof(t_corewar));
	init_environment(&core);
	init_operations(core.op);
	init_parse_args(&core);
	retrieve_data(&core, ++argv);
	if (!core.env.total_processes)
		corewar_error("Please provide a valid player", 1);
	init_ncurses(&core);
	init_board(&core);
	core.flag.viz ? loop_viz(&core) : loop(&core);
	terminate_ncurses(&core);
	core.flag.dump ? dump_board(&core) : 0;
	return (0);
}
