#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int x[100+1] = {0};
	int y[100+1] = {0};

	while(n--) {
		
		int xp,yp;
		scanf("%d %d", &xp, &yp);
		x[xp]++;
		y[yp]++;
		
	}

	int x_, y_;
	x_ = y_ = 0;
	for(int i=0; i<=100; i++) {
		if(x[i]) x_++;
		if(y[i]) y_++;
	}

	printf("%d\n", (x_>y_)? y_:x_);

}
