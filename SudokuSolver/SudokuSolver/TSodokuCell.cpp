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
#include "TSodokuCell.h"

TSodokuCell::TSodokuCell(void)
{ 
	for(int i = 1; i <= 9; i++)
	{
		candidates.push_back(i); 
	}; 
}

TSodokuCell::TSodokuCell(int val)
{ 
	candidates.push_back(val); 
}


TSodokuCell::~TSodokuCell(void)
{ 

}

const std::vector<int> &TSodokuCell::operator=(int val)
{
	candidates.empty();
	candidates.push_back(val);

	return candidates;
}

const std::vector<int> &TSodokuCell::operator-=(int val)
{
	auto begin = candidates.begin();

	while(begin != candidates.end())
	{
		if(*begin == val)
		{
			if(candidates.size() == 1)
			{
				__debugbreak();
			}
			candidates.erase(begin);
			return candidates;
		}
		begin++;
	}

	return candidates;
}

const std::vector<int> &TSodokuCell::GetCandidates()
{
	return candidates;
};

std::string TSodokuCell::ToString()
{
    char buf[5];
	std::string buffer;

	if(candidates.size() == 1)
	{
		int val = candidates[0];
		sprintf_s(buf, "%d", val);
		buffer = buf;
	}
	else
		buffer = " ";

	return buffer;
}

bool TSodokuCell::isSolved()
{
	return candidates.size() == 1 ? true : false;
}

int TSodokuCell::getSolvedValue()
{
	if(!this->isSolved())
		return -1;

	return candidates[0];
}