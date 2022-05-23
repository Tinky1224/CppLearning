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
        int n, res=0, mid, l, r;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        if (n==2){
            std::cout << 2 << std::endl;
            continue;
        }
        mid = n/2;
        l = mid;
        r = mid;
        while (l >= 0 && s[l]==s[mid]){
            l--;
        }
        while (r < n && s[r]==s[mid]){
            r++;
        }
        res = r-l-1;
        std::cout << res << std::endl;
    }
    return 0;
}

