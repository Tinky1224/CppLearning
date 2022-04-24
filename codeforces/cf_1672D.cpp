#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long
#define pii std::pair<int, int>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--){
        int n, ind=0, curr, num;
        std::cin >> n;
        std::vector<int> a(n, 0), b(n, 0);
        std::vector<std::vector<pii>> inds(n+1);
        bool check = true;
        for (int i=0; i<n; i++) {
            std::cin >> a[i];
            inds[a[i]].push_back(pii (i, 1));
        }
        for (int i=0; i<n; i++){
            std::reverse(inds[i].begin(), inds[i].end());
        }
        for (int i=0; i<n; i++) std::cin >> b[i];
        for (int i=0; i<n; i++) {
            curr = b[i];
            while (curr != a[ind] && inds[a[ind]][0].first>inds[curr].back().first){
                num = inds[a[ind]].back().second;
                inds[a[ind]].pop_back();
                inds[a[ind]].back().second += num;
                ind++;
            }
            if (curr != a[ind]){
                check = false;
                break;
            }else{
                if (inds[curr].back().second > 1){
                    inds[curr].back().second -= 1;
                }else{
                    inds[curr].pop_back();
                    ind++;
                }
            }
        }
        if (check) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}