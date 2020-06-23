#include <iostream>
#include <list>

using namespace std;



int main(int argc, char *argv[])
{
	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	// insert 100 at index 1
	list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);
	cout << "Element: " << *it << endl;

	// remove index 1
	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	eraseIt = numbers.erase(eraseIt);
	cout << "Element: " << *it << endl;

	// Demonstrating how erase method increments it pointer.
	// Basically it is pointing to the same index after the element is
	// removed and shifted.  This means, 1234 will never be inserted
	// wher *it equals 2 when written this way
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) 
	{

		cout << "Pointing to " << *it << endl;
		if(*it == 2) {
			numbers.insert(it, 1234);
		}
		if(*it == 1) {
			it = numbers.erase(it);
			cout << "Pointing to " << *it << " AFTER ERASE" << endl;
		}
		
	}

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) 
	{
		cout << *it << endl;
	}
	

	system("pause");
	return 0;
}