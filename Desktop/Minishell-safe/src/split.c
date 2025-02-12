/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:42:10 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/11 16:48:10 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	count_words(char *s, char c, int i)
{
	int		count;
	char	quote;

	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if (s[i] == '"' || s[i] == '\'')
			{
				quote = s[i];
				i = quote_handle(s, quote, i);
			}
			else if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			{
				if (s[i + 1] == s[i] && s[i] != '|')
					i++;
				i++;
			}
			else
			{
				while (s[i] && s[i] != c && s[i] != '"' && s[i] != '\'' && s[i] != '|' && s[i] != '<' && s[i] != '>')
					i++;
			}
			count++;
		}
	}
	return (count);
}

char	*malloc_word(char **s, char c)
{
	char	*start;
	char	quote;
	int		len;

	if (**s == c)
	{
		while (**s == c)
			(*s)++;
		return (create_word(" ", 1));
	}
	if (**s == '"' || **s == '\'')
	{
		quote = **s;
		start = is_double_quote(s, quote);
		while (**s && **s != quote)
			(*s)++;
		len = dq_len(s, start, quote);
		if (**s)
			(*s)++;
	}
	else if (**s == '|' || **s == '<' || **s == '>')
	{
		start = *s;
		if ((*s)[1] == **s && **s != '|')
			(*s)++;
		(*s)++;
		len = *s - start;
	}
	else
	{
		start = *s;
		while (**s && **s != c && **s != '"' && **s != '\'' && **s != '|' && **s != '<' && **s != '>')
			(*s)++;
		len = *s - start;
	}
	return (create_word(start, len));
}

char	**insert_words(char *s, char c, int count)
{
	char	**words;
	int		i;

	words = (char **)malloc((count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < count)
	{
		words[i] = malloc_word(&s, c);
		if (!words[i])
		{
			while (i > 0)
				free(words[--i]);
			free(words);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}

int	count(char *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = count_words(s, c, i);
	return (nb);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		count;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c, i);
	split = insert_words(s, c, count);
	return (split);
}
