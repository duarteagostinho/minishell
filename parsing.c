/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:20:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/10 15:52:58 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char  *readl_prompt(char  *prompt)
{
  char  *line;

  line = NULL;
  if (!prompt || !*prompt)
      return (NULL);
  line = readline(prompt);
  if (!line || !*line)
    return (NULL);
  return (line);
}
