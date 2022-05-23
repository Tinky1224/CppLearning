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
        int n, c=1, m;
        std::cin >> n;
        m = n;
        std::vector<int> a(n);
        for (int i=0; i<n; i++) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        for (int i=1; i<n; i++){
            if (a[i]==a[i-1]){
                c++;
                if (c>2) m--;
            }else c=1;
        }
        std::cout << (m+1)/2 << std::endl;
    }
    return 0;
}

