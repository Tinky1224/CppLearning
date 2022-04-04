#include<iostream>
#include<vector>
 
int main(){
    std::vector<int> st;
    int n, k;
    std::cin >> n >> k;
//    std::cout << n << "," << k << std::endl;
    for (int i=0;i<n;i++){
//        std::cout << n << std::endl;
        int curr;
        std::cin >> curr;
        st.push_back(curr);
    }
//    std::cout << "out loop" << std::endl;
    int curr = st[k-1];
    while (!st.empty() && (curr>st.back() || st.back()==0)){
        st.pop_back();
        if (st.empty()) break;
    }
    std::cout << st.size() << std::endl;
    return 0;
}
