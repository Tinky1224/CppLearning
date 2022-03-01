#include <iostream>
using namespace std;

int main(){
    string x;
    int y,z;
    //variable = (condition) ? expressionTrue : expressionFalse;
    cout << "input y and z:" << endl;
    cin >> y >> z;
    x = (y>z) ? "y is win." : "z is win.";
    cout << x << endl;
    if (1<2) {
        cout << "1<2!!" << endl;
    }
    if (1>2){
        cout << "1>2?!?!" << endl; 
    }else if (2 > 3){
        cout << "2>3?!?!?" << endl;
    }else {
        cout << "1<=2!" << endl;
    }

    return 0;
}