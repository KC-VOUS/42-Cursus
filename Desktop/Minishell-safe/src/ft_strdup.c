/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:15:02 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/01/20 10:51:21 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	char	*head;
	int		i;

	i = 0;
	while (s[i])
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	head = ret;
	while (*s)
		*ret++ = *s++;
	*ret = '\0';
	return (head);
}
