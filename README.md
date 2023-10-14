<p align="center">
	<img src="https://i.goopics.net/34onfv.gif">
</p>

<h1 align="center">
	Description
</h1>
<p align="center">
	This is a 42 School project. It consists in creating a little 2D game with the MiniLibX, the school's graphic library.
</p>

<h2 align="center">
	The game
</h2>
<p align="center">
	The purpose of the game is to obtain every collectible of the level, while avoiding ennemy attacks. You can beat the ennemies either by jumping on them or by hitting them with your hammer lost in the map. The tiniest contact can loose you the game, so be careful !
</p>

<h2 align="center">
	Commands
</h2>
<table>
	<tr>
		<td align="center"><code>W</code><br>Move up</td>
		<td align="center"><code>A</code><br>Move left</td>
		<td align="center"><code>S</code><br>Move down</td>
		<td align="center"><code>D</code><br>Move right</td>
		<td align="center"><code>SPACE</code><br>Hammer blow (bottom excluded)</td>
		<td align="center"><code>SPACE+S</code><br>Jump</td>
		<td align="center"><code>TAB</code><br>Display step counter</td>
		<td align="center"><code>ESC</code><br>Close game</td>
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
	Running game
</h2>

```bash
./so_long [MAP.ber]
```

<p align="center">
	A map set is provided in the "maps" folder. I challenge you to complete my levels (the world 4 in particular :) ).
</p>

<h2 align="center">
	Map composition
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
					<td align="center"><code>E</code></td><td align="center">Exit</td>
				</tr>
				<tr>
					<td align="center"><code>P</code></td><td align="center">Starting position</td>
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
					Map example
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
						<img src="https://i.goopics.net/uc1ily.png">
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
		<li>being rectangular</li>
		<li>being surrounded by walls</li>
		<li>containing only one starting position</li>
		<li>containing only one exit</li>
		<li>containing at least one collectible</li>
		<li>containing a maximum of one hammer</li>
		<li>being composed only by valid characters</li>
		<li>the file containing map must be .ber</li>
	</ul>
</p>
<p>
	By respecting the above conditions, you can create your own maps !
</p>

<h2 align="center">
	Informations
</h2>
<p align="center">
	Being free to choose my own sprites, I used the ones from games I grew up with, namely the Mario license from the 90s and 2000s, and especially here Paper Mario 64. The same goes for sounds, added as a bonus, and the Easter eggs that can be found in the different levels. With it being my first game as well as my first graphical project, it seemed natural to me to make it a tribute to the ones that made me love the world of video games and gave me the desire to create some of my own.
</p>
