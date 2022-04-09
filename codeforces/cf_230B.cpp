#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

int main(){
    // create prime vector. time, space: O(n).
    std::vector<bool> Prime(1000001,true);
    int curr;
    for (int i=0; i<1000001; i++){
        if (i<2) Prime[i]=false;
        if (Prime[i]){
            curr = i*2;
            while (curr<1000001){
                Prime[curr] = false;
                curr += i;
            }
        }
    }
    //others.
    std::unordered_set<long long> s;
    for (long long i=2; i<1000001; i++){
        if (Prime[int(i)]) s.insert(i*i);
    }
    int n;
    std::cin >> n;
    long long x;
    for (int i=0; i<n; i++){
        std::cin >> x;
        if (s.count(x)==1) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
    /*
    // main.
    int n; 
    std::cin >> n;
    long long x;
    double r;
    for (int i=0; i<n; i++){
        std::cin >> x;
        r = std::sqrt(x);
        if (r==int(r) && Prime[int(r)]) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
    */
}