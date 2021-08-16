#include "string_functions.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_realloc(char *str, int *size)
{
	char	*temp;

	write(1, "3\n", 2);
	*size = *size * 2;
	temp = (char *) malloc(sizeof(char *) * (*size) + 1);
	ft_strcpy(temp, str);
	free(str);
	return (temp);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	write(1, "\n", 1);
}
