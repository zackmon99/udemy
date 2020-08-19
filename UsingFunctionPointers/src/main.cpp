#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test) {
	// return test == "Two";
	return test.size() == 3;
}

int countStrings(vector<string>& texts, bool (*match)(string)) {
	int count = 0;
	for (vector<string>::iterator i = texts.begin(); i != texts.end(); i++)
	{
		if (match(*i)) {
			count++;
		}
	}
	
	return count;
}

int main(int argc, char *argv[])
{
	vector<string>texts;
	texts.push_back("One");
	texts.push_back("Two");
	texts.push_back("Three");
	texts.push_back("One");
	texts.push_back("Two");
	texts.push_back("Three");

	cout << match("one") << endl;

	// This one is part of algorithm.h
	cout << count_if(texts.begin(), texts.end(), match) << endl;

	// This is our own implementation taking only
	// string vectors.  See above.
	cout << countStrings(texts, match) << endl;


	system("pause");
}
