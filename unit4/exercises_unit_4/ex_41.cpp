#include<iostream>
using namespace std;

class GrandDad{
	int age;
	protected:
	void run();
	public:
	void walk();
};


class Father: private GrandDad{  //Single Inheritance
	int height;
	public:
	void sleep();
	void wake();
};

class You : public Father{ //MultiLevel Inheritance
	int weight;
	public:
	void eat();
	void dance();
};