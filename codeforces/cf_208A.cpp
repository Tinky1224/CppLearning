#include <iostream>
#include <string>

int main(){
    std::string s, res;
    std::cin >> s;
    int curr_l = 0;
    for (char c:s){
        if (curr_l>1 && c=='B' && res[curr_l-1]=='U' && res[curr_l-2]=='W'){
            res.pop_back();
            res.pop_back();
            curr_l-=2;
            if (curr_l>0 && res[curr_l-1]!=' '){
                res.push_back(' ');
                curr_l++;
            }
        }else{
            res.push_back(c);
            curr_l++;
        }
    }
    if (res.back()==' ') res.pop_back();
    std::cout << res << std::endl;
    return 0;
}