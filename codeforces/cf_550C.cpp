#include <iostream>
#include <string>
#include <vector>
#include <map>


int main(){
    std::string s, curr_s;
    std::cin >> s;
    int n = s.size(), num, curr_num, m;
    std::vector<std::pair<std::string,int>> curr{std::pair<std::string,int>("",0)};
    std::vector<bool> exist(8,false);
    std::pair<std::string,int> p;
    for (int i=0; i<n; i++){
        num = s[i]-'0';
        m = curr.size();
        for (int j=0; j<m; j++){
            p = curr[j];
            curr_s = p.first;
            curr_num = p.second;
            curr_s.push_back(s[i]);
            curr_num *= 10;
            curr_num += num;
            curr_num %= 8;
            if (curr_num==0){
                std::cout << "YES" << std::endl;
                std::cout << curr_s << std::endl;
                return 0;
            }
            if (!exist[curr_num]){
                curr.push_back(std::pair<std::string, int>(curr_s, curr_num));
                exist[curr_num] = true;
            }
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}