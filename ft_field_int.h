#ifndef FT_FIELD_INT_H
# define FT_FIELD_INT_H
# include <stdlib.h>
# include "ft_field_char.h"
# include "ft_square.h"

typedef struct s_field
{
	int		row_count;
	int		col_count;
	int		**arr;
}	t_field;

t_field	*ft_get_empty_field(int row_count, int col_count);
void	ft_print_field_int(t_field *field);
t_field	*ft_get_field_int(t_field_char	*field_char);
void	ft_free_field_int(t_field	*field);
#endif