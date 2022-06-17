#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void whatthefuck(char **map, int rows, int col);
void printmap(char **map, int rows, int column);
void replaceisland(char **map, int i, int j, int num_islands, int col, int row);

int main(int ac, char **av)
{
	// find a way to replace fopen fclose fgetc
	FILE *fp;
	char **map;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}

	fp = fopen(av[1], "r");

	if (fp == NULL)
	{
		printf("We cannot open that file\n");
		write(1, "\n", 1);
		return 0;
	}

	char buff;
	int column, totalnum, rows;
	rows = 0;
	totalnum = 0;

	// calculate number of rows and columns

	printf("The map in the file:\n");
	while (1)
	{
		buff = fgetc(fp);
		if ( buff ==  EOF )
			break;
		printf("%c", buff);
		if ( buff == '\n' ){
			rows++;
			continue;
		}
		else if (buff == 13)
			continue;
		totalnum++;
	}

	printf("\n\nTotal number of valid elements = %d\n", totalnum);
	column = totalnum/rows;
	printf("Rows = %d, Cols = %d\n\n\n", rows, column);

	int i, j;
	fclose(fp);

	// Allocating memory

	printf("Duplicating map...\n\n");
	map = (char **) malloc ((rows) * sizeof(char *));
	if (map == NULL)
	{
		printf("Failed");
		return 0;
	}

	for (i = 0; i < rows; i++)
	{
		map[i] = (char *) malloc ((column + 1) * sizeof(char));
		if (map == NULL)
		{
			printf("Failed");
			return 0;
		}
	}

	i = 0;
	j = 0;
	column = column + 1;

	fp = fopen(av[1], "r");

	// copy the map from the example txt to our code for our personal use

	while (1)
	{
		buff = fgetc(fp);
		if ( buff ==  EOF )
			break;
		if ( buff == '\n'){
			map[j][i] = buff;
			i = 0;
			j++;
			continue;
		}
		else if (buff == 13)
			continue;
		map[j][i] = buff;
		i++;
	}

	fclose(fp);

	printf("Duplication done!\n");
	printf("Copy looks like this:\n\n");

	printmap(map, rows, column);
	printf("\nDoing the shit they want please wait....\n\n");
	whatthefuck(map, rows, column);
	return 0;
}

void whatthefuck(char **map, int rows, int col)
{
	int i, j, num_islands;

	num_islands = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < col; j++)
			if (map[i][j] == 'X')
			{
				replaceisland(map, i, j, num_islands, col, rows);
				num_islands++;
			}
	printmap(map, rows, col);
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
