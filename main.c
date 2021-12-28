#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
int main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char *str;

	while ((str = get_next_line(fd)) != NULL)
	{
		printf("result:%s", str);
	}
	printf("last:%s", str);

	return (0);
}