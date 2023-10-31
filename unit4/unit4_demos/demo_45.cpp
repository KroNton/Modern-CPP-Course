
#include<iostream>
using namespace std;

class Mobile
{
public:
	virtual void Display()
	{
		cout << "\nThis is Display() method"
				" of base class Mobile"<<endl;
	}
	void Show()
	{
		cout << "\nThis is Show() method "
			"of BaseClass Mobile"<<endl;
	}
};

class VideoPlayer : public Mobile
{
public:
	// Overriding method - new working of
	// base class's display method
	void Display()
	{
		cout << "\nThis is Display() method"
			" of derived Class VideoPlayer"<<endl;
	}
};

// Driver code
int main()
{
	
//1st method to call the override function
	VideoPlayer Vp;
	Mobile &M = Vp;
	M.Display();
	Vp.Show();

//2nd method to call the override function

	// VideoPlayer Vp;
	// Mobile *M;
	// M=&Vp;
	// M->Display();
	// Vp.Show();
}