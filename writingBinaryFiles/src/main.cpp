#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// This is needed so structs are not padded for efficiency.
// We want to save the struct EXACTLY
#pragma pack(push, 1)
struct Person {
	// Must not use pointers, because saving pointers won't work
	// string is a pointer on the heap, so we can't use string for name
	char name[50];
	int age;
	double height;
};
// Need to add this so padding is re-enabled
#pragma pack(pop)

int main(int argc, char *argv[])
{
	Person someone = {"Bilbo", 111, 0.8};

	// --WRITING FILE--
	// it is good to give filenames a variable so you
	// can refer to them later, sucha as in an error msg
	string fileName = "test.bin";

	ofstream outputFile;

	// need to use ios::binary so newline character are not
	// processed as they are for strings
	outputFile.open(fileName, ios::binary);

	if (outputFile.is_open())
	{
		// need to write the address
		// and need to cast to char *

		// OLD WAY
		// outputFile.write((char *)&someone, sizeof(Person));

		// NEW WAY
		// reinterpret_cast instead of just casting
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
		outputFile.close();
	}
	else
	{
		cout << "Could not create " + fileName;
	}
	
	// --END OF WRITING FILE--


	// --READING FILE--
	ifstream inputFile;
	
	Person copyOfBilbo = {};
	// need to use ios::binary so newline character are not
	// processed as they are for strings
	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open())
	{
		// need to read to the address
		// and need to cast to char *

		// OLD WAY
		// outputFile.write((char *)&someone, sizeof(Person));

		// NEW WAY
		// reinterpret_cast instead of just casting
		inputFile.read(reinterpret_cast<char *>(&copyOfBilbo), sizeof(Person));
		inputFile.close();
	}
	else
	{
		cout << "Could not read file " + fileName;
	}

	cout << copyOfBilbo.name << ", " << copyOfBilbo.age << ", " << copyOfBilbo.height << endl;
	
	system("pause");
	return 0;
}