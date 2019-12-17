#include "gtest.h"
#include "Monom.h"
#include "List.h"
#include "Polinom.h"

TEST(Monom, can_create_monom1) {
	string a = "3*x^2*y^3*z^2";
	Monom b(a);
	EXPECT_EQ(b.coeff, 3);
}

TEST(Monom, can_create_monom2) {
	string a = "x^2*y^3*z^2";
	Monom b(a);
	EXPECT_EQ(b.coeff, 1);
}

TEST(Monom, can_create_monom3) {
	string a = "x^2*y^3*z^2";
	Monom b(a);
	EXPECT_EQ(b.deg, 232);
}
TEST(Monom, can_create_monom4) {
	string a = "x^2*z^2";
	Monom b(a);
	EXPECT_EQ(b.deg, 202);
}

TEST(Monom, can_create_monom5) {
	string a = "1";
	Monom b(a);
	EXPECT_EQ(b.deg, 0);
}

TEST(List, can_push_el1)
{
	List<Monom> s;
	Iterator<Monom> i(s.Head());
	string a = "x^2*y^3*z^2";
	string b = "x^3*y^3*z^2";
	Monom am(a);
	Monom bm(b);
	s.Push(am);
	s.Push(bm);
	i++;
	EXPECT_EQ((*i).deg,232);
}

TEST(List, can_push_el2)
{
	List<Monom> s;
	Iterator<Monom> i(s.Head());
	string a = "x^2*y^3*z^2";
	string b = "x^3*y^3*z^2";
	Monom am(a);
	Monom bm(b);
	s.Push(bm);
	s.Push(am);
	i++;
	EXPECT_EQ((*i).deg, 232);
}

TEST(List, can_push_el3)
{
	List<Monom> s;
	Iterator<Monom> i(s.Head());
	string a = "x^2";
	string b = "x^2";
	Monom am(a);
	Monom bm(b);
	s.Push(bm);
	s.Push(am);
	i++;
	EXPECT_EQ((*i).coeff, 2);
}

TEST(Polinom, right_infix1) {
	string a = "2*x^1";
	Polinom b;
	EXPECT_TRUE(b.Check(a));
}

TEST(Polinom, right_infix2) {
	string a = "x^2*y^3*z^4";
	Polinom b;
	EXPECT_TRUE(b.Check(a));

}

TEST(Polinom, right_infix3) {
	string a = "1";
	Polinom b;
	EXPECT_TRUE(b.Check(a));
}

TEST(Polinom, right_infix4) {
	string a = "-x^2+x^2*y^3-z^1";
	Polinom b;
	EXPECT_TRUE(b.Check(a));
}

TEST(Polinom, wrong_infix1) {
	string a = "x^22";
	Polinom b;
	EXPECT_TRUE(!(b.Check(a)));
}

TEST(Polinom, wrong_infix2) {
	string a = "y^3*x^2";
	Polinom b;
	EXPECT_TRUE(!(b.Check(a)));
}

TEST(Polinom, wrong_infix3) {
	string a = "x^2+y";
	Polinom b;
	EXPECT_TRUE(!(b.Check(a)));
}

TEST(Polinom, get_elem) {
	string a = "x^2";
	Monom b(a);
	Polinom c;
	c.Push(b);
	EXPECT_EQ(c.GetMon(1).deg, 200);
}

TEST(Polinom, to_polinom1) {
	string a = "x^2+y^1";
	Polinom b;
	b.toPolinom(a);
	EXPECT_EQ(b.GetMon(1).deg,10);
}

TEST(Polinom, to_polinom2) {
	string a = "x^2-y^1";
	Polinom b;
	b.toPolinom(a);
	EXPECT_EQ(b.GetMon(1).coeff, -1);
}

TEST(Polinom, plus1) {
	string a = "x^2";
	string aa = "x^2";
	Polinom b;
	Polinom bb;
	Polinom res;
	b.toPolinom(a);
	bb.toPolinom(aa);
	res = b + bb;
	EXPECT_EQ(res.GetMon(1).coeff, 2);
}

TEST(Polinom, plus2) {
	string a = "x^2";
	string aa = "x^3*y^2";
	Polinom b;
	Polinom bb;
	Polinom res;
	b.toPolinom(a);
	bb.toPolinom(aa);
	res = b + bb;
	EXPECT_EQ(res.GetMon(2).deg, 320);
}

TEST(Polinom, mult1) {
	string a = "x^2";
	string aa = "x^2";
	Polinom b;
	Polinom bb;
	Polinom res;
	b.toPolinom(a);
	bb.toPolinom(aa);
	res = b * bb;
	EXPECT_EQ(res.GetMon(1).deg, 400);
}

TEST(Polinom, mult2) {
	string a = "x^3*y^2";
	string aa = "x^2";
	Polinom b;
	Polinom bb;
	Polinom res;
	b.toPolinom(a);
	bb.toPolinom(aa);
	res = b * bb;
	EXPECT_EQ(res.GetMon(1).deg, 520);
}
