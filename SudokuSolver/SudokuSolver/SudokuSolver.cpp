/*

Copyright (C) 2012 Peter Klaas Steijn

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do 
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.

*/

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