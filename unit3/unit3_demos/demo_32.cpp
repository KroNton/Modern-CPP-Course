#include<iostream>
using namespace std;

// Create a Class
class IceTray
{
  // Access specifier
  private:
  // Data members(variables inside a class)
  string fish_shape;
  string star_shape;

  // Member Functions()
  void frozen_status(){
      cout << "Crystal which is in fish shape is "<< fish_shape << " and the one in star shape is " << star_shape << endl;
  
  }
};

int main(){
  
  // Declare an object of class IceTray
  IceTray Orange_juice;

  // Accessing data member
  Orange_juice.fish_shape = "Frozen";
  Orange_juice.star_shape = "Not frozen";

  // Accessing Member Function
  Orange_juice.frozen_status();
  return 0;