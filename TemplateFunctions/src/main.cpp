#include <iostream>

using namespace std;

template<class T>
void print(T n) {
	cout << "Template version: " << n << endl;
}

void print(int value) {
	cout << "Non template version: " << value << endl;
}

// This one will REQUIRE a type when calling since
// there is no argument to infer the type;
template<class T>
void show() {
	cout << T() << endl;
}

int main(int argc, char *argv[])
{
	print<int>(5);

	print<string>("test");

	// Don't actually need what type it is
	// c++ infers type

	print("HELLO");

	// EXCEPT, you do when you have an overloaded
	// function.  Defaults to non template version
	// because it is a closer match.  IE print
	// non template function takes exatcly an int.

	print(3);
	print<int>(3);
	// Makes it go for template class with type
	// inference.
	print<>(4);

	show<double>();

	system("pause");
	return 0;
}