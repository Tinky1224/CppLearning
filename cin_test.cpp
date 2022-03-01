#include <iostream>
#include <string> //這裡只有getline需要用到這個函式庫
using namespace std;

int main(){
    string s="NOTHING";
    cout << "#cin. input some word:" << endl;
    cin >> s;
    cout << "#cin:" << s << endl;
    cin.clear(); //因為cin在獲取空白鍵時就會停止，此時後續的輸入並不會消失，而是繼續等到下個cin時直接獲取，所以需要進行清除的動作。
    cin.sync();
    cout << "#getline. input some word:" << '\n';
    getline (cin, s);
    cout << "#getline:" << s << '\n';
    return 0;
}