#include "miniRT.h"

void	*mlx_ptr;
void	*win_ptr;

int	press_esc_key(int key)
{
	if (key == 0xFF1B)
		exit(0);
	return (0);
}

int main()
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	mlx_key_hook(win_ptr, press_esc_key, win_ptr);
	mlx_loop(mlx_ptr);
}