#include <iostream>
#include <map>
#include <queue>
#include <vector>

int main(){
    int t, n, res, parent, curr, l, r, total=0, mid, remain=0;
    std::priority_queue<int> heap1, heap2;
    std::map<int, int> c;
    std::vector<int> final;
    std::cin >> t;
    for (int i=0; i<t; i++){
        heap1 = std::priority_queue<int>();
        heap1.push(1);
        heap2 = std::priority_queue<int>();
        final.clear();
        c.clear();
        c[0] = 1;
        total = 0;
        std::cin >> n;
        for (int j=0; j<n-1; j++){
            std::cin >> parent;
            c[parent]++;
        }
        res = c.size();
        for (auto p:c){
            heap1.push(p.second);
        }
        for (int j=0; j<res; j++){
            curr = heap1.top();
            if (curr>res-j){
                total += curr-res+j;
                final.push_back(curr-res+j);
            }
            heap1.pop();
        }
        l = 0;
        r = total;
        while (l < r){
            mid = (l+r)/2;
            remain=0;
            for (int num:final){
                if (num > mid){
                    remain += num-mid;
                }
            }
            if (remain > mid){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        std::cout << res+l << std::endl;
    }
    return 0;
}