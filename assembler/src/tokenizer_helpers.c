/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:14:13 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 18:59:50 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*remove_comment(char *s)
{
	int		pound_index;
	char	*tmp;

	pound_index = char_at(s, '#', 0);
	if (pound_index != -1)
		tmp = ft_strsub(s, 0, pound_index);
	else
		tmp = ft_strdup(s);
	return (tmp);
}

void	advance(t_input *line)
{
	line->index++;
	if (!line->len || line->index > line->len - 1)
		line->current_char = '\0';
	else
		line->current_char = line->s[line->index];
}

void	skip_separators(t_input *line)
{
	while (char_is_separator(line->current_char))
		advance(line);
}

void	remove_label_char(char **s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(*s);
	new_s = ft_strsub(*s, 0, len - 1);
	ft_strdel(s);
	*s = new_s;
}

int8_t	char_is_separator(char c)
{
	if (c == SEPARATOR_CHAR || ft_iswhitespace(c))
		return (1);
	return (0);
}
