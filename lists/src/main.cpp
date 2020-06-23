#include <iostream>
#include <map>

using namespace std;



int main(int argc, char *argv[])
{
	map<string, int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	ages.insert(make_pair("Peter", 100));

	ages["Mike"] = 77;

	cout << ages["Raj"] << endl;

	if (ages.find("Vicky") != ages.end())
	{
		cout << "Found Vicky" << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}
	
	// Shows how iterator pointer points to a 'pair'
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		pair<string, int> age = *it;
		cout << age.first << ": " << age.second << endl;
	}
	cout << "--------------" << endl;
	ages.erase("Peter");
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
	
	
	system("pause");
	return 0;
}