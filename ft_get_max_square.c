#include "ft_get_max_square.h"

int	ft_is_possible(t_field *field, int x, int y, int size)
{
	int	obs_count;

	obs_count = 0;
	if (x + size - 1 >= field->row_count || y + size - 1 >= field->col_count)
		return (0);
	if (x > 0 && y > 0)
		obs_count += field->arr[x - 1][y - 1];
	if (y + size - 1 < field->col_count && x > 0)
		obs_count -= field->arr[x - 1][y + size - 1];
	if (x + size - 1 < field->row_count && y > 0)
		obs_count -= field->arr[x + size - 1][y - 1];
	if (x + size - 1 < field->row_count && y + size - 1 < field->col_count)
		obs_count += field->arr[x + size - 1][y + size - 1];
	if (obs_count == 0)
		return (1);
	return (0);
}

t_square	ft_get_max_square(t_field *field)
{
	int			i;
	int			j;
	t_square	max_sqr;

	max_sqr.col_index = -1;
	max_sqr.row_index = -1;
	max_sqr.size = 0;
	i = 0;
	while (i < field->row_count)
	{
		j = 0;
		while (j < field->col_count)
		{
			while (ft_is_possible(field, i, j, max_sqr.size + 1))
			{
				max_sqr.size += 1;
				max_sqr.row_index = i;
				max_sqr.col_index = j;
			}
			j++;
		}
		i++;
	}
	return (max_sqr);
}
