#include <iostream>
#include <string>
using namespace std;
/*  string/int -> 變數型態(內部的值)
    cars/scores -> 變數名稱
    [n]/[] -> 賦予n/?個值的空間，若沒有指定n，則依照給定的資料大小賦予空間。
    PS.若是空間大於給定的值個數，可以再額外增加值進入array，但若是空間已滿，要新增新的值則需要覆蓋掉原有的值。
*/
int main(){
    string cars[4] = {"BMW","Yamaha","Mazda","Ford"};
    int scores[] = {100,95,90,80};

    cout << "all cars : " << cars << endl; //array的記憶體位置
    cout << "all scores : " << scores << endl;
    cout << "First car : " << cars[0] << endl;
    cout << "First score : " << scores[0] << endl;
    cout << "Second car : " << cars[1] << endl;
    cout << "Second score : " << scores[1] << endl;
    for (int i=0;i<sizeof(scores)/sizeof(scores[0]);i++){
        cout << i << "th car : " << cars[i] << "score : " << scores[i] << endl;
    }
    return 0;
}