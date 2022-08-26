#include "mini_paint1.h"

typedef struct s_info
{
	int	w;
	int	h;
	char	bg_c;
}	t_info;
t_info info;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	draw_c;
}	t_circle;

int	ft_strlen(char *s)
{
	int ret = 0;

	while (s[ret])
		ret++;
	return (ret);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	print_err()
{
	ft_putstr("Error: Operation file corrupted\n");
	return (1);
}

int	is_in_circle(float x, float y, t_circle *c)
{
	float dist;

	dist = sqrtf(powf(x - c->x, 2) + powf(y - c->y, 2));
	if (dist > c->r)
		return (0);
	if (dist > c->r - (float)1)
		return (2);
	return (1);
}

void	mini_paint(char **map, t_circle *c)
{
	int	i, j, ret;
	
	for (i = 0; i < info.h; i++)
	{
		for (j = 0; j < info.w; j++)
		{
			ret = is_in_circle(j, i, c);
			if ((ret == 2 && c->type == 'c') || (ret && c->type == 'C'))
				map[i][j] = c->draw_c;
		}
	}
}

void	print_map(char **map)
{
	int i, j;

	for (i = 0; i < info.h; i++)
	{
		for (j = 0; j < info.w; j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	FILE	*f;
	t_circle	c;
	char	**map;
	int	i, j, ret;

	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (print_err());
	if ((fscanf(f, "%d %d %c\n", &info.w, &info.h, &info.bg_c)) != 3)
		return (print_err());
	if (!(info.w > 0 && info.w <= 300 && info.h > 0 && info.h <= 300))
		return (print_err());
	map = malloc(sizeof(char *) * (info.h + 1));
	if (map == NULL)
		return (1);
	for (i = 0; i < info.h; i++)
	{
		map[i] = malloc(info.w + 1);
		if (map[i] == NULL)
			return (1);
		for (j = 0; j < info.w; j++)
			map[i][j] = info.bg_c;
		map[i][j] = 0;
	}
	map[i] = 0;
	while ((ret = fscanf(f, "%c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.r, &c.draw_c)) == 5)
	{
		if (!(c.r > (float)0 && (c.type == 'c' || c.type == 'C')))
			return (print_err());
		mini_paint(map, &c);
	}
	if (ret != -1)
		return (print_err());
	print_map(map);
	for (i = 0; i < info.h; i++)
		free(map[i]);
	free(map);
	fclose(f);

	return (0);
}