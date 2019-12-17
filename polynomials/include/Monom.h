#pragma once
#include "iostream"
#include "string"
using namespace std;
class Monom
{
public:
	int coeff;
	int deg = 0;
public:
	bool IsOperand(const char& opd)
	{
		const string alphabet = "xyz";

		if (alphabet.find(opd) != string::npos)
			return true;

		return false;
	}
	bool IsNumber(const char& opd)
	{
		const string numbers = "0123456789";

		if (numbers.find(opd) != string::npos)
			return true;

		return false;
	}

	int IsOperator(const char& op)
	{
		const string operPr1 = "+-*";
		if (operPr1.find(op) != string::npos)
			return 1;
		return 0;
	}
	Monom() {
		deg = 0;
		coeff = 0;
	}
	Monom(string a) {
		string res;
		string deg1, deg2, deg3;
		if (!(IsNumber(a[0])))
			coeff = 1;
		else {
			int i = 0;
			while (IsNumber(a[i])) {
				res += a[i];
				i++;
			}
			coeff = stoi(res);
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'x') {
				deg1 += a[i + 2];
				deg += 100 * stoi(deg1);
				i + 2;
			}
			else if (a[i] == 'y') {
				deg2 += a[i + 2];
				deg += 10 * stoi(deg2);
				i + 2;
			}
			else if (a[i] == 'z') {
				deg3 += a[i + 2];
				deg += stoi(deg3);
				i + 2;
			}
			else
				continue;
		}
	}
	void Minus() {
		coeff = coeff * (-1);
	}
};

