#include<iostream>
using namespace std;
//implement interface using abstract calss
//Interface containes only pure virtual member function
class IPower
{
  public:
  virtual void Square()=0;
  virtual void Cube()=0;
  ~IPower()=default;
};

class SomeData : public IPower
{
public:
  SomeData(int x, int y, int z)
  {
    X = x;
    Y = y;
    Z = z;
  }

void Square()
{
  cout << "Square of the provided numbers are:\n";
  cout << X*X << endl;
  cout << Y*Y << endl;
  cout << Z*Z << endl;
}
void Cube()
{
  cout << "Cube of the provided numbers are:\n";
  cout << X*X*X << endl;
  cout << Y*Y*Y << endl;
  cout << Z*Z*Z << endl;
  
}
private:
  int X;
  int Y;
  int Z;
};

int main(){
	SomeData numbers(4,2,7);
	numbers.Square();
	numbers.Cube();
	return 0;
}
