#include <iostream>
// This is for C++98 typeid
#include <typeinfo>
using namespace std;



int main(int argc, char *argv[])
{
	string value;

	// C++ 98 stuff
	cout << typeid(value).name() << endl;

	// decltype examines the type of the variable in ()
	// and gives it to what you are declaring.
	decltype(value) name = "Bob";

	cout << typeid(name).name() << endl;

	system("pause");
}
