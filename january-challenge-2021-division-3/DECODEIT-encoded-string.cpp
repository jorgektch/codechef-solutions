#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int tc;
    int n;
    char code[100000];
    char matrix[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
    int pos;

	scanf("%d", &tc);
	for (int c=0; c<tc; c++){
	    scanf("%d", &n);
	    scanf("%s", code);
	    for(int i=0; i<n/4; i++){
	        pos = ((int)code[4*i]-48)*8+((int)code[4*i+1]-48)*4+((int)code[4*i+2]-48)*2+((int)code[4*i+3]-48);
	        printf("%c", matrix[pos]);
	    }
	    printf("\n");
	}
	return 0;
}