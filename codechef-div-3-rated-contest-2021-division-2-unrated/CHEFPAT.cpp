#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	for(int c=0; c<t; c++){
	    int n; cin >> n;
        int ai, max_ai=1001;
        map<int, vector<int>> m;
	    for(int i=0; i<n; i++){
            cin >> ai;
            if(ai>max_ai) max_ai = ai;
            m[ai].push_back(i+1);
        }
        map<int, int> pos_time;
        int pos = 1;
        for(int illness=max_ai; illness>=1; illness--){
            for(int i=0; i<m[illness].size(); i++){
                pos_time[m[illness][i]] = pos;
                pos++;
            }
        }
        for(int i=1; i<=n; i++){
            cout << pos_time[i] << " ";
        }
        cout << "\n";
	}
	return 0;
}
