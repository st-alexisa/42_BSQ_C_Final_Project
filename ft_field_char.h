#ifndef FT_FIELD_CHAR_H
# define FT_FIELD_CHAR_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_square.h"
# include "stdio.h"

typedef struct s_field_char
{
	int		row_count;
	int		col_count;
	char	empty_symb;
	char	obstacle_symb;
	char	full_symb;
	char	**arr;
}	t_field_char;

t_field_char	*ft_create_field_char(void);
void			ft_print_field_with_square(t_field_char *field,
					t_square square);
void			ft_free_field_char(t_field_char *field);
int				ft_check_field_char(t_field_char *field);
#endif