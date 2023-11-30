# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
typedef struct s_liste
{
    char *data;
    struct s_liste *next;
    
} t_list;
char	*ft_strjoin(char *s1, char *s2);
int     found_newline(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *s, int c);
int	    ft_strlen(const char *s);
char    *save_data(char *container);
char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif