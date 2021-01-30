#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    int len, num;
    int pair, nopair;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin >> len;
        pair = 0, nopair = 0;
        for (int j = 0; j < len; j++) {
            cin >> num;
            if(num % 2 == 0){
                pair++;
            }else{
                nopair++;
            }
        }
        if(len == pair || len==nopair){
            cout << 0 << "\n";
        }else{
            cout << min(pair, nopair) << "\n";
        }
    }
    return 0;
}