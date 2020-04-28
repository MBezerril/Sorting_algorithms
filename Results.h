#pragma once
class Results
{
public:
	int time = 0, swaps = 0, comparison = 0;
	Results();
	Results operator+=(const Results r) {
		this->comparison += r.comparison;
		this->swaps+= r.swaps;
	}
};

