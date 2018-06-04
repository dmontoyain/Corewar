/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:27:31 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/02 00:42:29 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	advance(t_input *line)
{
	line->index++;
	if (line->index > line->len - 1)
		line->current_char = '\0';
	else
		line->s[line->index];
}

char	*parse_value(t_input *line)
{
	size_t	start;
	
	handle_whitespace(line);
	if (ft_isprint(line->current_char))
		start = line->index;
	while (line->current_char && ft_isprint(line->current_char))
		advance(line);
	return (ft_strsub(line->s, start, line->current_char - start));
}

void	get_token_type(t_token *token)
{
	size_t	len;
	uint8_t	op;
	uint8_t	param;
	char	*s;

	s = token->value;
	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len > 1 || s[len - 2] == LABEL_CHAR)
		token->type = LABEL;
	else if (op = compare_to_ops(s))
	{
		token->type = OPERATION;
		token->subtype = op;
	}
	else if (param = compare_to_params(s))
	{
		token->type = PARAMETER;
		token->subtype = param;
	}
	else
		token->type = NONE;
}

t_token	get_next_token(t_input *line, uint8_t type)
{
	t_token		new_token;

	line->current_char = line->s[line->index];
	new_token.value = parse_value(line);
	get_token_type(&new_token);
}

