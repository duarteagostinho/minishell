/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:10:29 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/12 18:48:02 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimmed(char const *set, char t)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == t)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_trimmed(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_trimmed(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(sizeof(*s1) * end - start + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
/* int main()
{
	printf("%s", ft_strtrim("ssssssssssss/ola, tudo bem?/s/", "/s"));
	return 0;
} */