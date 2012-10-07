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