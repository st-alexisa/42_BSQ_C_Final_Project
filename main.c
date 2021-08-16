#include "ft_field_char.h"
#include "ft_reader.h"
#include "ft_field_int.h"
#include "ft_get_max_square.h"
#include <fcntl.h>

int	ft_standart_input(void);

void	ft_process_field(int file)
{
	t_field_char	*field_char;
	t_field			*field_int;
	t_square		square;

	square.size = 0;
	square.row_index = -1;
	square.col_index = -1;
	field_char = ft_create_field_char();
	field_int = ft_get_empty_field(0, 0);
	if (!ft_read_field_char(field_char, file))
		write(1, "map error\n", 10);
	else
	{
		field_int = ft_get_field_int(field_char);
		square = ft_get_max_square(field_int);
		ft_print_field_with_square(field_char, square);
		close(file);
	}
	if (field_int)
		ft_free_field_int(field_int);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			ft_process_field(open(argv[i], O_RDONLY));
			i++;
		}
	}
	if (argc == 1)
	{
		ft_process_field(ft_standart_input());
	}
	return (0);
}
