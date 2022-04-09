#include <iostream>

int main(){
    int n, evenness[2]={-1,-1}, curr, res=-1;
    bool check = false;
    std::cin >> n;
    for (int i=0; i<n; i++){
        std::cin >> curr;
        if (check){
            if (evenness[curr%2]==-1){
                res=i+1;
            }
        }else{
            if (evenness[curr%2]!=-1){
                check = true;
                res = evenness[(curr%2)^1];
            }else{
                evenness[curr%2]=i+1;
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}