#include <iostream>
using namespace std;

int areaOfCircle(float radius){
    return 3.1415*radius*radius;
}

int main(){
    int radius;
    for(int i=0;i<5;i++) {
        cout << "Enter Radius: ";
        cin >> radius;  
        int areacircle = areaOfCircle(radius);
        cout << "area of circle = " << areacircle << endl;
    }
    return 0;
}