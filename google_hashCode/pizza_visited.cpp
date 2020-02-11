// Initial implementation. No optimizations or clever stuff yet.

#include <bits/stdc++.h>
using namespace std;

#define MAX_PIZZA 10000+1


int M, N, bestSum;
bool found = false;
vector<int> pizzas;
vector<int> best_order;
bool visited[MAX_PIZZA][MAX_PIZZA] = {false};

void maxSum(int pizza, int currentSum, vector<int> current_order, bool &found)  {
	
	// If already found or exceeded the maximum slices to order, cut this branch
	if(found || currentSum > M  || pizza !=0 && visited[pizza][pizza-1]) return;

	// Check the solution quality at each node in the recursion tree
	if(currentSum > bestSum) {
		found = (currentSum==M)? true:false;
		bestSum = currentSum;
		best_order = current_order;
	}
	// No more pizza types than there is 
	if(pizza+1 >= pizzas.size()) return;
	if(pizza != 0) visited[pizza][pizza-1] = visited[pizza-1][pizza] = true;

	current_order.push_back(pizza);
	maxSum(pizza+1, currentSum + pizzas[pizza], current_order, found);
	
	current_order.pop_back();
	maxSum(pizza+1, currentSum, current_order, found);
	
}


int main() {
	
	
	scanf("%d %d", &M, &N);
	pizzas.reserve(N);

	for(int i=0; i<N; i++) {
		
		int s = -1;
		scanf("%d", &s);
		pizzas.push_back(s);
		
	}
	
	maxSum(0, 0, vector<int>(), found);

	// Checking Input
	size_t size = best_order.size();
	printf("%zu\n", size);
	for(int i=0; i<size; i++) printf("%d ", best_order[i]);
	printf("\n");
	
}
