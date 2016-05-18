#include <unistd.h>
#include <mlx.h> 
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_env
{
	void		*ptr;
	void		*win;
}			t_env;


int	main(void)
{
	t_env	*e;
	void	*img;
	char	*get_data_addr;
	int	*img_data;
	int	i;

	e = (t_env *)malloc(sizeof(t_env));
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, 800, 800, "42");
	img = mlx_new_image(e->ptr, 75, 50);
	img_data = (int *)malloc(sizeof(int) * 3);
	get_data_addr = mlx_get_data_addr(img, img_data, img_data + 1, img_data + 2);
	
	printf("bits_per_pixel = %d\nbits_per_line = %d\nendian = %d\n", img_data[0], img_data[1], img_data[2]);

	i = 0;
	while (i < 300 * 50)
	{
		get_data_addr[i] = 0xFF;
		i++;
	}	
	mlx_pixel_put(e->ptr, e->win, 19, 20, 0xFF0000);
	mlx_put_image_to_window(e->ptr, e->win, img, 20, 20);
	mlx_put_image_to_window(e->ptr, e->win, img, 188, 150);
	mlx_put_image_to_window(e->ptr, e->win, img, 400, 300);
	mlx_destroy_image(e->ptr, img);
	mlx_loop(e->ptr);
}
