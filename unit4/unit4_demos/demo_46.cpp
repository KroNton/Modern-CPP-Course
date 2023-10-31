#include<iostream>
using namespace std;

class Father {
public:
	virtual void run()
	{
		cout << "Father is running\n";
	}
};

class Son : public Father {
public:
	void run()
	{
		cout << "Son is running\n";
	}

};

int main()
{
	
//1st method to call the override virtual function

	Son ss;
	Father &f=ss ;
	f.run();

//2nd method to call the override virtual function

	Father *fptr;
	Son s;
	fptr = &s;

	fptr->run();

	return 0;
}