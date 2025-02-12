/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:36:52 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/12 11:50:20 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

// char	*ft_strdup(const char *s)
// {
// 	char	*copy;
// 	size_t	len;

// 	if (!s) // Protection contre un pointeur NULL
// 		return (NULL);
// 	len = strlen(s);
// 	copy = (char *)malloc((len + 1) * sizeof(char));
// 	if (!copy)
// 		return (NULL);
// 	memcpy(copy, s, len + 1); // Copie optimisée
// 	return (copy);
// }

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	count_tab(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**cpenv(char **env)
{
	int		i;
	char	**envcpy;

	i = 0;
	envcpy = (char **)malloc((count_tab(env) + 1) * sizeof(char *));
	if (!envcpy)
		return (NULL);
	while (env[i])
	{
		envcpy[i] = ft_strdup(env[i]);
		if (!envcpy[i])
		{
			while (i > 0)
				free(envcpy[--i]);
			free(envcpy);
			return (NULL);
		}
		i++;
	}
	envcpy[i] = NULL;
	return (envcpy);
}
