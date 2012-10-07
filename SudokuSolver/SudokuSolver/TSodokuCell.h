#pragma once

class TSodokuCell
{
public:
	TSodokuCell(void);
	TSodokuCell(int val);
	~TSodokuCell(void);

	const std::vector<int> &GetCandidates();

	bool isSolved();
	int getSolvedValue();

	// remove all candidates but this value (read: this cell is solved)
	const std::vector<int> &operator=(int val);
	// remove one of the candidates from this cell
	const std::vector<int> &operator-=(int val);

	std::string ToString();

private:
std::vector<int> candidates;
};

