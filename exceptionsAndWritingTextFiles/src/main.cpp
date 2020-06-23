#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person {
	
};

class CanGoWrong
{
private:
	/* data */
public:
	CanGoWrong() {
		cout << "InHERE" << endl;
		char *pMemory = new char[1999999999];
		delete[] pMemory;
	}
};


class MyException: public exception
{
private:
	/* data */
public:
	virtual const char* what() const throw() {
		return "OH SHIT!";
	}
	MyException(/* args */);
	~MyException();


};

class Test
{
private:
	/* data */
public:
	Test(/* args */);
	~Test();
	void goesWrong() {
		throw MyException();
	}
};

Test::Test(/* args */)
{
}

Test::~Test()
{
}


MyException::MyException(/* args */)
{


}

MyException::~MyException()
{
}


void mightGoWrong() {
	bool error1 = false;
	bool error2 = false;
	if (error1) {
		throw "WHOA";
	}
	if (error2) {
		throw std::string("Something else went wrong");
	}
	
}
int main(int argc, char *argv[])
{

	// EXCEPTIONS
	try {
		mightGoWrong();
	}
	catch(int e) {
		std::cout << "Error code: " << e << std::endl;
	}
	catch(char const * e) {
		std::cout << "Error message: " << e << std::endl;
	}
	// REMEMBER: exceptions are a bit different.  pass the address of an object.
	// C++ handles the rest.
	catch(std::string &e) {
		std::cout << "Error string: " << e << std::endl;
	}

	std::cout << "Still running..." << std::endl;
	// CanGoWrong wrong;
	/*
	try {
		CanGoWrong wrong;
	}
	catch(const bad_alloc &e) {
		cout << "Caught exception: " << e.what() << endl;
		
	}
	*/

	Test test;

	try {
		test.goesWrong();
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
	}


	system("pause");

	std::cout << "End of Exceptions" << std::endl;
	//END OF EXCEPTIONS

	// File stream


	ofstream outFile;
	string outFileName = "text.txt";
	outFile.open(outFileName);

	if(outFile.is_open()) {
		outFile << "Hello there" << endl;
		outFile << "123" << endl;
		outFile.close();
	}
	else {
		cout << "Couild not create file: " << outFileName << endl;
	}

	ifstream inFile;
	string iFileNameStats = "stats.txt";

	inFile.open(iFileNameStats);

	while(inFile) {
		string line;
		getline(inFile, line, ':');

		int population;

		inFile >> population;
		// See if error.  If not, it sees eof, and repeats last int read
		if (!inFile) {
			break;
		}

		// Must move one character to skip newline character
		// inFile.get(); // discarding character value
		// --OR in C++ 11
		inFile >> ws; //READ WHITE SPACE (ws)

		//

		cout << line << " -- " << population << endl;
	}

	inFile.close();
	system("pause");
	return 0;
}