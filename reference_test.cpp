#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "Hello";
    string s2 = s1;
    string &s3 = s1;

    cout << "value:" << endl << "s1:" << s1 << endl << "s2:" << s2 << endl << "s3:" << s3 << endl;
    cout <<"memory pos:" << endl << "s1:" << &s1 << endl << "s2:" << &s2 << endl << "s3:" << &s3 << endl;
}