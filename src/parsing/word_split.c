/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:00:00 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/25 16:34:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

static int	count_words(t_str str)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if ((str[i] == ' ' || str[i] == '\t') && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

static t_str	extract_word(t_str str, int *pos)
{
	int		start;
	int		len;
	t_str	word;
	int		i;

	while (str[*pos] && (str[*pos] == ' ' || str[*pos] == '\t'))
		(*pos)++;
	start = *pos;
	while (str[*pos] && str[*pos] != ' ' && str[*pos] != '\t')
		(*pos)++;
	len = *pos - start;
	if (len == 0)
		return (NULL);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

t_vtr	word_split(t_str str)
{
	t_vtr	words;
	int		word_count;
	int		pos;
	int		i;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	words = malloc(sizeof(t_str) * (word_count + 1));
	if (!words)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < word_count)
	{
		words[i] = extract_word(str, &pos);
		if (!words[i])
		{
			free_vtr(words, get_sizeof_args(words));
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
