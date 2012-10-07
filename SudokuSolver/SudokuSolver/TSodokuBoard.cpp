
#include "stdafx.h"
#include "TSodokuBoard.h"

TSodokuBoard::TSodokuBoard(FILE *pFile)
{
	// 9x9 with newlines on the first 8 rows
	TCHAR buffer[10*9];

	size_t count = fread(buffer, sizeof(TCHAR), 10*9, pFile);

	buffer[89] = '\0';

	TSodokuCell *temp;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(j == 9)
				continue;     // don't add the newline character to the board

			if(buffer[i*10+j] == _TEXT(' '))
				temp = new TSodokuCell();
			else
			{
				TCHAR buff[2];
				buff[0] = buffer[i*10+j];
				buff[1] = _TEXT('\0');

				int val = _tstoi(buff);

				temp = new TSodokuCell(val);
			}

			myBoard.push_back(*temp);
		}
	}
}


TSodokuBoard::~TSodokuBoard(void)
{
	// TODO -- get this to automatically destruct
	while(myBoard.size() != 0)
	{
		free(&(myBoard.back()));
		myBoard.pop_back();
	}
}

TSodokuCell &TSodokuBoard::operator [](int pos)
{
	return myBoard[pos];
}

void TSodokuBoard::PrintBoard()
{
	_tprintf(_TEXT("**BOARD STATE**\n"));

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			std::string buffer = myBoard[i*9 + j].ToString();
			_tprintf(_TEXT("%s"), buffer.c_str());
		}	
		_tprintf(_TEXT("\n"));
	}

	_tprintf(_TEXT("\n\n"));
};

bool TSodokuBoard::isSolved()
{
	auto begin = myBoard.begin();

	while(begin != myBoard.end())
	{
		if(begin->GetCandidates().size() != 1)
		{
			return false;
		}
		begin++;
	}

	return true;
}


void TSodokuBoard::Solve()
{
	while(!this->isSolved())
	{
		// for each cell, reduce the candidates based on the other items in that {row, cell, group}
		for(int row = 0; row < 9; row++)
		{
			for(int col = 0; col < 9; col++)
			{
				// if this cell is already solved then continue
				if(myBoard[row*9+col].isSolved())
				{
					continue;
				}

				// get all the solved items in this row and reduce those candidates
				for(int myrow = 0; myrow < 9; myrow++)
				{
					// break out if you have now solved this cell
					if(myBoard[row*9+col].isSolved())
						break;
					
					if(myBoard[myrow*9+col].isSolved())
					{
						myBoard[row*9+col] -= myBoard[myrow*9+col].getSolvedValue();
					}
				}

				// get all the solved items in this column and reduce those candidates
				for(int mycol = 0; mycol < 9; mycol++)
				{
					// break out if you have now solved this cell
					if(myBoard[row*9+col].isSolved())
						break;

					if(myBoard[row*9+mycol].isSolved())
					{
						myBoard[row*9+col] -= myBoard[row*9+mycol].getSolvedValue();
					}
				}

				// get all the solved items in this group and reduce those candidates
				for(int myrow = row / 3 * 3; myrow < (row / 3 + 1) * 3; myrow++)
				{
					for(int mycol = col / 3 * 3; mycol < (col / 3 + 1) * 3; mycol++)
					{
						// break out if you have now solved this cell
						if(myBoard[row*9+col].isSolved())
							break;

						if(myBoard[myrow*9+mycol].isSolved())
						{
							myBoard[row*9+col] -= myBoard[myrow*9+mycol].getSolvedValue();
						}
					}
				}
			}
		}

		this->PrintBoard();
	}
}