/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:26:45 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/11 18:00:59 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	quote_handle(char *s, char quote, int i)
{
	i++;
	while (s[i] && s[i] != quote)
		i++;
	if (!s[i])
	{
		printf("unclosed quote\n");
		exit(EXIT_FAILURE);
	}
	i++;
	return (i);
}

char	*create_word(char *start, int len)
{
	char	*word;

	word = (char *)malloc(len + 1); //
	if (!word)
		return (NULL);
	strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	*is_double_quote(char **s, char quote)
{
	char	*start;

	if (quote == '\'')
	{
		start = *s;
		(*s)++;
	}
	else
	{
		(*s)++;
		start = *s;
	}
	return (start);
}

int	dq_len(char **s, char *start, char quote)
{
	int		len;

	len = 0;
	if (quote == '\'')
		len = (*s - start) + 1;
	else
		len = *s - start;
	return (len);
}
