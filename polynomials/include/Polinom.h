#pragma once
#include "List.h"
class Polinom
{
	List<Monom> pol;
public:
	Polinom() {

	}
	Polinom(Polinom& a) {
		pol = a.pol;
	}
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
	bool Check(string infix) {
		int status = 0;
		int k = 0;
		int minus = 0;
		for (int i = 0; i < infix.size(); i++){
			if (status == 0) {
				if (IsNumber(infix[i]) & (k == 0))
					status = 1;
				else if (IsOperand(infix[i])) {
					if ((infix[i] == 'x') & (k == 0)) {
						k = 1;
						status = 5;
					}
					else if ((infix[i] == 'y') & (k != 2) & (k != 3)) {
						k = 2;
						status = 5;
					}
					else if ((infix[i] == 'z') & (k != 3)) {
						k = 3;
						status = 5;
					}
				}
				else if (infix[0]) {
						status = 0;
					}
				else
					status = 3;
			}
			else if (status == 1) {
				if (IsOperator(infix[i])) {
						status = 0;
				}
				else if (IsNumber(infix[i]) & IsNumber(infix[i - 1]))
					status = 1;
				else
					status = 3;
			}
			else if (status == 2) {
				if (IsNumber(infix[i]))
					status = 4;
				else
					status = 3;
			}
			else if (status == 4) {
				if (IsOperator(infix[i]))
					if (infix[i] != '*') {
						status = 0;
						k = 0;
					}
					else
						status = 0;
				else
					status = 3;
			}
			else if (status == 5) {
				if (infix[i] == '^')
				status = 2;
				else
					status = 3;
			}
		}
		if (status == 1 || status == 4)
			return true;
		else
			return false;
	}
	Monom GetMon(int i) {
		int k = 0;
		Iterator<Monom> it = pol.begin();
		while (k < i) {
			it++;
			k++;
		}
		return *it;
	}
	void Push(Monom a) {
		pol.Push(a);
	}
	void toPolinom(string infix) {
		int k = 0;
		string mon;
		for (int i = 0; i < infix.size(); i++) {
			if((infix[i] == '+') & (k == 0)){
				Monom op(mon);
				pol.Push(op);
				mon = "";
				k = 0;
			}
			else if ((infix[i] == '+') & (k == 1)) {
				Monom op(mon);
				op.Minus();
				pol.Push(op);
				mon = "";
				k = 0;
			}
			else if ((infix[i] == '-') & (k == 0)) {
				Monom op(mon);
				pol.Push(op);
				mon = "";
				k = 1;
			}
			else if ((infix[i] == '-') & (k == 1)) {
				Monom op(mon);
				op.Minus();
				pol.Push(op);
				mon = "";
				k = 1;
			}
			else {
				mon += infix[i];
			}
		}
		if (k == 0) {
			Monom op(mon);
			pol.Push(op);
		}
		else {
			Monom op(mon);
			op.Minus();
			pol.Push(op);
		}
	}
	Polinom& operator=(Polinom& a) {
		pol = a.pol;
		return *this;
	}
	Polinom operator+(Polinom a) {
		Polinom res;
		res.pol.change_head_coeff(a.pol.Head()->data.coeff + pol.Head()->data.coeff);
		Iterator<Monom> i(pol.Head()->next);
		Iterator<Monom> k(a.pol.Head()->next);
	
		while(i != NULL & k != NULL)
		{
			if ((*i).deg < (*k).deg) {
				res.Push(*i);
				i++;
			}
			else if ((*i).deg == (*k).deg) {
				Monom op;
				op.coeff = (*i).coeff + (*k).coeff;
				op.deg = (*i).deg;
				res.Push(op);
				i++;
				k++;
			}
			else {
				res.Push(*k);
				k++;
			}
		}
		if(k == NULL)
			while (i != NULL) {
				res.Push(*i);
				i++;
			}
		else
			while (k != NULL) {
				res.Push(*k);
				k++;
			}
		return res;
	}
	Polinom operator*(Polinom a) {
		Polinom res;
		Iterator<Monom> i(pol.Head());
		Iterator<Monom> k(a.pol.Head());
		while (i != NULL) {
			while (k != NULL) {
				Monom op;
				op.deg = (*i).deg + (*k).deg;
				op.coeff = (*i).coeff * (*k).coeff;
				res.Push(op);
				k++;
			}
			k = a.pol.Head();
			i++;
		}
		return res;
	}
	~Polinom(){}
};

