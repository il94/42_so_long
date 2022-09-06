<p align="center">
	<img src="https://zupimages.net/up/22/36/mqgn.png">
</p>

<h1 align="center">
	Description
</h1>
<p align="center">
	This is a 42 School's project. The project consist to create a little 2D game with the MiniLibX, the school graphic library.
</p>

<h2 align="center">
	The Game
</h2>
<p align="center">
	The purpose of the game is to collect all collectibles of the level, while avoiding ennemy attacks. You can beat them by jumping on them, or hitting them with your hammer losted in map. The least contact can loose you the game, so be careful !
</p>

<h2 align="center">
	Commands
</h2>
<table>
	<tr>
		<td align="center"><code>W</code><br>Moving up</td>
		<td align="center"><code>A</code><br>Moving left</td>
		<td align="center"><code>S</code><br>Moving down</td>
		<td align="center"><code>D</code><br>Moving right</td>
		<td align="center"><code>SPACE</code><br>Hammer blow in the direction of the player (bottom excluded)</td>
		<td align="center"><code>SPACE+S</code><br>Jump</td>
		<td align="center"><code>TAB</code><br>Display step counter</td>
		<td align="center"><code>ESC</code><br>Close the game</td>
	</tr>
</table>

<h2 align="center">
	Installation
</h2>

```bash
sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
sudo apt-get install vlc
git clone https://github.com/il94/42_so_long so_long
cd so_long && make -j
```

<h2 align="center">
	Running Game
</h2>

```bash
./so_long [MAP.ber]
```

<p align="center">
	A map set is provided in "maps" folder. I challenge you to complete my levels (the world 4 in particular :) ).
</p>

<h2 align="center">
	Map Composition
</h2>
<table align="center">
	<tr>
		<td>
			<h3 align="center">
				Valid Characters
			</h3>
			<table align="center">
				<tr>
					<td align="center">Character</td><td align="center">Element</td>
				</tr>
				<tr>
					<td align="center"><code>0</code></td><td align="center">Grass</td>
				</tr>
				<tr>
					<td align="center"><code>1</code></td><td align="center">Wall</td>
				</tr>
				<tr>
					<td align="center"><code>C</code></td><td align="center">Collectible</td>
				</tr>
				<tr>
					<td align="center"><code>E</code></td><td align="center">Exit Door</td>
				</tr>
				<tr>
					<td align="center"><code>P</code></td><td align="center">Starting Position</td>
				</tr>
				<tr>
					<td align="center"><code>M</code></td><td align="center">Enemy</td>
				</tr>
				<tr>
					<td align="center"><code>H</code></td><td align="center">Hammer</td>
				</tr>
			</table>
		</td>
		<td>
			<table align="center">
				<h3 align="center">
					Map Example
				</h3>
				<tr>
					<td><br><br>
						<pre align="center">
111111111
111000111
1PH0C00E1
1110M0111
111111111</pre><br><br>
						<p align="center">
							<i>Content .ber file</i>
						</p>
					</td>
					<td>
						<img src="https://zupimages.net/up/22/36/wp6g.png">
						<p align="center">
							<i>Render in game</i>
						</p>
					</td>
				</tr>
			</table>
		</td>
	</tr>
</table>

<p>
	To be valid, a map must meet the following conditions :
	<ul>
		<li>be rectangular</li>
		<li>surrounded by walls</li>
		<li>contain only one starting position</li>
		<li>contain only one exit door</li>
		<li>contain at least one collectible</li>
		<li>contain a maximum of one hammer</li>
		<libe composed by only valid characters</li>
		<li>the file contain map must be at .ber format</li>
	</ul>
</p>
<p>
	By respecting the above conditions, you can create your own maps !
</p>

<h2 align="center">
	Informations
</h2>
<p align="center">
	Being free to choose game's sprites, I chose to use the ones from the games I grew up with, namely the Mario licence during the years 90s and 2000s, especially Paper Mario 64. It's the same for sounds, added as a bonus and the little references hidden everywhere in game. Being my first game, and my first graphical project, it seemed natural to me to make this game a tribute to these games that made me love the world of video games, and which gave me the desire to create some in my turn.
</p>
