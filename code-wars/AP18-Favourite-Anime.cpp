#include <bits/stdc++.h>
using namespace std;
long long int ncip(int dim, double R){
    int i;
    long long int r = (long long int)floor(R);
    if (dim == 1){
        return 1 + 2*r; 
    }
    long long int n = ncip(dim-1, R);
    for(i=1; i<=r; ++i){
        n += 2*ncip(dim-1, sqrt(R*R - i*i));
    }
    return n;
}
int main(){
    int n; cin >> n; // 1 <= n <= 100
    int ri; vector<int> rv;
    for(int i=0; i<n; i++){
        cin >> ri; rv.push_back(ri); // 1 <= ri <= 1000
    }
    int r; cin >> r; // 1 <= r <= 100
    cout << ncip(n, r) << "\n";
    return 0;
}