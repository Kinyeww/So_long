#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


void	So_Long(char* filename)
{
	char**	map;

	map = load_map(filename);
}

static int	counter(int fd)
{
	int	counts;
	char*	str;

	counts = 0;
	str = get_next_line
}

static char**	load_map(char* filename)
{
	char**	str;
	int	fd;
	int	lines;

	fd = open(filename, O_RDONLY);
	lines = counter(fd);
	str = get_next_line(fd);
}

int	main(void)
{
	if ((!So_Long("map.ber")))
	{
		ft_printf("error\n");
		return (1);
	}
	return (0);
}