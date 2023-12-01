/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:00:22 by mal-mora          #+#    #+#             */
/*   Updated: 2023/12/01 12:41:00 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **container)
{
	if (*container)
	{
		free(*container);
		*container = NULL;
	}
	return (NULL);
}

static char	*save_data(char *container)
{
	int		i;
	int		len;
	char	*result;
	int		j;

	j = 0;
	i = 0;
	if (!container || !ft_strchr(container, '\n'))
		return (NULL);
	len = ft_strlen(container);
	while (container[i] != '\n')
		i++;
	len = len - i;
	result = malloc(len * sizeof(char));
	if (!result)
	{
		ft_free(&container);
		return (NULL);
	}
	while (j < len - 1 && *container)
		result[j++] = container[++i];
	result[j] = '\0';
	ft_free(&container);
	return (result);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			j;
	size_t			s_len;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len - start <= len)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if (j < len && i >= start)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

static char	*get_line(int fd, char *buf, char **container)
{
	int	reader;
	int	i;

	i = 0;
	reader = 1;
	if (!*container)
		*container = ft_strdup("");
	while (*container && reader && !ft_strchr(*container, '\n'))
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buf[reader] = '\0';
		*container = ft_strjoin(*container, buf);
	}
	if (reader == 0 && (!*container || !**container))
		return (NULL);
	if (ft_strchr(*container, '\n'))
	{
		while ((*container)[i] != '\n')
			i++;
		return (ft_substr(*container, 0, i + 1));
	}
	return (*container);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*container[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT32_MAX || fd > OPEN_MAX)
		return (ft_free(&container[fd]));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free(&container[fd]));
	line = get_line(fd, buf, &container[fd]);
	if (!line)
		return ((free(container[fd]), container[fd] = NULL, free(buf), NULL));
	container[fd] = save_data(container[fd]);
	free(buf);
	return (line);
}
// int main()
// {
//     int fd;
//     int i = 3;
//     fd = open("ex.txt",O_RDONLY);
//     int fd2 = open("he.txt", O_CREAT | O_RDWR, 0666);
//     if (fd2 == -1) {
//     perror("Error opening or creating he.txt");
//     return 1;
//     }
//     printf("%s",get_next_line(fd2));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd2));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd2));
//    /* while(i--)
//     {
//         str = get_next_line(fd);
//         printf("%s",str);
//         free(str);
//     }*/
//     // system("leaks a.out");
// }
