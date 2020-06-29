#include <iostream>
// This is for C++98 typeid
#include <typeinfo>
using namespace std;

// so we don't need to explicitly declare a return type
// the part after -> is a trailing type.  You need this
// to use auto here.
template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2) {
	return value1 + value2;
}

int get() {
	return 999;
}

auto test2() -> decltype(get()) {
	return get();
}

int main(int argc, char *argv[])
{

	// You can use auto basically anywhere.  It has C++
	// figure out what it should be
	auto value = 7;
	auto text = "Hello";

	cout << typeid(value).name() << endl;
	cout << typeid(text).name() << endl;

	cout << test(5, 6) << endl;

	cout << test(2.2, 3.5) << endl;

	cout << test2() << endl;

	system("pause");
}
