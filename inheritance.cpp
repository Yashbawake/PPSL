#include <iostream>
 using namespace std;
 
 class vehical{
     public:
     void vehica(){
         cout<<"l am a vehicle"<<endl;
     }
 };
 class fourwheel:public vehical{
     public:
     void fourwhee(){
         cout<<"I have four wheels"<<endl;
     }
 };
 class car:public fourwheel{
     public:
     void ca(){
         cout<<"I am a car"<<endl;
     }
 };

int main()
{
    car c1;
    c1.ca();
    c1.vehica();
    c1.fourwhee();

    return 0;
}