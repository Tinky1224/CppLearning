#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n, k, ind1, ind2;
    std::cin >> t;
    while (t>0){
        std::cin >> n >> k;
        std::string s;
        std::vector<int> times(n,0), inds;
        std::cin >> s;
        if (k%2>0){
            k--;
            ind1 = -1;
            for (int i=0; i<n; i++){
                if (s[i]=='1'){
                    ind1 = i;
                    break;
                }
                s[i] = '1';
            }
            if (ind1==-1){
                ind1 = n-1;
                s[n-1] = '0';
            }
            times[ind1]++;
            for (int i=ind1+1; i<n; i++){
                if (s[i]=='1') s[i]='0';
                else s[i]='1';
            }
        }
        if (k>0){
            for (int i=0; i<n; i++){
                if (s[i]=='0') inds.push_back(i);
            }
            std::reverse(inds.begin(), inds.end());
            while (k>0 && inds.size()>1){
                ind1 = inds.back();
                inds.pop_back();
                ind2 = inds.back();
                inds.pop_back();
                times[ind1]++;
                times[ind2]++;
                s[ind1] = '1';
                s[ind2] = '1';
                k -= 2;
            }
            if (k>0){
                if (inds.size()>0 && inds[0]!=n-1){
                    k -= 2;
                    s[inds[0]] = '1';
                    s[n-1] = '0';
                    times[inds[0]]++;
                    times[n-1]++;
                }
                times[0] += k;
            }
        }
        std::cout << s << std::endl;
        for (int time:times) std::cout << time << " ";
        std::cout << std::endl;
        t--;
    }
    return 0;
}