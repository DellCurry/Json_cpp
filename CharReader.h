#pragma once
#include <string>
#include <iostream>
#include <string>
class CharReader
{
public:
	CharReader();
	CharReader(std::string& s);
	CharReader(CharReader& reader);
	~CharReader();
	char next();
	char peek();
	std::string next(int);
	bool hasMore();
	bool hasMore(int);
	void catchError(int);

private:
	std::string jsonStr;
	int pos;
	int size;

};
