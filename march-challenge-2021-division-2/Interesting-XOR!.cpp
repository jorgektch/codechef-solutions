#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t; cin >> t;
    for(int i=0; i<t; i++){
        long long c; cin >> c;
        long long axb_max = -1;
        for(long long a=1; a<pow(2, ceil(log(c)/log(2)))-1; a++){
            for(long long b=a; b<pow(2, ceil(log(c)/log(2))); b++){
                if((a^b)==c && a*b>axb_max){
                    axb_max = a*b;
                }
            }
        }
        cout << axb_max << endl;
    }
    return 0;
}