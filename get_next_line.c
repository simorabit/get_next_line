#include "get_next_line.h"

char *get_lines(int fd, char *buf, char **container)
{
    int reader;
    int i;
    char *line;

    i = 0;
    reader = 1;
    if(!*container)
            *container = ft_strdup("");
    while (reader && !ft_strchr(*container,'\n'))
    {
        reader = read(fd,buf,BUFFER_SIZE);
        if(reader == -1)
        {
            return NULL;
        }
        if(reader == 0)
            break;
        buf[reader] ='\0';
        *container = ft_strjoin(*container,buf);
    }
    if (reader == 0 && *container && !**container)
	{
		return (NULL);
	}
    if(ft_strchr(*container,'\n'))
    {
        while ((*container)[i] != '\n')
            i++;
        line = ft_substr(*container, 0, i + 1);
    }
    else
        return *container;
    return line;
}
char *get_next_line(int fd)
{
    char *buf;
    static char *container;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT32_MAX)
    {
        if (container)
            free(container), container = NULL;
        return NULL;
    }
    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buf)
    {
        if (container)
            free(container), container = NULL;
        return NULL;
    }
    line = get_lines(fd, buf, &container);
    if (!line)
        return (free(container), container = NULL, free(buf),  NULL);
    container = save_data(container);
    free(buf);
    return line;
}
// int main()
// {
//     int fd;
//     int i = 3;
//     fd = open("ex.txt",O_RDONLY);
//     char *str;

//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//    /* while(i--)
//     {
//         str = get_next_line(fd);
//         printf("%s",str);
//         free(str);
//     }*/
//     // system("leaks a.out");
// }
