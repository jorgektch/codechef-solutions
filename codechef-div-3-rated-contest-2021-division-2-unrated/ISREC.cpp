#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	for(int c=0; c<t; c++){
        int n, m;
        cin >> n >> m;
        vector<string> v;
        vector<int> x;
        vector<int> y;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            v.push_back(s);
            for(int j=0; j<s.length(); j++){
                if(s[j]=='1'){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        int x_0 = *min_element(x.begin(), x.end());
        int x_f = *max_element(x.begin(), x.end());
        int y_0 = *min_element(y.begin(), y.end());
        int y_f = *max_element(y.begin(), y.end());
        bool is_connected = true;
        for(int i=x_0; i<=x_f; i++){
            for(int j=y_0; j<=y_f; j++){
                if(v[i][j] == '0'){
                   is_connected = false; 
                   break;
                }
            }
            if(!is_connected) break;
        }
        if(is_connected) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}