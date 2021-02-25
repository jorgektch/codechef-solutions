#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
    vector<long long int> scores;
	for(int c=0; c<t; c++){
	    int n, k;
	    cin >> n >> k;
	    int pi; vector<int> points;
	    for(int i=0; i<k; i++){
	        cin >> pi;
	        points.push_back(pi);
	    }
	    for(int i=0; i<n; i++){
	        string s; cin >> s;
	        long long int score = 0;
	        for(int j=0; j<s.length(); j++){
	            if(s[j]=='1') score += points[j];
	        }
	        scores.push_back(score);
	    }
	}
    for(int i=0; i<scores.size(); i++){
        cout << scores[i] << "\n";
    }
	return 0;
}
