//This is HugeInt.h
#pragma once


#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

class HugeInt{

private:

	int BIG[200];

public:
	
	HugeInt();
	HugeInt(int a);
	HugeInt(const char* a);
	HugeInt& operator=(const HugeInt& a);
	HugeInt operator+(const HugeInt& a);
	HugeInt operator-(const HugeInt& a);
	friend istream& operator >> (istream& in, HugeInt& a);
	friend ostream& operator << (ostream& out, const HugeInt& a);

};

