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
        int n, X=1;
        std::cin >> n;
        while (X < n) X = X*2+1;
        std::vector<int> a(n);
        for (int i=0; i<n; i++) {
            std::cin >> a[i];
            if (a[i]!=i) X &= a[i];
        }
        std::cout << X << std::endl;
    }
    return 0;
}

