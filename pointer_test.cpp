#include <iostream>
using namespace std;

int main(){
    string s = "Hello";
    string* ptr = &s; //指標儲存的是目標的記憶體位置
    cout << "s:" << s << " mem:" << &s << endl;
    cout << "ptr:" << ptr << " mem:" << &ptr << " target value:" << *ptr << endl;
    *ptr = "World"; //改變目標位置中的value
    cout << "s:" << s << " mem:" << &s << endl;
    return 0;

}