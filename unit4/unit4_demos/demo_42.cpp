#include <iostream>
using namespace std;


class Battery {

private:
	int num;

public:
	void set(int charge)
	{
		num = charge;
	}
	int get()
	{
		return num;
	}
};


class Mobile {

public:
	Battery B;
	void show()
	{
		cout<< "battery is "<< B.get() <<"% charged"<<endl;
	}
};

// Driver code
int main()
{
	// Creating the object of
	// class Mobile
	Mobile Nokia;
	Nokia.B.set(100);
	Nokia.show();
}