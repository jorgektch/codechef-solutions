#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	for(int c=0; c<t; c++){
	    int m, h;
	    cin >> m >> h;
	    int bmi = m/pow(h,2);
	    if(bmi<=18)
	        cout << "1\n";
	    else
	        if(19<=bmi && bmi<=24)
	            cout << "2\n";
	        else
	            if(25<=bmi && bmi<=29)
	                cout << "3\n";
	            else
	                cout << "4\n";
	    
	}
	return 0;
}
