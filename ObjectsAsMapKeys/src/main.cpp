#include <iostream>
#include <map>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(string name, int age): name(name), age(age){
		cout << "USING PARAMETER CONSTRUCTOR!" << endl;
	}
	Person(): name(""), age(0) {
		cout << "USING DEFAULT CONSTRUCTOR!" << endl;
	}

	Person(const Person &other) {
		cout << "USING COPY CONSTRUCTOR!" << endl;
		name = other.name;
		age = other.age;
	}

	// Must be marked const because it expects keys not to be changed
	// so any methods you call on a key must be const
	void print() const {
		cout << name << ": " << age << flush;
	}

	// Must provide a method of comparing 2 objects
	// as maps need to know what order to have
	// the objects in. So I'm redefining <
	bool operator<(const Person &other) const {
		// Need the case if they are the same
		// this allows an object to be inserted that
		// has the same 'name' member variable.
		// Otherwise trying to insert 
		// people[Person("Mike", 444)] = 123
		// would overwrite the int value in the map
		// for Mike, but would not change the age
		// so our loop would say:
		// 123: Mike: 40
		if (name == other.name) {
			return age < other.age;
		}
		else {
		return name < other.name;
		}	
	}
};



int main(int argc, char *argv[])
{
	map<Person, int> people;

	// This implements 'Shallow Copy'
	// It will just copy the instance variables
	// into new object
	// This is BAD if you have pointers in your instance variables

	cout << "MAKING MIKE" << endl;
	people[Person("Mike", 40)] = 40;
	cout << "MAKING MIKE AGAIN" << endl;
	people[Person("Mike", 444)] = 123;
	cout << "MAKING VICKY" << endl;
	people[Person("Vicky", 30)] = 30;
	cout << "MAKING RAJ" << endl;
	people[Person("Raj", 20)] = 20;

	cout << "MAKING BOB THROUGH INSERT" << endl;
	people.insert(make_pair(Person("Bob", 45), 45));

	for (map<Person, int>::iterator i = people.begin(); i != people.end(); i++)
	{
		cout << i->second << ": " << flush;
		i->first.print();
		cout << endl;
	}
	


	system("pause");
	return 0;
}