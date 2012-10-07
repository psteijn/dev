// SudokuSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TSodokuBoard.h"

void SolveSodoku(TCHAR *);

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 2)
	{
		_tprintf(_TEXT("usage:\n\tSdkSolv.exe <input.sok>\n\n\tinput.sok is a txt file with 9 lines of 9 characters {0-9,' '} depicting the soduku puzzle"));
#if _DEBUG
		__debugbreak();
#endif
		return 1;
	}

	std::string input_file(argv[1]);

	FILE *pFile;
	
	errno_t error = _tfopen_s(&pFile, input_file.c_str(), _TEXT("r"));

	if (error != 0)
	{
		_tprintf(_TEXT("ERROR: invalid file"));
#if _DEBUG
		__debugbreak();
#endif
		return 2;
	}

	TSodokuBoard tsb(pFile);

	tsb.PrintBoard();

	fclose(pFile);

	tsb.Solve();

	tsb.PrintBoard();
	
#if _DEBUG
		__debugbreak();
#endif

	return 0;
}

void SolveSodoku(TCHAR *buffer)
{

}