#include "get_next_line.h"

static char		*read_posle_n(char *rd_all)
{
	char		*n;
	char		*ostatok;

	if ((rd_all == NULL) || (*rd_all == '\0') || !(n = ft_strchr(rd_all, '\n')))
	{
		free(rd_all);
		return (NULL);
	}
	ostatok = ft_strdup(++n);
	free(rd_all);
	return (ostatok);
}

int				get_next_line(int fd, char **line)
{
	static char	*rd_all;
	char		*rd_s;
	long int	len_r;

	len_r = 5;
	if ((read(fd, 0, 0) == -1) || BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (!(rd_s = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((!ft_strchr(rd_all, '\n')) && (len_r = read(fd, rd_s, BUFFER_SIZE)))
	{
		rd_s[len_r] = '\0';
		if (!(rd_all = ft_strjoin_clean(rd_all, rd_s)))
			return (-1);
	}
	free(rd_s);
	if (len_r < 0)
	{
		free(rd_all);
		return (-1);
	}
	if (!(*line = ft_strdup_n(rd_all)))
		return (-1);
	rd_all = read_posle_n(rd_all);
	return (len_r == 0 ? 0 : 1);
}
