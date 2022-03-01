#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void FirstFunction(int i){
    for (i=i;i>0;i--){
        cout << "First function " << i << "\n";
    }
}

int main(){
    int num;
    cout << "input call number\n" ;
    cin >> num;
    FirstFunction(num);
    return 0;
}

