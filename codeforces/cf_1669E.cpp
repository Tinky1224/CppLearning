#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t>0){
        t--;
        std::vector<int> f(11,0), s(11,0);
        std::vector<std::vector<int>> c(11, std::vector<int> (11,0));
        int n;
        ll res=0;
        std::cin >> n;
        std::string w;
        for (int i=0; i<n; i++){
            std::cin >> w;
            res += f[w[0]-'a'] + s[w[1]-'a'] - c[w[0]-'a'][w[1]-'a']*2;
            f[w[0]-'a']++;
            s[w[1]-'a']++;
            c[w[0]-'a'][w[1]-'a']++;
        }
        std::cout << res << std::endl;
    }
}