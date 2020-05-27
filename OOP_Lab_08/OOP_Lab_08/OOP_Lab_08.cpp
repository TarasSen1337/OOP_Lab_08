#include <iostream>
#include <string>

using namespace std;


class FruitSingleton
{
private:

	static FruitSingleton* singleObject;
	static int count;


	int amount;
	string name;

	FruitSingleton(int a, string n)
	{
		name = n;
		amount = a;
		count++;
	}

public:
	static FruitSingleton& getInstance(int a, string n)
	{
		if (count == 0)
		{
			singleObject = new FruitSingleton(a, n);
		}
		return *singleObject;
	};

	int getAmount()
	{
		return amount;
	}
	string getName() {
		return name;
	}
};

int FruitSingleton::count = 0;
FruitSingleton* FruitSingleton::singleObject = 0;

int main() {

	FruitSingleton& testobject = FruitSingleton::getInstance(5, "apples");

	cout << "There are " << testobject.getAmount() << " " << testobject.getName() << endl;

	testobject = FruitSingleton::getInstance(3, "oranges");

	cout << "There are " << testobject.getAmount() << " " << testobject.getName() << endl;

	return 0;
}