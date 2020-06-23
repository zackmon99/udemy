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
	void print() {
		cout << name << ": " << age << endl;
	}
};



int main(int argc, char *argv[])
{
	map<int, Person> people;

	// This implements 'Shallow Copy'
	// It will just copy the instance variables
	// into new object
	// This is BAD if you have pointers in your instance variables

	cout << "MAKING MIKE" << endl;
	people[0] = Person("Mike", 40);
	cout << "MAKING VICKY" << endl;
	people[1] = Person("Vicky", 30);
	cout << "MAKING RAJ" << endl;
	people[2] = Person("Raj", 20);

	cout << "MAKING BOB THROUGH INSERT" << endl;
	people.insert(make_pair(3, Person("Bob", 45)));

	for (map<int, Person>::iterator i = people.begin(); i != people.end(); i++)
	{
		i->second.print();
	}
	


	system("pause");
	return 0;
}