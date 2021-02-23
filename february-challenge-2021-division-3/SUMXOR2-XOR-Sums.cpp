#include <bits/stdc++.h>
#include <math.h>
using namespace std;
bool subsetExist(vector<int> arr, int suma, int k){
    int l = k, h = suma-k;
    int x = arr.size();
    bool mat[2][h+1];
    for(int i=0; i<=x; i++){
        for(int j=0; j<=h; j++){
            if(j == 0)
                mat[i%2][j] = true;
            else if(i == 0)
                mat[i%2][j] = false;
            else if(arr[i-1] <= j)
                mat[i%2][j] = mat[(i+1)%2][j-arr[i-1]] || ,arr[(i+1)%2][j];
            else:
                mat[i%2][j] = mat[(i+1)%2][j];
        }
    }
    int flag = 0;
    for(int i=l; i<=h; i++){
        if(mat[x%2][i]){
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        return true;
    else
        return false;
}

int main(){
    long long int n; cin>>n;
    vector<long long int> a;
    for(int i=0; i<n; i++){
        long long int ai; cin >> ai;
        a.push_back(ai);
    }
    long long int q; cin >> q;
    for(long long int i=0; i<q; i++){
        int m; cin >> m;
        
    }
    long long int acum = 0, s1, s2, s3, s4;
    s1 = 1+3+5+2; acum += s1;
    cout << "s1 = " << s1 << " acum = " << acum <<"\n";
    s2 = (1^3)+(1^5)+(1^2)+(3^5)+(3^2)+(5^2); acum += s2;
    cout << "s2 = " << s2 << " acum = " << acum <<"\n";
    s3 = (1^3^5)+(1^3^2)+(1^5^2)+(3^5^2); acum += s3;
    cout << "s3 = " << s3 << " acum = " << acum <<"\n";
    s4 = (1^3^5^2); acum += s4;
    cout << "s4 = " << s4 << " acum = " << acum <<"\n";
    cout << (1^3) << " " << bin((1^3)) << "\n";
    cout << (1^5) << " " << bin((1^5)) << "\n";
    cout << (1^2) << " " << bin((1^2)) << "\n";
    cout << (3^5) << " " << bin((3^5)) << "\n";
    cout << (3^2) << " " << bin((3^2)) << "\n";
    cout << (5^2) << " " << bin((5^2)) << "\n";
    // cout << ":)\n";
    return 0;
}