#include <iostream>
using namespace std;

void func(int* u){
	cout<<"Output of constant cast "<<*u<<endl;
}

class Base{
	virtual void print(){}
};
class derived : public Base{
};
int main()
{
	// using static cast operator
        float f = 3.5;
	int b = static_cast<int>(f);
	cout << "Output of static cast "<< b <<endl;

	//using constant cast operator
	const int num1 = 40;
	const int *num2 = &num1;
	// typecasting to pass a pointer to constant data type variable
	int *v = const_cast <int*>(num2);
	func(v);

        //using dynamic cast operator
	Base *ptr = new derived;
	//converting pointer to parent into pointer to child class
	derived *pd = dynamic_cast<derived*>(ptr);
	if(pd!=NULL){
		cout<< "Dynamic casting is done successfully\n";
	}
	else{
	cout<< "Dynamic casting has failed";
	}

	//using reinterpret cast operator
	int *pt = new int (65);//declare a pointer variable
	//converting int pointer type to char pointer type
	char *ch = reinterpret_cast <char*>(pt);
	cout << "The value of pt is "<< pt << ", value of pt* is "<<*pt<<endl;
	cout << "The value of ch is "<< ch << ", value of ch* is "<<*ch<<endl;

	return 0;
}