#include <iostream>
using namespace std;

int main(){
    int i=0,num1=0,num2=0;

    while (i < 5){
        cout << "while:" << i++ << endl;
        cout << "num++" << num1++ << endl;
        cout << "++num" << ++num2 << endl;
    }
    cout << "outloop:" << endl << "num1: " << num1 << endl << "num2: " << num2 << endl;

    do{
        cout << "do_while:" << i-- << endl;
    }while (i > 10); //Whether or not the conditions are met, it will be executed at least once.

    for(i=5;i>0;i--){
        cout << "--i:" << i << endl;
    }
    return 0;
}