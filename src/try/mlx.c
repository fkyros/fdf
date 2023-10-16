#include "../inc/fdf.h"
#include "../inc/defines.h"

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
}	t_mlx_info;

int key_deal(int key, t_mlx_info *mlx_info)
{
	(void)key;
	mlx_pixel_put(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->i, mlx_info->i, 0x00FFFFFF);
	mlx_info->i++;
	return (0);
}

/**
 * dpk = decision parameter in k iteration -> used to make the decision of
 * 		 which point to plot in the next iteration
 */
void	bresenham_2d(int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	dpk;
	int k;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	dpk = (2 * dy) - dx;
	k = 0;
	while (k < dy)
	{
		k++;
	}
}

int main()
{
	t_mlx_info	mlx_info;

	mlx_info.mlx_ptr = mlx_init();
	mlx_info.win_ptr = mlx_new_window(mlx_info.mlx_ptr, 1080, 720, "hello world!");
	
	mlx_info.i = 0;
	mlx_key_hook(mlx_info.win_ptr, key_deal, &mlx_info);
	mlx_string_put(mlx_info.mlx_ptr, mlx_info.win_ptr, 50, 50, 0x00FFFFFF, "SEXO");
	mlx_string_put(mlx_info.mlx_ptr, mlx_info.win_ptr, 50, 70, 0x00FFFFFF, "POLLA");
	mlx_string_put(mlx_info.mlx_ptr, mlx_info.win_ptr, 50, 90, 0x00FFFFFF, "COJONES");
	mlx_string_put(mlx_info.mlx_ptr, mlx_info.win_ptr, 50, 150, 0x00FFFFFF, "WE LIVE");
	mlx_string_put(mlx_info.mlx_ptr, mlx_info.win_ptr, 50, 170, 0x00FFFFFF, "WE LOVE");
	mlx_string_put(mlx_info.mlx_ptr, mlx_info.win_ptr, 50, 190, 0x00EAEAEA, "WE LIE");
	
	mlx_loop(mlx_info.mlx_ptr);
}

void	main2()
{
	t_mlx	mlx;
	void	*img;
	char	*addr;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (L);
	mlx.win = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!mlx.win)
	{
		free(mlx.ptr);
		return (L);
	}

	mlx_string_put(mlx.ptr, mlx.win, 50, 50, 0x00FFFFFF, "SEXO");
	img = mlx_new_image(mlx.ptr, 100, 100);
	mlx_loop(mlx.ptr);
	//addr = mlx_get_data_addr(img, );
	mlx_put_image_to_window(mlx.ptr, mlx.win, img, 100, 100);

	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
}
