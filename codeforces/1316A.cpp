#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int t,m,n;
 
    scanf("%d", &t);
    while(t--) {
        
        scanf("%d %d", &n, &m);
 
        int grades[n];
        double mean = 0;
        for(int i=0; i<n; i++) {
            
            scanf("%d", &grades[i]);
            mean += grades[i];
        }
 
        int sum = mean - grades[0];
        mean/=(1.0*n);
 
        if(mean==0) {
            cout << "0\n";
            continue;
        }
       
	   	double ans;
		int max = grades[0];
		while(true) {
		
		ans = (max + sum)/(1.0*n);

		if(ans != mean) break;

		max++;
		sum--;

		if(max > m || sum < 0) break;
		
		} 
        
		cout << max-1 << "\n";
    }
 
}
