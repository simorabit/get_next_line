#include "get_next_line.h"
static char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src != '\0')
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	return (dest);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}
char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	

	return (NULL);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	if (start > s_len)
		return (ft_strdup(""));
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

int found_newline(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return 1;
        i++;
    }
    return 0; 
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new_value;

	i = 0;
	new_value = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!new_value)
		return (NULL);
	while (s1[i])
	{
		new_value[i] = s1[i];
		i++;
	}
	new_value[i] = '\0';
	return (new_value);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
	{
		free(s1);
		return (NULL);
	}
	ptr = ft_strcpy(result, s1);
	ptr = ft_strcpy(result + s1_len, s2);
	*(ptr + s2_len) = '\0';
	free(s1);
	return (result);
}
char * save_data(char *container)
{
	int i;
	int pos;
	int len;
	char *result;
	int j;
	
	j = 0;
	pos = 0;
	i = 0;
	if (!container)
		return NULL;
	if (!ft_strchr(container, '\n'))
	{
		return (NULL);
	}
	if (ft_strchr(container,'\n') == NULL)
		return ft_strdup("");

	len = ft_strlen(container);
	while(*container)
	{
		if(container[i] == '\n')
		{
			pos = i;
			break;
		}
		i++;
	}
	int len_res = len - pos;
	result = malloc(len_res);
	if (!result)
	{
		return NULL;
	}	
	while (j < len_res - 1 && *container)
	{
		result[j++] = container[++pos];
	}
	result[j] = '\0';
	free(container);
	container = NULL;
	return result;
}