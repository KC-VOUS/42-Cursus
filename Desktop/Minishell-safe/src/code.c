#include "../lexer.h"

char	*expand(char *s, char **env)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	*str;

	while (env[i])
	{
		if (strncmp(env[i], s, (strlen(s))) == 0)
		{
			str = malloc(strlen(env[i]) - strlen(s) + 1);
			j = strlen(s);
			while (env[i][j])
			{
				str[k] = env[i][j];
				k++;
				j++;
			}
			str[k] = '\0';
			return (str);
		}
		else
			i++;
	}
	return (s);
}

char	*expande_moi(char *s, char **env)
{
	int	i = 0;
	int	j = 0;
	char	*str;
	char	*str2;

	while (s[i])
	{
		if (s[i] == '$')
		{
			i++;
			j = i;
			while (s[i] && s[i] != ' ' && s[i] != '$')
				i++;
			str = (char *)malloc((i - j) + 2 * sizeof(char));
			if (!str)
				return (NULL);
			i = j;
			j = 0;
			while (s[i] && s[i] != ' ' && s[i] != '$')
			{
				str[j++] = s[i];
				i++;
			}
			str[j++] = '=';
			str[j] = '\0';
			str2 = expand(str, env);
			if (strncmp(str2, str, strlen(str)) == 0)
				return (s);
			else
				return (str2);
		}
		else
			i++;
	}
	return (s);
}
