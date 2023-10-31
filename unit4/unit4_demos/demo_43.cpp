

#include <iostream>
#include<string>
using namespace std;


// Method 1
void Mobile(int var)
{
	cout << "Charge available " << var << endl;
}

// Method 2
void Mobile(string s)
{
	cout << "Battery Status: "<< s << endl;
}


int main()
{
	int a = 96;
	string status ="Charging";

	Mobile(a);
	Mobile(status);
	

	return 0;
}