	if (scroll >= 0 && scroll <= frequency)
	{
		pos.y = 4;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency && scroll <= frequency * 2)
	{
		pos.y = 8;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 2 && scroll <= frequency * 3)
	{
		pos.y = 12;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 3 && scroll <= frequency * 4)
	{
		pos.y = 16;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 4 && scroll <= frequency * 5)
	{
		pos.y = 20;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 5 && scroll <= frequency * 6)
	{
		pos.y = 24;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 6 && scroll <= frequency * 7)
	{
		pos.y = 28;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 7 && scroll <= frequency * 8)
	{
		pos.y = 32;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 8 && scroll <= frequency * 9)
	{
		pos.y = 36;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 9 && scroll <= frequency * 10)
	{
		pos.y = 40;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 10 && scroll <= frequency * 11)
	{
		pos.y = 44;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 11 && scroll <= frequency * 12)
	{
		pos.y = 48;
		draw(&game->render, &game->bar, pos, MENU);
	}
