#include <iostream>

using namespace std;

void test() {
	cout << "Hello" << endl;
}

void test2(int value) {
	cout << value << endl;
}

int main(int argc, char *argv[])
{
	test();

	// Because void *ptest() looks like a function
	// prototype to c++, we need () around it to say
	// that it IS a pointer
	void (*pTest)();


	// The name of a function IS a pointer to the
	// function, so you don't actually need to assign
	// it &test.
	// pTest = &test;
	pTest = test;

	// Could also have just done this:
	// void(*pTest)() = test;


	// Need the () here because *pTest() could mean
	// just dereference what pTest returns.  So we
	// put the () around it so that the *pTest is
	// determined first.
	// (*pTest)();a
	// BUT,
	// C++ can recognize that when youahave a pointer to
	// a function, then if you add (), it is obvious that
	// you intend to call the function that the pointer
	// points to.
	pTest();

	test2(2);

	// When the function has parameters, you supply
	// a list of JUST the types.  No need for variable
	// name.
	void (*pTest2)(int) = test2;

	pTest2(2);


	system("pause");
}
