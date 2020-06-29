#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;



int main(int argc, char *argv[])
{

	auto texts = {"One", "two", "three"};

	cout << typeid(texts).name();

	for (auto text: texts) {
		cout << text << endl;
	}

	vector<int> numbers = {5, 7, 9, 11};

	for ( auto number: numbers) {
		cout << number << endl;
	}

	string hello = "Hello";

	for (auto c: hello) {
		cout << c << endl;
	}

	system("pause");
}
