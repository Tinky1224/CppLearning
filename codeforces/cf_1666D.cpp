#include <iostream>
#include <string>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::string s, t;
    std::cin >> n;
    for (int i=0; i<n; i++){
        int c[26] = {0};
        std::cin >> s >> t;
        while (!s.empty() && !t.empty()){
            if (c[t.back()-'A']>0) break;
            if (s.back()==t.back()){
                t.pop_back();
            }else{
                c[s.back()-'A'] = 1;
            }
            s.pop_back();
        }
        if (!t.empty()) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }
}