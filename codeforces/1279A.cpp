#include <cstdio>
#include <iostream>
using namespace std;
int main() {

	int T;
	scanf("%d\n", &T);
	while(T--){
	
		long long int colors[4] = {0};
		int max = 4-1;
		
		for(int i=0; i<3; i++) {
			scanf("%lld", &colors[i]);
			// Getting max element
			if(colors[i] > colors[max]) colors[max] = colors[i];
		}

		long long int sum = colors[max];
		bool skipped = false;
		for(int i=0; i<3; i++) {
			if(colors[i] == colors[max] && !skipped) {
				skipped = true;
				continue;
			}
			sum -= colors[i];
		}
			
		if(sum <= 1) printf("Yes\n");
		else printf("No\n");
		
	}
	
}
