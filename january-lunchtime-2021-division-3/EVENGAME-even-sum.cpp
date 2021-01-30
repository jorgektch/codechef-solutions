#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    int n, a;
    int num_pair, num_nopair;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        num_pair = 0; num_nopair = 0;
        for (int j = 0; j < n; j++) {
            cin >> a;
            if(a%2==0) num_pair++;
            else num_nopair++;
        }
        if(num_nopair%2==0) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}