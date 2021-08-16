#include "ft_field_char.h"

t_field_char	*ft_create_field_char(void)
{
	t_field_char	*field_char;

	field_char = (t_field_char *) malloc(sizeof(t_field_char));
	if (!field_char)
	{
		field_char->row_count = 0;
		field_char->col_count = 0;
		field_char->arr = (char **)0;
		field_char->empty_symb = '\0';
		field_char->obstacle_symb = '\0';
		field_char->full_symb = '\0';
	}
	return (field_char);
}

void	ft_print_field_with_square(t_field_char *field, t_square square)
{
	int	i;
	int	j;

	i = 0;
	while (i < field->row_count)
	{
		j = 0;
		while (j < field->col_count)
		{
			if (i >= square.row_index && i < square.row_index + square.size
				&& j >= square.col_index && j < square.col_index + square.size)
				write(1, &field->full_symb, 1);
			else
				write(1, &field->arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_check_field_char(t_field_char *field)
{
	int	i;
	int	j;

	if (field->empty_symb <= 32 || field->empty_symb == 127)
		return (0);
	if (field->obstacle_symb <= 32 || field->obstacle_symb == 127)
		return (0);
	if (field->row_count < 1 && field->col_count < 1)
		return (0);
	i = 0;
	while (i != field->row_count)
	{
		j = 0;
		while (j != field->col_count)
		{
			if (field->arr[i][j] != field->empty_symb &&
				field->arr[i][j] != field->obstacle_symb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_field_char(t_field_char	*field)
{
	int	i;

	if (!field)
		return ;
	i = 0;
	if (field->arr)
	{
		while (i < field->row_count)
		{
			if (!field->arr[i])
				break ;
			free(field->arr[i]);
			i++;
		}
		free(field->arr);
	}
	free(field);
}
