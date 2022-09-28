
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_matrix(char	*str, char	*line)
{
	char	*mew;
	int		len_str;
	int		len_line;

	len_str = ft_strlen(str);
	len_line = ft_strlen(line);
	mew = malloc(sizeof(char) * (len_str - len_line + 1));
	if (!mew)
		return (NULL);
	ft_memcpy(mew, str + len_line, len_str - len_line + 1);
	free(str);
	return (mew);
}

char	*ft_free(char *str, char *tmp)
{
	free(str);
	free(tmp);
	return (NULL);
}

char	*ft_parse(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_memory(int fd, char *str, int buffer)
{
	char	*tmp;
	int		byte;

	byte = 1;
	tmp = malloc(sizeof(char) * (buffer + 1));
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	while (ft_strchr(tmp, '\n') == NULL && byte != 0)
	{
		byte = read(fd, tmp, buffer);
		if (byte < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = '\0';
		str = ft_strjoin_gnl(str, tmp);
	}
	if (!byte && !*str)
		return (ft_free(str, tmp));
	free(tmp);
	return (str);
}

char	*get_next_line(int fd, int buffer)
{
	char		*line;
	static char	*str;

	if (buffer <= 0 || fd < 0)
		return (NULL);
	str = ft_memory(fd, str, buffer);
	if (!str)
		return (NULL);
	line = ft_parse(str);
	str = ft_matrix(str, line);
	return (line);
}