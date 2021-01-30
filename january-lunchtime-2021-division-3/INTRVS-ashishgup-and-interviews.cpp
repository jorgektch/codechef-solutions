#include <algorithm>
#include <math.h>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t, n, k;
    int time, res;
    bool to_slow, is_bot;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin >> n; cin >> k;
        res = 0;
        to_slow = false;
        is_bot = true;
        for (int j = 0; j < n; j++) {
            cin >> time;
            if(time>-1) {
                res = res+1;
                if(time>k) to_slow=true;
                if(time>1) is_bot=false;
            }else{
                is_bot=false;
            }
        }
        if(res<ceil(n/2.0)){
            cout << "Rejected\n";
        }else{
            if(to_slow){
                cout<<"Too Slow\n";
            }else{
                if(is_bot){
                    cout <<"Bot\n";
                }else{
                    cout << "Accepted\n";
                }
            }
        }
    }
    return 0;
}