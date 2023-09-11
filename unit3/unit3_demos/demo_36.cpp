#include<iostream>
using namespace std;

class Icetray {
   int crystals;
   public:
   Icetray(int x = 0) {
      crystals = x;
   }
   //non-constant function
   int getValue(){
   crystals++;
   return crystals;
   }

   //constant member function
   int getValue() const {
      return crystals;
   }
};
int main() {
   //constant object - calls only constant function
   const Icetray apple_juice(5);
   //Non-constant function
   Icetray Lemon_juice(8);
   cout << "The value using object apple_juice : " << apple_juice.getValue();
   cout << "\nThe value using object Lemon_juice : " << Lemon_juice.getValue();
   cout <<"\n";
   return 0;
}