#include <mlx.h>
#include <stdlib.h>

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_info;

int key_deal(int key, t_mlx_info *mlx_info)
{
	if (key == )
}

int main()
{
	t_mlx_info	mlx_info;

	mlx_info.mlx_ptr = mlx_init();
	mlx_info.win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "hello world!");
	
	mlx_key_hook(win_ptr, key_deal, &mlx_info);
	
	mlx_loop(mlx_ptr);
	return (0);
}
