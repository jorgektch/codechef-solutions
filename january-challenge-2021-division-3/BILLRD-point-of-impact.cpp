#include <iostream>
using namespace std;
int main() {
	int t;
	int n, k;
	int x, y;
	int xf, yf;
	int quad[4][2];
	scanf("%d", &t);
	for(int c=0; c<t; c++){
	    scanf("%d", &n);
	    scanf("%d", &k);
	    scanf("%d", &x);
	    scanf("%d", &y);
	    if(x==y){
	        xf = n;
	        yf = n;
	    }else{
	        if(x>y){
	            quad[0][0] = n;
	            quad[0][1] = y+(n-x);
        	    quad[1][0] = y+(n-x);
        	    quad[1][1] = n;
        	    quad[2][0] = 0;
        	    quad[2][1] = x-y;
        	    quad[3][0] = x-y;
        	    quad[3][1] = 0;
	        }else{
	            quad[0][0] = x+(n-y);
	            quad[0][1] = n;
        	    quad[1][0] = n;
        	    quad[1][1] = x+(n-y);
        	    quad[2][0] = y-x;
        	    quad[2][1] = 0;
        	    quad[3][0] = 0;
        	    quad[3][1] = y-x;
	        }
	        xf = quad[(k-1)%4][0];
	        yf = quad[(k-1)%4][1];
	    }
	    printf("%d %d\n", xf, yf);
	}
	return 0;
}