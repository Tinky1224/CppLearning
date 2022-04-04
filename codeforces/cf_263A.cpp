#include<iostream>
 
int main(){
    int curr, res=0;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            std::cin >> curr;
            if (curr==1){
                if (i<2) res+=2-i;
                else res+=i-2;
                if (j<2) res+=2-j;
                else res+=j-2;
                break;
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}