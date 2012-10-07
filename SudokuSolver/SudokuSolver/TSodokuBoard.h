#pragma once

#include "TSodokuCell.h"

class TSodokuBoard
{
public:
	TSodokuBoard(FILE *pFile);
	~TSodokuBoard(void);

	// output methods
	void PrintBoard();

	void Solve();
	bool isSolved();

private:
	std::vector<TSodokuCell> myBoard;

	// algorithm methods
	TSodokuCell &operator[](int pos);
};

