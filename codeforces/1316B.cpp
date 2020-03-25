#include <algorithm>
#include <string>
#include <iostream>

int main() {


	int T;
	std::cin >> T;

	while(T--) {
	
		int N, ans, k, pos;
		char c;
		std::string s;

		std::cin >> N;
		std::cin >> s;

		pos = 0;
		k = s.size();
	
		int ct = s.size();
		while(ct--) {
			
			c = s[s.size()-1];
			bool changed = false;
			for(int i=s.size()-1; i>=pos; i--){
				std::cout << "trying " << s[i] << "\n";
				if(s[i] < c) {
					std::cout << "Swapping " << c << " for " << s[i] << " and " << k << " for " << i+1 << "\n";
					c = s[i];
					k = i+1;
					changed = true;
				}
			}

			if(!changed) break;
			
			pos = k-1;
			size_t size = N-k+1;
			for(int i=0; i<size; i++)
				std::reverse(s.begin()+i, s.begin()+i+k);
			std::cout << "Reverse #" << pos+1 << " from " << s << "\n";
			std::cout << "k " << k << "\n";

		}
			
		std::cout << s << "\n" << k << "\n";
		
	}

}
