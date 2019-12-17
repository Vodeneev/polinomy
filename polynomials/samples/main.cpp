#include "Polinom.h"
#include "List.h"

int main() {
	string a = "x^2";
	string aa = "x^3*y^2";
	Polinom b;
	Polinom bb;
	Polinom res;
	b.toPolinom(a);
	bb.toPolinom(aa);
	res = b * bb;
}