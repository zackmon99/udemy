#include <iostream>

using namespace std;

// Generally template classes are used to implement 
// something that stores objects.
// Also, template classes are generally declared and
// defined all in one header file.  No .cpp 
// implementation
template<class T> // you can have more classes here
class Test {
private:
	T obj;

public:
	Test(T obj) {
		this->obj = obj;
	}

	void print() {
		cout << obj << endl;
	}
};

int main(int argc, char *argv[])
{
	Test<string> test1("Zack");

	test1.print();

	system("pause");
	return 0;
}