#include <iostream>
#include <string>
#include <vector>

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;

	// TODO: store the data
	// hints: you can use std::string, std::vectors + string, char**, vector<vector<char>>, etc
	std::vector<std::vector<char>> matrix;
public:
	Matrix(size_t numColumnsX, size_t numLinesY) : column_count(numColumnsX), line_count(numLinesY)
		// TODO: add functionality
	{
		matrix.resize(line_count);
		for (int line = 0; line < line_count; line++)
		{
			matrix[line].resize(column_count);
		}
		// TODO: add functionality
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		std::vector<char> newMatrixLine(data.begin(), data.end());
		matrix[line_number] = newMatrixLine;
	}

	//OPTIONAL
	//char getCellXY(size_t x, size_t y, char cell_content)
	//{
	//	// TODO: add functionality
	//	return 0;
	//}

	char getCellXY(size_t x, size_t y, char cell_content)
	{
		if (y >= line_count)
		{
			return -1;
		}

		if (x < 0)
		{
			return -1;
		}

		if (x >= column_count)
		{
			return -1;
		}

		if (y < 0)
		{
			return -1;
		}

		cell_content = matrix[y][x];
		return 0;
	}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		// TODO: add functionality
		if (y >= line_count)
		{
			return;
		}

		if (x < 0)
		{
			return;
		}

		if (x >= column_count)
		{
			return;
		}

		if (y < 0)
		{
			return;
		}
		matrix[y][x] = cell_content;
	}

	void print()
	{
		// print all lines and columns
		// TODO: add functionality

		for (int line = 0; line < line_count; line++)
		{
			for (int column = 0; column < column_count; column++)
			{
				std::cout << matrix[line][column];
			}
			std::cout << "\n";
		}
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(3, 7, 'O');
	matrix.print();
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--	
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');
	return 0;
}