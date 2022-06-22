#include "so_long.h"

t_param *init_param(t_map *map)
{
	t_param *new_param;

	new_param = (t_param *)malloc(sizeof(t_param));
	if (new_param == NULL)
		return (NULL); 
	new_param -> x = map -> locate[0];
	new_param -> y = map -> locate[1];
	return (new_param);
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;	
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d y: %d\n", param -> x, param -> y);
	return (0);
}

void	event_manage(void *window_ptr, t_param *param)
{
	mlx_key_hook(window_ptr, &key_hook, param);

}