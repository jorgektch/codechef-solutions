#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    for(int c=0; c<t; c++){
        int n; cin >> n;
        vector<int> a = vector<int>();
        for(int i=0; i<n; i++){
            long int ai; cin >> ai;
            a.push_back(ai);
        }
        long int mini = *min_element(a.begin(), a.end());
        long int maxi = *max_element(a.begin(), a.end());
        long int sum_temp, sum_max = -1;
        for(int i=1; i<n-1; i++){
            sum_temp = abs(mini-a[i])+abs(a[i]-maxi);
            if(sum_temp>sum_max){
                sum_max = sum_temp;
            }
        }
        cout << sum_max+abs(maxi-mini) <<"\n";
    }
    return 0;
}