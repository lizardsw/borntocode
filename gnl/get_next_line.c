#include <unistd.h>


#include <stdio.h>
#include <fcntl.h>

#define BUFF_SIZE 4




char *get_next_line(int fd)
{



	return 0;
}

int	main()
{
	int fd;
	char buff[BUFF_SIZE + 1];
	ssize_t len;

	fd = open("help.txt", O_RDONLY);
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = 0;
		printf("%s,", buff);
	}
	return 0;
}
