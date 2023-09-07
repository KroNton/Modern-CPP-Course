#include<iostream>
#include<vector>
using namespace std;


struct Tray_details
{
  string name;
  int crystal_numbers;
  vector<string> shapes;
  float time_;
 
};




void print_details(Tray_details T){

  cout<< "Details for the "<< T.name << "Tray are:"<<endl;
  cout << "Crystal count : "<< T.crystal_numbers<<endl;
  cout << "Time Required : "<< T.time_<<endl;
  cout << "Shapes available are:" << endl;

  for (auto i = T.shapes.begin(); i != T.shapes.end(); ++i)
        cout << *i << " ";
  cout<<"\n";

}


int main(){
  Tray_details Green_tray;
  Green_tray.name = "Green";
  Green_tray.crystal_numbers = 10;
  Green_tray.shapes.push_back("fish");
  Green_tray.shapes.push_back("crab");
  Green_tray.shapes.push_back("star");
  Green_tray.time_ = 20.2;
  print_details( Green_tray);

  return 0;
}