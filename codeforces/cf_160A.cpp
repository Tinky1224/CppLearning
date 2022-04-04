#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, curr, total=0, res=0;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i=0; i<n; i++){
        std::cin >> curr;
        nums[i] = curr;
        total += curr;
    }
    std::sort(nums.begin(), nums.end());
    curr = 0;
    while (curr <= total){
        curr += nums.back();
        total -= nums.back();
        res++;
        nums.pop_back();
    }
    std::cout << res << std::endl;
    return 0;
}