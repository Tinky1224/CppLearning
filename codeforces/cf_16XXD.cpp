#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define ll long long
#define pii std::pair<int, int>
#define max_heap(type) priority_queue<type, std::vector<type>>
#define min_heap(type) priority_queue<type, std::vector<type>, greater<type>>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--){
        int n, odd=0, even=0;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        for (char c:s){
            if (c=='0') even++;
            else odd++;
        }
        if (odd%2 || odd < 2){
            std::cout << "NO" << std::endl;
            continue;
        }

    }
    return 0;
}

