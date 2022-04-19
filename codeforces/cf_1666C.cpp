#include <iostream>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x[3], y[3], target[2], res[24], seg=0;
    std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    if ((x[1] <= x[0] && x[0] <= x[2]) || (x[2] <= x[0] && x[0] <= x[1])) target[0] = x[0];
    else if ((x[0] <= x[1] && x[1] <= x[2]) || (x[2] <= x[1] && x[1] <= x[0])) target[0] = x[1];
    else target[0] = x[2];
    if ((y[1] <= y[0] && y[0] <= y[2]) || (y[2] <= y[0] && y[0] <= y[1])) target[1] = y[0];
    else if ((y[0] <= y[1] && y[1] <= y[2]) || (y[2] <= y[1] && y[1] <= y[0])) target[1] = y[1];
    else target[1] = y[2];
    for (int i=0; i<3; i++){
        if (x[i]!=target[0]){
            res[seg*4+0] = x[i];
            res[seg*4+1] = y[i];
            res[seg*4+2] = target[0];
            res[seg*4+3] = y[i];
            x[i] = target[0];
            seg++;
        }
        if (y[i]!=target[1]){
            res[seg*4+0] = x[i];
            res[seg*4+1] = y[i];
            res[seg*4+2] = x[i];
            res[seg*4+3] = target[1];
            y[i] = target[1];
            seg++;
        }
    }
    std::cout << seg << std::endl;
    for (int i=0; i<seg; i++){
        for (int j=0; j<4; j++){
            std::cout << res[i*4+j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
    
}
