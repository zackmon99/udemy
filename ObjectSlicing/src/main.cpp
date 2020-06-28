#include <iostream>

using namespace std;

class Parent {
private:
	int one;

public:
	// must redefine default constructor when you
	// overwrite copy constructor.
	Parent(): one(0) {
		//cout << "Parent constructor." << endl;
	}

	// When the copy constructor is invoked with Child,
	// The extra member variables of child are not used.
	// Known as object slicing.
	Parent(const Parent &other): one(0) {
		cout << "Copy parent" << endl;
	}

	virtual void print() {
		cout << "Parent" << endl;
	}

	virtual ~Parent() {

	}
};

class Child: public Parent {
private:
	int two;

public:
	Child(): two(0) {
		//cout << "Child constructor" << endl;
	}

	void print() {
		cout << "Child" << endl;
	}
};

int main(int argc, char *argv[])
{
	Child c1;

	// Pointers/References work with virtual methods
	Parent &p1 = c1;
	p1.print();
	
	// This doesnt work as you would expect because it is
	// using implicit copy constructor.
	Parent p2 = Child();
	p2.print();
	system("pause");
	return 0;
}