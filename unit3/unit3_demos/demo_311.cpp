#include <iostream>
using namespace std;

class Icetray {
public:
        // A user-defined
	// parameterized constructor
	Icetray(int x){
		cout << "This is a parameterized constructor \n";
	}
	
	/* Using the default specifier to instruct
	 the compiler to create the default
	implementation of the constructor.*/
	Icetray() = default;
	//Making copy constructor uncallable
	Icetray(const Icetray&)= delete;
};

int main()
{
	// executes using defaulted constructor
	Icetray Apple_juice, Lemon_juice;
	
	// uses parameterized constructor
	Icetray Mango_juice(1);

	//Error, the usage of the 
	//copy constructor is disabled
	Lemon_juice=Icetray(Apple_juice);
	return 0;
}