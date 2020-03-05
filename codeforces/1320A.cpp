#include <bits/stdc++.h>
using namespace std;

struct City {
	
	int id;
	int beauty;
	int pattern;
	
};

int main() {
	
	int n;
	scanf("%d", &n);
	
	int c[n+1];
	vector<City> ans;
	ans.reserve(n);
	
	for(int i=1; i<=n; i++){
		
		scanf("%d", &c[i]);

		City ct;
		ct.id = i;
		ct.beauty = c[i];
		ct.pattern = c[i] - i;
		
		ans.push_back(ct);
	}
	
	sort(ans.begin(), ans.end(), [](const City &a, const City &b) { 
		return a.pattern > b.pattern;
	});



	long long int max = ans[0].beauty, curr = 0;
	int iBest = 0, iCurr = 0;

	for(int i=0; i<ans.size(); i++) {
		
		curr += ans[i].beauty;
		if(curr > max) {
			iBest = iCurr;
			max = curr;
		}

		if(i+1 < ans.size() && ans[i].pattern != ans[i+1].pattern){
			iCurr = i+1;
			curr = 0;
		}
	}
	
	int i = iBest;
	long long int best = 0;
	cout << max << "\n";

}