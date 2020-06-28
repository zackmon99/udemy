#include <iostream>

using namespace std;

// Abstract classes have methods with no implementation.
class Animal {
public:
	// This notation means there is no implementation
	// in this class.  This makes speak a pure
	// virtual function.  This also makes this an
	// abstract class by virtue of having any
	// pure virtual functions.
	virtual void speak() = 0;
	virtual void run() = 0;
};

class Dog: public Animal {
public:
	// You must provide implementations for all pure
	// virtual functions in a child of an abstract
	// class, otherwise, this is also an abstract
	// class because it still has unimplemented pure
	// virtual methods.  So this is still an abstract
	// class because there is no implementation of
	// run().
	virtual void speak() {
		cout << "Woof!" << endl;
	}
};

class Labrador: public Dog {
public:
	Labrador() {
		cout << "New Labrador" << endl;
	}
	// Defining implementation of run().  There are
	// no more pure virtual functions to define,
	// so this is NOT an abstract class!
	virtual void run() {
		cout << "Labrador running!" << endl;
	}
};

int main(int argc, char *argv[])
{

	
	// This does not work because it is an abstract
	// class and you can not obstantiate an abstract
	// class:
	// Animal animal;

	// This is also an abstract class because there is
	// still no implementation of pure virtual function
	// run()
	// Dog dog;
	// dog.speak();

	// Now all pure virtual functions have an
	// implementation.  This is NOT an abstract class.
	// You can obstantiate a Labrador.
	Labrador labrador;
	labrador.speak();
	labrador.run();

	// You cannot create arrays of abstract classes
	// because arrays run the constructors of the
	// object type when declared.
	// Animal animals[];

	// This still works, of course.
	Labrador labs[5];

	// So if you do need an array of Animals,
	// use Pointers!
	Animal *animals[5];
	animals[0] = &labrador;
	animals[1] = &Labrador();

	animals[0]->run();
	animals[1]->speak();

	system("pause");
	return 0;
}