#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long

int main(){
//    std::cout.sync_with_stdio(false);
  //  std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t>0){
        t--;
        int n, accu=0, curr=0;
        std::cin >> n;
        std::vector<int> A(n,-1), C(n,0);
        for (int i=0; i<n; i++) std::cin >> C[i];
        for (int i=0; i<n; i++){
            for (int j=0; j<C[i]-accu; j++){
                A[curr] = 1;
                C[curr] -= curr;
                curr++;
                if (curr==n) break;
            }
            if (curr<n){
                A[curr++] = 0;
            }else{
                break;
            }
            accu = C[i];
        }
        for (int num:A) std::cout << num << " ";
        std::cout << std::endl;
    }
    return 0;
}