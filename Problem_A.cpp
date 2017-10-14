//
// Created by beans on 2017/10/14.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int cnt = 0,max = 0;
        if(n==0)
            return 0;
        cout << n << " ";
        if(n==1) {
            max = 4;
            cnt = 3;
        }else {
            while (n != 1) {
                if (n > max)
                    max = n;
                cnt++;
                if (n % 2 == 0)
                    n /= 2;
                else
                    n = n * 3 + 1;

            }
        }
        cout << cnt << " " << max << endl;

    }
}