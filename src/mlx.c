#include <mlx.h>
#include <stdlib.h>

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

int main()
{
	t_mlx_info	mlx_info;

	mlx_info.mlx_ptr = mlx_init();
	mlx_info.win_ptr = mlx_new_window(mlx_info.mlx_ptr, 1080, 720, "hello world!");
	
	mlx_info.i = 0;
	mlx_key_hook(mlx_info.win_ptr, key_deal, &mlx_info);
	
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}
