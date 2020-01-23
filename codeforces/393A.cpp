#include <bits/stdc++.h>
using namespace std;

int main() {

	char c = 0;
	// Letters we are looking for
	int n = 0, i = 0, e = 0, t = 0;

	while(c != EOF) {
		c = getchar();
		
		switch (c) {
			case 'n': n++; break;
			case 'i': i++; break;
			case 'e': e++; break;
			case 't': t++; break;
			default: break;
		}
	}

	int aux, ans;
	// How many words I can write with a given amount of each char.
	// Notice that we only need 2 'n' in some cases. Hence (n-1)/2
	aux = min( (n-1)/2, e/3 ); 
	ans = min(i,t);
	// Not enough n/e means no word at all
	if(aux == 0) printf("0\n");
	else if(ans <= aux) printf("%d\n", ans);
	else printf("%d\n", aux);

}
