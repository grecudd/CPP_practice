#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <algorithm>

class GameOfLife {
	std::vector<std::vector<bool>> currentGeneration;
	std::vector<std::vector<bool>> nextGeneration;
	std::vector<std::vector<int>> directions = { {-1, -1},	{-1, 0},	{-1, 1},
													 {0, -1},		{0, 1},
													 {1, -1},	{1, 0},		{1, 1} };
	int rows;
	int cols;
public:
	GameOfLife(int rows, int cols) : rows(rows), cols(cols)
	{
		currentGeneration.resize(rows);
		nextGeneration.resize(rows);

		srand(time(NULL));

		for (int i = 0; i < rows; i++)
		{
			currentGeneration[i].resize(cols);
			nextGeneration[i].resize(cols);

			for (int j = 0; j < cols; j++)
			{
				currentGeneration[i][j] = rand() % 2;
			}
		}
	}

	void printMatrix()
	{
		Sleep(200);
		system("cls");
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (currentGeneration[i][j])
				{
					//std::cout << char(177);
					std::cout << " ";
				}
				else
				{
					std::cout << char(178);

				}
			}

			std::cout << "\n";
		}
	}

	int simulate()
	{
		int changes = 0;
		for (int i = 1; i < rows - 1; i++)
		{
			for (int j = 1; j < cols - 1; j++)
			{
				int neighbors = 0;

				for (int x = -1; x < 2; x++)
				{
					for (int y = -1; y < 2; y++)
					{
						neighbors += currentGeneration[i + x][j + y];
					}
				}
				neighbors -= currentGeneration[i][j];

				int currentState = currentGeneration[i][j];

				if (!currentState && neighbors == 3)
				{
					nextGeneration[i][j] = 1;
					changes++;
				}
				else if (currentState && (neighbors < 2 || neighbors > 3))
				{
					nextGeneration[i][j] = 0;
					changes++;
				}
				else
				{
					nextGeneration[i][j] = currentState;
				}
			}
		}

		currentGeneration = nextGeneration;
		printMatrix();
		return changes;
	}
};

int main()
{
	GameOfLife gameOfLife(25, 25);

	int changes = 0;
	int sameChanges = 0;
	int generation = 1;
	for (; sameChanges < 10; generation++)
	{
		int noOfChanges = gameOfLife.simulate();
		if (noOfChanges == changes)
		{
			sameChanges++;
		}
		else
		{
			sameChanges = 0;
			changes = noOfChanges;
		}
	}

	std::cout << "Stopped at generation : " << generation;
	return 0;
}