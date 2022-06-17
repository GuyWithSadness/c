#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int whatthefuck(char **map, int rows, int col);
void printmap(char **map, int rows, int column);
void replaceisland(char **map, int i, int j, int num_islands, int col, int row);

int main(int ac, char **av)
{
	// find a way to replace fopen fclose fgetc
	char **map;
	int x;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}


	x = open(av[1], O_RDONLY);
	if (x == -1)
	{
		write(1, "\n", 1);
		return 0;
	}

	char buff[1];
	int column, totalnum, rows, check, expectednum;
	rows = 0;
	totalnum = 0;
	// calculate number of rows and columns
	while (1)
	{
		check = read(x, buff, 1);
		if ( check ==  0 )
			break;
		if (buff[0] != '\n' && buff[0] != '.' && buff[0] != 'X' && buff[0] != 13)
			{
				write(1, "\n", 1);
				return 0;
			}
		else {
			if ( buff[0] == '\n' ) {
				if (rows == 0)
					expectednum = totalnum;
				else if (expectednum != totalnum)
				{
					write(1, "\n", 1);
					return 0;
				}
				totalnum = 0;
				rows++;
				continue;
			}
			else if (buff[0] == 13)
				continue;
			else
				totalnum++;
		}
	}

	if (expectednum > 1024)
	{
		write(1, "\n", 1);
		return 0;
	}
	column = expectednum;

	int i, j;
	close(x);
	// Allocating memory
	map = (char **) malloc ((rows) * sizeof(char *));
	if (map == NULL)
	{
		write(1, "\n", 1);
		return 0;
	}

	for (i = 0; i < rows; i++)
	{
		map[i] = (char *) malloc ((column + 1) * sizeof(char));
		if (map == NULL)
		{
			write(1, "\n", 1);
			return 0;
		}
	}

	i = 0;
	j = 0;
	column = column + 1;

	x = open(av[1], O_RDONLY);
	// copy the map from the example.txt to our code for our personal use
	while (1)
	{
		check = read(x, buff, 1);
		if ( check ==  0 )
			break;
		if ( buff[0] == '\n'){
			map[j][i] = buff[0];
			i = 0;
			j++;
			continue;
		}
		else if (buff[0] == 13)
			continue;
		map[j][i] = buff[0];
		i++;
	}
	close(x);

	whatthefuck(map, rows, column);
	write(1, "\n", 1);
	return 0;
}

int whatthefuck(char **map, int rows, int col)
{
	int i, j, num_islands;

	num_islands = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < col; j++)
			if (map[i][j] == 'X')
			{
				replaceisland(map, i, j, num_islands, col, rows);
				num_islands++;
				if (num_islands == 10);
				{
					return 1;
				}
			}
	printmap(map, rows, col);
	return 0;
}

void replaceisland(char **map, int i, int j, int num_islands, int col, int row)
{
	if (map[i][j] == 'X')
		map[i][j] = num_islands + '0';
	// check right
	if ((j + 1) < col && map[i][j + 1] == 'X')
		replaceisland(map, i, j+1, num_islands, col, row);
	// check left
	if ((j - 1) >= 0 && map[i][j - 1] == 'X')
		replaceisland(map, i, j-1, num_islands, col, row);
	// check down
	if ((i + 1) < row && map[i + 1][j] == 'X')
		replaceisland(map, i + 1, j, num_islands, col, row);
	// check up
	if ((i - 1) >= 0 && map[i - 1][j] == 'X')
		replaceisland(map, i -1 , j, num_islands, col, row);
}

void printmap(char **map, int rows, int column)
{
	int i, j;

	i = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < column; j++)
			write(1, &map[i][j], 1);
}
