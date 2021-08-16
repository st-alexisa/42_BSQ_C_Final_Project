#ifndef STRING_FUNCTIONS_H
# define STRING_FUNCTIONS_H
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);
char	*ft_realloc(char *str, int *size);
#endif
