#include "get_next_line.h"

char				*ft_strchr(const char *s, int c)
{
	long int		len_s;
	char			*p_c;

	if (!s || *s == '\0')
		return (NULL);
	p_c = (char *)s;
	len_s = ft_strlen(p_c) + 1;
	while (len_s--)
		if (*p_c++ == c)
			return (p_c - 1);
	return (NULL);
}

char				*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str != NULL)
	{
		while (s && s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char				*ft_strdup_n(const char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str != NULL)
	{
		while (s && (s[i] != '\0') && (s[i] != '\n'))
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

size_t				ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strjoin_clean(char *s1, char *s2)
{
	char			*p_free_s1;
	char			*start_str;
	char			*str_s1_s2;
	unsigned int	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (s2 == NULL)
		return (NULL);
	if (!(str_s1_s2 = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	start_str = str_s1_s2;
	p_free_s1 = s1;
	while (s1 && *s1 != '\0')
		*str_s1_s2++ = *s1++;
	while (*s2 != '\0')
		*str_s1_s2++ = *s2++;
	*str_s1_s2 = '\0';
	free(p_free_s1);
	return (start_str);
}
