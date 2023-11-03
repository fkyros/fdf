#include "../../inc/fdf.h"
#include <stdio.h>

void	map42()
{
	char *file = "../maps/42.fdf";

	proper_extension(file);
	int width = get_map_width(file);
	int height = get_map_height(file);
	printf("width = %d\n", width);
	printf("heigth = %d\n", height);
}

int main()
{
	map42();
	return (0);
}
