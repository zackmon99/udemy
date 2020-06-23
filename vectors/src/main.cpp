#include <iostream>
#include <vector>

using namespace std;



int main(int argc, char *argv[])
{
	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	vector<string>::iterator it = strings.begin();

	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++ ) {
		cout << *it << endl;
	}

	// Vectors and Memory
	vector<double> numbers(0);
	cout << "Size: " << numbers.size() << endl;

	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 10000; i++)
	{
		if (numbers.capacity() != capacity)
		{
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}
		numbers.push_back(i);
	}
	
	numbers.clear();
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;


	// 2d vectors
	// pre-initialize, 3 rows, 4 columns. init to 0
	vector< vector<int> > grid(3, vector<int>(4, 0));

	grid[1].push_back(1);

	for(int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col]<< " " << flush;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}