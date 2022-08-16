int	key_press(int keycode, t_game *game)
{
	int			freq;
	static int	delay2;

	// print_elements(game);

	printf("x = %d, y = %d\n", game->cell.x, game->cell.y);
	freq = 9;
	if (!delay2)
		delay2 = 0;
	if (delay2 > 0)
		game->delay = 1;
	else
		game->delay = 0;
	if (keycode == KEY_W)
	{
		ft_print_array(game->map);
		delay2++;
		if (delay2 == 1)
			draw_image_s(game, &game->m_walk_left_b, game->player, 44 - 48);
		if (delay2 == 2)
			draw_image_s(game, &game->m_walk_left_b_2, game->player, 40 - 48);
		if (delay2 == 3)
			draw_image_s(game, &game->m_walk_left_b_3, game->player, 36 - 48);
		if (delay2 == 4)
			draw_image_s(game, &game->m_walk_left_b, game->player, 30 - 48);
		if (delay2 == 5)
			draw_image_s(game, &game->m_walk_left_b_2, game->player, 24 - 48);
		if (delay2 == 6)
			draw_image_s(game, &game->m_walk_left_b_3, game->player, 18 - 48);
		if (delay2 == 7)
			draw_image_s(game, &game->m_walk_left_b, game->player, 12 - 48);
		if (delay2 == 8)
			draw_image_s(game, &game->m_walk_left_b_2, game->player, 6 - 48);
		if (delay2 == 9)
			draw_image_s(game, &game->m_walk_left_b_3, game->player, 0 - 48);
		if (delay2 == freq)
		{
			if (is(PLAYER, game->map[game->player.y][game->player.x]) == 'a'
				|| is(PLAYER, game->map[game->player.y][game->player.x]) == 'A')
				move_player(game, game->player.y - 1, game->player.x, 'a');
			else
				move_player(game, game->player.y - 1, game->player.x, 'b');
			delay2 = 0;
		}
	}
	else if (keycode == KEY_D)
		move_player(game, game->player.y, game->player.x + 1, 'B');
	else if (keycode == KEY_S)
	{
		if (game->map[game->player.y][game->player.x] == 'a'
			|| game->map[game->player.y][game->player.x] == 'A')
			move_player(game, game->player.y + 1, game->player.x, 'A');
		else
			move_player(game, game->player.y + 1, game->player.x, 'B');
	}
	else if (keycode == KEY_A)
		move_player(game, game->player.y, game->player.x - 1, 'A');
	// else if (keycode == KEY_SPACE)
	// 	reboot_game(game);
	// else if (keycode == KEY_TAB)
	// 	reboot_game(game);
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

