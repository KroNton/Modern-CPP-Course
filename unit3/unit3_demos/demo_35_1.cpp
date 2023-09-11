#include<iostream>
using namespace std;

class IceTray{

  public:
  //Non static data member initialization
  string crab_shape = "Frozen";
   
  //Default Constructor
  IceTray(){
   // You can overwrite the data member here at consturctor	  
   crab_shape= "Rewriting Frozen";
     }
  //Destructor
  ~IceTray(){
     cout<<"Destructor is called"<<endl;
  }
};

int main(){

  //Default Constructor Call
  IceTray Orange_Juice;
  cout << Orange_Juice.crab_shape << endl;
  return 0;
}