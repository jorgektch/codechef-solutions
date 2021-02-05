#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){
    int n; cin>>n;
    int max_div = 1;
    for(int i=1; i<10+1; i++){
        if(n%i==0 && i>=max_div) max_div = i;
    }
    cout << max_div;
    return 0;
}