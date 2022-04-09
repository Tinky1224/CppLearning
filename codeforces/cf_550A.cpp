#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string s;
    std::cin >> s;
    std::vector<int> A, B;
    int n=s.size();
    for (int i=0; i<n-1; i++){
        if (s[i]=='A' && s[i+1]=='B') A.push_back(i);
        if (s[i]=='B' && s[i+1]=='A') B.push_back(i);
    }
    for (int a_ind:A){
        for (int b_ind:B){
            if (b_ind < a_ind-1 || b_ind >a_ind+1){
                std::cout << "YES" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}