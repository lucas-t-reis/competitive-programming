#include <bits/stdc++.h>

using namespace std;

bool ordered(vector<int> &v) {
	
	int ascending = -1;
	for(int i=0; i<v.size(); i++) {
		
		// Checking non-decreasing sequence
		if(ascending <= v[i]) ascending = v[i];
		else return false;
	
	}

	return true;
}
void thanosSort(vector<int> numbers, int side,  int &total) {

	if(numbers.size() < total) return;	// Eliminating unecessary recursions

	if(ordered(numbers))
		total = (total<numbers.size())?numbers.size():total;
	else {
		
		int size = numbers.size();
		vector<int> left (numbers.begin(), numbers.begin()+ size/2);
		vector<int> right (numbers.begin()+size/2, numbers.end() );
		thanosSort(left, 0, total);
		thanosSort(right, 1, total);
	}
}


int main() {

	
	int n;
	scanf("%d", &n);
	vector<int> v;
	v.reserve(n);
	for(int i=0; i<n; i++) {
		int num = -1;
		scanf("%d", &num);
		v.push_back(num);
	}

	int total1,total2;
	total1 = total2 = 0;
	
	thanosSort(v,0,total1);
	thanosSort(v, 1, total2);
	total1 = (total1>total2)?total1:total2;

	printf("%d\n", total1);
}
