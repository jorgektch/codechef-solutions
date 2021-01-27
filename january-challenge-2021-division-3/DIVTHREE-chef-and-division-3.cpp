#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n, k ,d;
int a, sa;
int res;

int main() {
    
	scanf("%d", &t);
	for(int tc=0; tc<t; tc++){
	    scanf("%d %d %d", &n, &k, &d);
	    sa = 0;
	    for(int i=0; i<n; i++){
	        scanf("%d", &a);
	        sa = sa+a;
	    }
	    // Process
	    if(k>sa){
	        res = 0;
	    }else{
	        if(sa/k > d){
	            res = d;
	        }else{
	            res = sa/k;
	        }
	    }
	    printf("%d\n", res);
	}
	return 0;
}