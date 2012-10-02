// SudokuSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>


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

	std::wstring input_file(argv[1]);

	FILE *pFile;
	
	errno_t error = _tfopen_s(&pFile, input_file.c_str(), L"r");

	if (error != 0)
	{
		_tprintf(_TEXT("ERROR: invalid file"));
#if _DEBUG
		__debugbreak();
#endif
		return 2;
	}

	// 9x9 with newlines on the first 8 rows
	TCHAR buffer[10*9];

	size_t count = fread(buffer, sizeof(TCHAR), 10*9-2, pFile);

	buffer[88] = '\0';

	_tprintf(_TEXT("%s"), buffer);

	SolveSodoku(buffer);

	fclose(pFile);

#if _DEBUG
		__debugbreak();
#endif

	return 0;
}

void SolveSodoku(TCHAR *buffer)
{

}