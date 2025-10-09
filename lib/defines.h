/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:40:46 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 09:50:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define PARENT 1
# define CHILD 2
# define IGNORE 3
# define HEREDOC 4
# define ERR_SYN_QUOTES "Syntax error: quotes unclosed\n"
# define ERR_SYN_RD "Syntax error: redirections\n"
# define ERR_SYN_PIPE "Syntax error: pipes\n"
# define ERR_EMPTY_INP "Error: Empty input\n"
# define ERR_SYN_PIPE "Syntax error: pipes\n"
# define GRN "\e[4;32m"
# define PRP "\e[0;35m"
# define WHT "\e[1;37m"
# define RED "\e[1;31m"
# define LG_RED "\e[0;31m"
# define COLOR_RESET "\e[0m"
# define _GNU_SOURCE

#endif