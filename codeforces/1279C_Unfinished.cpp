#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;
	scanf("%d", &T);

	while(T--) {
		
		int a,b;
		scanf("%d %d", &a, &b);
		
		int gifts[a];
		int list[a];
		bool taken[a];

		memset(gifts, 0, a*sizeof(int));
		memset(list, 0, a*sizeof(int));
		memset(taken, 0, a*sizeof(bool));


		// Storing the gifts
		for(int i=0; i<a; i++){
			int g;
			scanf("%d", &g);
			gifts[i] = --g;
		}
		
		// Getting presents list
		for(int i=0; i<b; i++){
			int l;
			scanf("%d", &l);
			list[i] = --l;
		}

		for(int i=b; i<a; i++) list[i] = -1;

		int time = 0;
		for(int i=0; i<b; i++) {

			int j = 0, k = 0;
			
			if(taken[i]) {
				time++;
				continue;
			}
			
			while(list[i] != gifts[j]) {
				
				if(list[j] != -1 && !taken[list[j]]) {
					taken[list[j]] = true;
					k++;
				}
				else if(list[j] == -1) k++;

				j++;
			}
			
			taken[list[j]] = true;
			time += 2*k + 1;
		}
		
		printf("%d\n", time);
	}
}

/*
This version does not perform well in large cases (Time Limit) but it's logic seems to be fine.
int main() {

	int T;
	scanf("%d", &T);

	while(T--) {
	
		int a,b;
		scanf("%d %d", &a, &b);

		int gifts[a];
		list<int> toGive;
		list<int> temp;
		list<int> giftStack;
		int time = 0;

		for(int i=0; i<a; i++) {
			
			int n;
			scanf("%d", &n); n--;
			
			gifts[i] = -1; // Flag for gifts not in Santa's list
			gifts[n] = 0; // Flag for gifts in the list

			giftStack.push_back(n);

		}

		for(int i=0; i<b; i++) {

			int n;
			scanf("%d", &n); n--;
			toGive.push_back(n);

		}

		while( !toGive.empty() ) {
			
			int gift = *(toGive.begin());
			int currGift = *(giftStack.begin());
			
			while(gift != currGift){
				
				time++;
				giftStack.pop_front();
				temp.push_back(currGift);
				currGift = *(giftStack.begin());
			}
			
			time++;
			giftStack.pop_front();
			toGive.pop_front();
			gifts[gift] = 1;

			auto it = temp.begin();
			while(it != temp.end()) {
				
				// If you have a present that doesn't have to be taken, put it back first
				if(gifts[*it] == -1) {
					time++;
					giftStack.push_front(*it);
					it = temp.erase(it);
				}
				else it++;

			}
			
			it = temp.begin();
			auto it2 = toGive.end(); it2--;
			while(!temp.empty()) {

				// Put back from temp to stack in reverse order from which they appear in toGive
				if(*it == *it2) {
					time++;
					giftStack.push_front(*it);
					it = temp.erase(it);
				}
				else if (it2 == toGive.begin() ) it2 = toGive.end();
				it2--;
			}
		}

		printf("%d\n", time);
	}
}
*/
