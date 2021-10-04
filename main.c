#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int     main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int i;

    while ((i = get_next_line(fd, &line)) > 0)
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
    printf("i = %d %s\n", i, line);
    free(line);
    return (0);
}