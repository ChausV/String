#include "String.h"
#include <iostream>

// #include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;

void showStr(const String & s)
{
	cout << "Length: " << s.length();
	cout << ", data: \"" << s << "\"";
	cout << endl;
}

void showCompareStr(const String & s1, const String & s2)
{
	cout << "\"" << s1 << "\".compare(\"" << s2 << "\") = "
	<< s1.compare(s2) << endl;
}

int main()
{
	cout << " --------------- Constructors tests --------------- " << endl;
	// default
	String def1;
	showStr(def1);
	cout << endl;
	// parametric
	String param1("Hell_ w0r!d");
	showStr(param1);
	String param2("");
	showStr(param2);
	cout << endl;
	// copy
	String copy1(param1);
	showStr(copy1);
	String copy2(param2);
	showStr(copy2);
	cout << endl;
	// move
	String move1(std::move(String("Temp for move")));
	showStr(move1);
	cout << endl;

	cout << " ----------------- operator= tests ----------------- " << endl;
	// copy assignment
	String cp_ass1("Copy_assign_to");
	String cp_ass2("Copy_assign_from");
	showStr(cp_ass1);
	showStr(cp_ass2);
	cp_ass1 = cp_ass2;
	showStr(cp_ass1);
	showStr(cp_ass2);
	cout << endl;
	// move assignment
	String mv_ass1("Move_assign_to");
	showStr(mv_ass1);
	mv_ass1 = String("TEMP Move_assign_from");
	showStr(mv_ass1);
	cout << endl;

	cout << " ----------------- compare() tests ----------------- " << endl;
	String comp1("");
	String comp2("abc");
	String comp3("acc");
	String comp4("abcd");
	showCompareStr(comp1, comp2);
	showCompareStr(comp2, comp2);
	showCompareStr(comp2, comp3);
	showCompareStr(comp3, comp2);
	showCompareStr(comp2, comp4);
	showCompareStr(comp3, comp4);
	cout << endl;

	cout << " ------------------ ==, != tests ------------------ " << endl;
	cout << std::boolalpha;
	cout << "\"" << comp2 << "\" == \"" << comp2 << "\" = "
												<< (comp2 == comp2) << endl;
	cout << "\"" << comp2 << "\" == \"" << comp3 << "\" = "
												<< (comp2 == comp3) << endl;
	cout << "\"" << comp2 << "\" != \"" << comp2 << "\" = "
												<< (comp2 != comp2) << endl;
	cout << "\"" << comp2 << "\" != \"" << comp3 << "\" = "
												<< (comp2 != comp3) << endl;
	cout << std::noboolalpha << endl;

	cout << " ------------------ clear() tests ------------------ " << endl;
	String clear1("Sacrifise for clear()");
	showStr(clear1);

	clear1.clear();
	showStr(clear1);

	clear1.clear();
	showStr(clear1);

	cout << endl;

	cout << " ------------------ swap() tests ------------------ " << endl;
	String swap1("First str");
	String swap2("Second str");
	showStr(swap1);
	showStr(swap2);

	swap1.swap(swap2);
	showStr(swap1);
	showStr(swap2);
	cout << endl;

	cout << " ----------------- substr() tests ----------------- " << endl;
	String sub1("STRabcdef");
	String subNeedle1("STR");
	cout << sub1.substr(subNeedle1) << endl;

	String sub2("abcSTRdef");
	cout << sub2.substr(subNeedle1) << endl;

	String sub3("abcdefSTR");
	cout << sub3.substr(subNeedle1) << endl;

	String sub4("abcdefST");
	cout << sub4.substr(subNeedle1) << endl;

	String sub5("abcdefe");
	cout << sub5.substr(subNeedle1) << endl;

	cout << sub5.substr(sub5) << endl;

	String subNeedle2("");
	cout << sub2.substr(subNeedle2) << endl;

	cout << subNeedle1.substr(sub2) << endl;
	cout << endl;

	cout << " ----------------- resize() tests ----------------- " << endl;
	String res1("String_resize_test");
	showStr(res1);
	res1.resize(18);
	showStr(res1);
	// TODO think about nonprintable chars in <<
	res1.resize(20);
	showStr(res1);
	res1.resize(22, 'q');
	showStr(res1);
	res1.resize(13, 'q');
	showStr(res1);
	res1.resize(0);
	showStr(res1);
	res1.resize(5, 'a');
	showStr(res1);
	cout << endl;

	cout << " ----------------- insert() tests ----------------- " << endl;
	String ins1("String_insert_test");
	String insWhat1("ABC");
	showStr(ins1);
	try {
		ins1.insert(19, insWhat1);
	} catch (std::out_of_range & exc) {
		cerr << "Out of range exception: " << exc.what() << endl;
	}
	showStr(ins1);

	ins1.insert(0, insWhat1);
	showStr(ins1);

	String ins2("String_insert_test");
	ins2.insert(10, insWhat1);
	showStr(ins2);

	String ins3("String_insert_test");
	ins3.insert(18, insWhat1);
	showStr(ins3);

	String ins4("String_insert_test");
	String insWhat2("");
	ins4.insert(10, insWhat2);
	showStr(ins4);

	insWhat2.insert(0, insWhat2);
	showStr(insWhat2);

	// insert String to itself
	ins4.insert(0, ins4);
	showStr(ins4);

	String ins5("String_insert_test");
	ins5.insert(10, ins5);
	showStr(ins5);

	String ins6("String_insert_test");
	ins6.insert(18, ins6);
	showStr(ins6);

	String ins7("String_insert_test");
	try {
		ins7.insert(19, ins7);
	} catch (std::out_of_range & exc) {
		cerr << "Out of range exception: " << exc.what() << endl;
	}
	showStr(ins7);
	cout << endl;

	cout << " --------------- insert(char) tests --------------- " << endl;
	String insCh1("Insert_char");
	insCh1.insert(0, ' ');
	showStr(insCh1);

	insCh1.insert(4, 'W');
	showStr(insCh1);

	insCh1.insert(13, 'M');
	showStr(insCh1);

	try {
		insCh1.insert(20, 'G');
	} catch (std::out_of_range & exc) {
		cerr << "Out of range exception: " << exc.what() << endl;
	}
	showStr(insCh1);
	cout << endl;

	cout << " ----------------- append() tests ----------------- " << endl;
	String app1("");
	showStr(app1.append(""));
	showStr(app1.append("Append"));
	showStr(app1.append(" test string"));
	showStr(app1.append(""));
	cout << endl;

	cout << " --------------------- + tests --------------------- " << endl;
	String add1("one");
	String add2(" plus two");
	showStr(add1);
	showStr(add2);
	showStr(add1 + add2);
	showStr(add1);
	showStr(add2);
	cout << endl;

	cout << " -------------------- += tests -------------------- " << endl;
	String addAss1("one");
	showStr(addAss1);
	addAss1 += String(" plus two");
	showStr(addAss1);
	showStr(addAss1 += " and plus three");
	showStr(addAss1);
	cout << endl;

	cout << " -------------------- >> tests -------------------- " << endl;
	String extr1;
	// cout << "first String input: " << endl;
	// std::cin >> extr1;
	// showStr(extr1);

	// cout << "second String input: " << endl;
	// std::cin >> extr1;
	// showStr(extr1);

	std::stringstream ss("  hello  there   ");
	ss >> extr1;
	showStr(extr1);
	ss >> extr1;
	showStr(extr1);

	return 0;
}
