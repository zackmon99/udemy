#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj"));
	lookup.insert(make_pair(20, "Bob"));

	for (multimap<int, string>::iterator i = lookup.begin(); i != lookup.end(); i++) {
		cout << i->first << ": " << i->second<< endl;
	}

	cout << "-----------" << endl;
	
	for (multimap<int, string>::iterator i = lookup.find(10); i != lookup.end(); i++) {
		cout << i->first << ": " << i->second<< endl;
	}

	cout << "-----------" << endl;

	// OLD WAY OF FINDING VALUES values WITH KEY OF 30
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
	for (multimap<int, string>::iterator i = its.first; i != its.second; i++) {
		cout << i->first << ": " << i->second<< endl;
	}

	cout << "-----------" << endl;

	// C++11 way of finding all values with key of 30
	auto its2 = lookup.equal_range(30);
	for (multimap<int, string>::iterator i = its2.first; i != its2.second; i++) {
		cout << i->first << ": " << i->second<< endl;
	}


	system("pause");
	return 0;
}