#include<iostream>
using namespace std;

class IceTray{

  public:
  string crab_shape;
  string tree_shape;
  
  //Default Constructor
  IceTray(){
    crab_shape= "Frozen";
    tree_shape = "Not Frozen";
  }
  
  //Parameterized Constructor
  IceTray(string x){
    crab_shape = x;
  }

  //Destructor
  ~IceTray(){
     cout<<"Destructor is called"<<endl;
  }


};

int main(){

  //Default Constructor Call
  IceTray Orange_Juice;
  //Parameterized Constructor Call
  IceTray Lemon_Juice("Not Frozen");
    
  cout << Orange_Juice.crab_shape << endl;
  cout << Lemon_Juice.crab_shape <<endl;
  
  return 0;
}