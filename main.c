#include <unistd.h>
#include <mlx.h> 
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_env
{
	void		*ptr;
	void		*win;
}			t_env;


void	test(t_env *e)
{
	int	i;
	int	j;
	int	test;

	*((unsigned char *)&test + 1) = 0xFF;
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			mlx_pixel_put(e->ptr, e->win, 250 + i, 250 + j, test);
			j++;
		}
		i++;
	}
}


int	main(void)
{
	t_env	*e;
	void	*img;
	char	*get_data_addr;
	int	*img_data;
	int	i;
	unsigned char	b = 0;
	unsigned char	g = 1;
	unsigned char 	r = 2;

	e = (t_env *)malloc(sizeof(t_env));
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, 800, 800, "42");
	img = mlx_new_image(e->ptr, 75, 50);
	img_data = (int *)malloc(sizeof(int) * 3);
	get_data_addr = mlx_get_data_addr(img, img_data, img_data + 1, img_data + 2);
	
	printf("bits_per_pixel = %d\nbytes_per_line = %d\nendian = %d\n", img_data[0], img_data[1], img_data[2]);

	i = 0;
	while (i < 300 * 50)
	{
		get_data_addr[i + b] = 0xFF;
		get_data_addr[i + g] = 0x00;
		get_data_addr[i + r] = 0xFF;
		i += 4;
	}	
	mlx_put_image_to_window(e->ptr, e->win, img, 20, 20);
	mlx_put_image_to_window(e->ptr, e->win, img, 188, 150);
	mlx_put_image_to_window(e->ptr, e->win, img, 400, 300);
	test(e);
	mlx_loop(e->ptr);
}
