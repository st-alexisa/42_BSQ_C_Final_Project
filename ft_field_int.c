#include "ft_field_int.h"

void	ft_print_field_int(t_field *field)
{
	int	i;
	int	j;

	i = 0;
	while (i < field->row_count)
	{
		j = 0;
		while (j < field->col_count)
		{
			printf("%d", field->arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_field	*ft_get_empty_field(int row_count, int col_count)
{
	int		i;
	t_field	*field_int;

	field_int = (t_field *) malloc(sizeof(t_field));
	if (field_int)
	{
		field_int->row_count = row_count;
		field_int->col_count = col_count;
		field_int->arr = (int **) malloc(sizeof(int *) * field_int->row_count);
		i = 0;
		while (i < field_int->row_count)
			field_int->arr[i++] = (int *) malloc(sizeof(int)
					* field_int->col_count);
	}
	return (field_int);
}

int	ft_get_obstacle_count(t_field *field, t_field_char
				*field_char, int x, int y)
{
	int	obs_count;

	obs_count = 0;
	if (field_char->arr[x][y] == field_char->obstacle_symb)
		obs_count++;
	if (x != 0)
		obs_count += field->arr[x - 1][y];
	if (y != 0)
		obs_count += field->arr[x][y - 1];
	if (x != 0 && y != 0)
		obs_count -= field->arr[x - 1][y - 1];
	return (obs_count);
}

t_field	*ft_get_field_int(t_field_char	*field_char)
{
	int		i;
	int		j;
	t_field	*field_int;

	field_int = ft_get_empty_field(field_char->row_count,
			field_char->col_count);
	i = 0;
	while (i < field_int->row_count)
	{
		j = 0;
		while (j < field_int->col_count)
		{
			field_int->arr[i][j] = ft_get_obstacle_count(field_int,
					field_char, i, j);
			j++;
		}
		i++;
	}
	return (field_int);
}

void	ft_free_field_int(t_field	*field)
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
