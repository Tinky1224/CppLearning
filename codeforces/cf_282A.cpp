#include<iostream>
#include<string>
int main(){
    int x=0, n;
    std::cin >> n;
    for (int i=0;i<n;i++){
        std::string oper;
        std::cin >> oper;
        if (oper=="X++" || oper=="++X"){
            x++;
        }else{
            x--;
        }
    }
    std::cout << x << std::endl;
    return 0;
}
