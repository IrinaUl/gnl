#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strdup_n(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_clean(char *s1, char *s2);
#endif
