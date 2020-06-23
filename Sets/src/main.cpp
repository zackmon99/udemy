#include <iostream>
#include <set>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(string name, int age);
	Person();
	~Person() {

	}
	void print() const;
	// Need to overload the < operator because
	// 
	bool operator<(const Person &other) const;
};

Person::Person(): name(""), age(0) {

}

Person::Person(string name, int age): name(name), age(age)
{
}

void Person::print() const {
	cout << name << ": " << age << endl;
}


bool Person::operator<(const Person &other) const {
	return name < other.name;
}

// --Switch these two to see change in behavior.  See comments
// below when inserting into people set.

/*
bool Person::operator<(const Person &other) const {
	return age < other.age;
}
*/


int main(int argc, char *argv[])
{
	// Set stores unique elements and orders them
	set<int> numbers;
	numbers.insert(50);
	numbers.insert(10);
	numbers.insert(30);
	numbers.insert(20);

	for (set<int>::iterator i = numbers.begin(); i != numbers.end(); i++)
	{
		cout << *i << endl;
	}

	// OLD WAY IS:
	// set<int>::iterator findIt = numbers.find(30);
	auto findIt = numbers.find(30);

	if (findIt != numbers.end())
	{
		cout << "Found: " << *findIt << endl;
	}
	
	// This just returns 1 if it finds the data
	if(numbers.count(30)) {
		cout << "Number found." << endl;
	}

	set<Person> people;

	people.insert(Person("Zack", 30));
	people.insert(Person("Kyle", 32));
	// Since the < operator compares names as defined
	// above, this will not do anything
	people.insert(Person("Zack", 31));
	// This works because the < operator compares names
	// Not ages.  If the < operator compared ages, this
	// would not work and the code above would work, making
	// 2 entries in the set for Zack.  Switch the operator
	// overload definition to see this.
	people.insert(Person("Person3", 32));

	
	for (set<Person>::iterator i = people.begin(); i != people.end(); i++)
	{
		i->print();
	}
	
	system("pause");
	return 0;
}