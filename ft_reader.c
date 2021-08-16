#include "ft_reader.h"

int	ft_get_field_description(t_field_char *field, char *str, int count_symb)
{
	int	count;
	int	i;

	count_symb--;
	field->full_symb = str[count_symb--];
	field->obstacle_symb = str[count_symb--];
	field->empty_symb = str[count_symb--];
	count = 0;
	i = 0;
	while (i <= count_symb)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		count = (count * 10) + (str[i] - 48);
		i++;
	}
	field->row_count = count;
	return (1);
}

char	*ft_read_line(int file)
{
	int		size;
	char	*line;
	char	c;
	int		i;
	int		file_rd;

	size = 100;
	line = (char *) malloc(sizeof(char) * size + 1);
	i = 0;
	c = '0';
	file_rd = 1;
	while (file_rd > 0 && c != '\n')
	{
		if (i >= size)
			line = ft_realloc(line, &size);
		file_rd = read(file, &c, 1);
		line[i] = c;
		i++;
	}
	i--;
	line[i] = '\0';
	return (line);
}

char	*ft_read_first_field_line(int file)
{
	char	*line;
	char	*res;

	line = ft_read_line(file);
	res = (char *) malloc(sizeof(char) * ft_strlen(line) + 1);
	ft_strcpy(res, line);
	return (res);
}

char	*ft_read_field_line(int file, int line_length)
{
	int		i;
	int		file_rd;
	char	c;
	char	*str;

	str = (char *) malloc(sizeof(char) * line_length + 1);
	if (!str)
		return (str);
	i = 0;
	file_rd = read(file, &c, 1);
	while (file_rd > 0 && c != '\n' && i < line_length)
	{
		str[i++] = c;
		file_rd = read(file, &c, 1);
	}
	if (file_rd < 0 || i > line_length || (c == '\n' && i != line_length))
	{
		free(str);
		return ((char *)0);
	}
	str[i] = '\0';
	return (str);
}

int	ft_read_field_char(t_field_char *field_char, int file)
{
	int		i;
	char	*description_line;

	description_line = ft_read_line(file);
	if (!ft_get_field_description(field_char,
			  description_line, ft_strlen(description_line)))
		return (0);
	field_char->arr = (char **) malloc(field_char->row_count * sizeof(char *));
	field_char->arr[0] = ft_read_first_field_line(file);
	field_char->col_count = ft_strlen(field_char->arr[0]);
	i = 1;
	while (i < field_char->row_count)
	{
		field_char->arr[i] = ft_read_field_line(file, field_char->col_count);
		if (!field_char->arr[i])
			return (0);
		i++;
	}
	if (!ft_check_field_char(field_char))
		return (0);
	return (1);
}
