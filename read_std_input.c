#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>

int	ft_standart_input(void)
{
	int		rd;
	char	c;
	int		file;

	file = open("standart_input.txt", O_WRONLY);
	rd = 1;
	while (rd > 0)
	{
		rd = read(0, &c, 1);
		write(1, &c, 1);
	}
	if (rd < 0)
		  return (-1);
	return (file);
}
