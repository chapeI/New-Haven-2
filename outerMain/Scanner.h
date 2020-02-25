#pragma once

#include <fstream>

class Scanner {

public:

	Scanner() = delete;
	Scanner(std::string);
	Scanner(Scanner&) = delete;
	~Scanner();
	bool hasNext();
	void consume(char, std::string);
	char nextChar();
	bool nextBool();
	int nextInt();

private:

	std::streampos* start;
	std::ifstream* stream;

	char advance();
	bool isDigit(char);
};
