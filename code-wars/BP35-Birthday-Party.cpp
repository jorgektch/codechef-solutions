#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int a; cin >> a;
    int n_x, n_y, n_z;
    cin >> n_x >> n_y >> n_z;
    vector<long long int> x, y, z;
    for(int i=0; i<n_x; i++){
        long long int xi; cin >> xi;
        x.push_back(xi);
    }
    for(int j=0; j<n_y; j++){
        long long int yi; cin >> yi;
        y.push_back(yi);
    }
    for(int k=0; k<n_z; k++){
        long long int zi; cin >> zi;
        z.push_back(zi);
    }
    long long int sum_max=-1;
    map<int, map<int, long long int>> yz;
    for(int i=0; i<n_x; i++){
        for(int j=0; j<n_y; j++){
            if(x[i]+y[j]<a){
                for(int k=0; k<n_z; k++){
                    if(yz[j][k]==0) yz[j][k] = y[j]+z[k];
                    long long int sum = x[i]+yz[j][k];
                    if(sum<=a && sum>sum_max)
                        sum_max = sum;
                }
            }
        }
    }
    if(sum_max == -1){
        cout << "-1\n";
    }else{
        long long int dif = a-sum_max;
        cout << dif << "\n";
    }
    return 0;
}