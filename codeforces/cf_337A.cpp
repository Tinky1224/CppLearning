#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m, res;
    std::cin >> n >> m;
    std::vector<int> puzzle(m);
    for (int i=0; i<m; i++){
        std::cin >> puzzle[i];
    }
    std::sort(puzzle.begin(), puzzle.end());
    res = puzzle[m-1]-puzzle[0];
    for (int i=0; i+n-1<m; i++){
        if (res > puzzle[i+n-1]-puzzle[i]){
            res = puzzle[i+n-1]-puzzle[i];
        }
    }
    std::cout << res << std::endl;
    return 0;
}