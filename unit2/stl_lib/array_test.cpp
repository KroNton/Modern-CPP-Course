
#include <iostream>
using namespace std;
  
int main()
{
    int arr[2]={42, 100};
  
    cout << arr[1] << " ";
    arr[1]= 80;
    cout << arr[1] << " ";
  
    return 0;
}