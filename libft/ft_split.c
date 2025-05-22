/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duarte <duarte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:31:05 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/09 18:22:22 by duarte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freeall(char **split, int n)
{
	while (n--)
		free(split[n]);
	free(split);
	return (NULL);
}

static	size_t	ft_count_words(const char *str, char c)
{
	size_t	words;
	size_t	x;

	words = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			words++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (words);
}

static size_t	ft_getpos(const char *s, char c)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	size_t	counter;
	size_t	words;
	size_t	final;
	char	**split;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	counter = 0;
	while (counter < words)
	{
		while (*s && *s == c)
			s++;
		final = ft_getpos(s, c);
		split[counter] = ft_substr(s, 0, (int)final);
		if (!split[counter])
			return (freeall(split, counter));
		s += final;
		counter++;
	}
	split[words] = NULL;
	return (split);
}

/* void printresult(char **result)
{
	int i = 0;
	if (!result)
	{
		printf("NULL\n");
		return;
	}
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
}
int main()
{
	char *test1 = "Hello \0world !";
	char **result1 = ft_split(test1, '\0');
	char *test2 = "HelloWorld!";
	char **result2 = ft_split(test2, 'a');
	char *test3 = "";
	char **result3 = ft_split(test3, 'v');
	char *test4 = NULL;
	char **result4 = ft_split(test4, 'a');

	printresult(result1);
	printresult(result2);
	printresult(result3);
	printresult(result4);
	return 0;
} */