//This is HugeInt.CPP

#include"HugeInt.h"

HugeInt::HugeInt() {
	for (int i = 0; i < 200; i++)
		BIG[i] = 0;
}

HugeInt::HugeInt(int n) {
	for (int i = 0; i < 200; i++)
		BIG[i] = 0;
	int j = 0;
	while (n != 0) {
		BIG[j] = n% 10;
		n /= 10;
		j++;
	}
}

HugeInt::HugeInt(const char* n) {
	for (int i = 0; i < 200; i++)
		BIG[i] = 0;
	int len = strlen(n);
	for (int i = len - 1; i >= 0; --i)
		BIG[len - i - 1] = n[i] - '0';
}

HugeInt& HugeInt::operator=(const HugeInt& n) {
	for (int i = 0; i < 200; i++)
		BIG[i] = n.BIG[i];
		return *this;
}

HugeInt HugeInt::operator+(const HugeInt& n) {
	int i = 0;
	int carry = 0;
	HugeInt result;
	while (i < 200) {
		result.BIG[i] = BIG[i] + n.BIG[i] + carry;
		carry = result.BIG[i] / 10;
		result.BIG[i] %= 10;
		i++;
	}
		return result;
}

HugeInt HugeInt::operator-(const HugeInt& n) {
	int i = 0;
	int borrow = 0;
	HugeInt result;
	while (i < 200) {
		result.BIG[i] = BIG[i] - n.BIG[i] - borrow;
		if (result.BIG[i] < 0) {
			borrow = 1;
			result.BIG[i] += 10;
		}
		else
			borrow = 0;

		i++;
	}
		return result;
}

istream& operator >> (istream& in, HugeInt& n) {
	int temp[200] = { 0 };
	int k = 0;
	char pe;
	in.get(pe);
	while (pe != '\n') {
		temp[k] = pe - '0';
		in.get(pe);
		k++;
	}
	k--;
	int j = k;
	while (k >= 0) {
		n.BIG[k] = temp[0 + j - k];
		k--;
	}
		return in;
}

ostream& operator << (ostream& out, const HugeInt& n) {
	int i = 199;
	while (n.BIG[i] == 0)
		i--;
	if (i <= 0)
		out << 0;
	while (i >= 0) {
		out << n.BIG[i];
		i--;
	}
		return out;
}

