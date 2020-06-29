#include <iostream>

using namespace std;

struct Test {
	virtual bool operator()(string &text) = 0;
};

// A functor overloads ()
// You could implement lots of things that overload Test.
// This can do things function pointers can't because
// structs and classes can contain variables.
struct MatchTest: public Test {
	virtual bool operator()(string &text) {
		return text == "lion";
	}
};

void check(string text, Test &test) {
	if (test(text) ) {
		cout << "Text matches!" << endl;
	}
	else {
		cout << "No match." << endl;
	}
}

int main(int argc, char *argv[])
{
	MatchTest pred;

	string value = "lion";

	cout << pred(value) << endl;

	MatchTest m;
	check("lion", m);

	system("pause");
}
