void	initialize_mlx(t_game *game, char *file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (0);
	get_data_map(file, &game->map, &game->max);
	game->win = mlx_new_window(game->mlx,
			game->max.x * CELL, game->max.y * CELL, "Paper sprites_mario");
	game->star_appeared = FALSE;
	game->get_hammer = FALSE;
	game->bar_displayed = FALSE;
	game->enemy_index = 0;
	game->coin_count = 0;
	read_all_map(game, "CM", get_elements_count);
	printf("coins = %d | ennemies = %d\n", game->coin_count, game->enemy_count);
	read_map(game, "P", &get_player_position);
	game->player_direction = 'P';
	game->player_state = 0;
	game->player_steps = 0;
	game->max_player_steps = FALSE;
	game->player_animation_speed = 12;
	game->is_hitting = FALSE;
	game->is_jumping = FALSE;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
	game->enemies = malloc(game->enemy_count * sizeof(t_data));
	read_all_map(game, "M", &get_enemies_data);
	game->state_enemy = 0;
	game->speed_animation_enemy = 200;
	if (!game->win)
		exit (0);

	// game->sprites_collectibles[5].pos = 
	get_all_images(game);
	get_all_addresses(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, run_game, game);
	mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	system("cvlc sound/march_ahead.wav &");
	mlx_loop(game->mlx);
}


int	enemy_sprite_can_move(t_game *game, t_pos pos_trgt, char code, int i)
{
	int	is_obstacle;

	is_obstacle = is(ENEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x]);
	if ((game->enemies[i].pos.y * CELL < game->enemies[i].cell.y - CELL / 2
			|| !is_obstacle) && code == 'U')
		return (1);
	else if ((game->enemies[i].pos.x * CELL >= game->enemies[i].cell.x - CELL / 2
			|| !is_obstacle) && code == 'R')
		return (1);
	else if ((game->enemies[i].pos.y * CELL > game->enemies[i].cell.y - CELL / 2
			|| !is_obstacle) && code == 'D')
		return (1);
	else if ((game->enemies[i].pos.x * CELL <= game->enemies[i].cell.x - CELL / 2
			|| !is_obstacle) && code == 'L')
		return (1);
	return (0);
}

int	enemy_position_can_move(t_game *game, t_pos pos_trgt, char code, int i) // a ajuster pour bug collision
{
	if (!is(ENEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x]))
	{
		if (code == 'U'
			&& game->enemies[i].cell.y / CELL < game->enemies[i].pos.y)
			return (1);
		else if (code == 'R'
			&& game->enemies[i].cell.x > game->enemies[i].pos.x * CELL + (CELL / 3) + CELL)
			return (1);
		else if (code == 'D'
			&& game->enemies[i].cell.y / CELL > game->enemies[i].pos.y)
			return (1);
		else if (code == 'L'
			&& game->enemies[i].cell.x < game->enemies[i].pos.x * CELL + (CELL / 3))
			return (1);
	}
	return (0);
}