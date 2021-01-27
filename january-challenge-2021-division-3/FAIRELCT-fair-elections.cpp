#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int t;
    int n, m;
    int v1[1000], sum1;
    int v2[1000], sum2;
    int pos;
    int ops;
    int temp;
    scanf("%d", &t);
	for(int c=0; c<t; c++){
        scanf("%d", &n);
        scanf("%d", &m);
        sum1 = 0;
        sum2 = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &v1[i]);
            sum1 = sum1 + v1[i];
        }
        for(int i=0; i<m; i++){
            scanf("%d", &v2[i]);
            sum2 = sum2 + v2[i];
        }
        // Ordering
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1;j++){
                if(v1[j]>v1[j+1]){
                    temp = v1[j];
                    v1[j] = v1[j+1];
                    v1[j+1] = temp;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m-1; j++){
                if(v2[j]<v2[j+1]){
                    temp = v2[j];
                    v2[j] = v2[j+1];
                    v2[j+1] = temp;
                }
            }
        }
        // Process
        ops = 0;
        if(sum1<=sum2){
            pos = 0;
            while(sum1<=sum2 && pos<n && pos<m){
                sum1 = sum1-v1[pos]+v2[pos];
                sum2 = sum2-v2[pos]+v1[pos];
                ops++;
                pos++;
            }
            if(sum1<=sum2){
                ops = -1;
            }
        }
        printf("%d\n", ops);
	}
	return 0;
}