#include <iostream>
#include <sstream>

using namespace std;

void sum(char* output, const long unsigned int d, const long unsigned int n) {
	// Initializing digits array with 0
	long unsigned int digits[d + 11];
	for (long unsigned int digit = 0; digit < d + 11; ++digit) {
		digits[digit] = 0;
	}
	// Meat of the program (Sum 1/i)
		
	for (long unsigned int i = 1; i <= n; ++i) {
		long unsigned int remainder = 1;
		// Stop at given precision (d+11) or at remainder = 0
		for (long unsigned int digit = 0; digit < d + 11 && remainder; ++digit) {
			long unsigned int div = remainder / i;
			long unsigned int mod = remainder % i;
			digits[digit] += div;
			remainder = mod * 10;
		}
	}

	// Sum decimals
	for (long unsigned int i = d + 11 - 1; i > 0; --i) {
		digits[i - 1] += digits[i] / 10;
		digits[i] %= 10;
	}

	// Round up
	if (digits[d + 1] >= 5) {
		++digits[d];
	}

	// Sum decimals	
	for (long unsigned int i = d; i > 0; --i) {
		digits[i - 1] += digits[i] / 10;
		digits[i] %= 10;
	}
	stringstream stringstreamA;
	stringstreamA << digits[0] << ".";
	for (long unsigned int i = 1; i <= d; ++i) 
		stringstreamA << digits[i];

	stringstreamA << '\0';
	string stringA = stringstreamA.str();
	stringA.copy(output, stringA.size());
}

int main() {

	long unsigned int d, n;

	cin >> d >> n;

	char output[d + 10]; // extra precision due to possible error

	sum(output, d, n);

	cout << output << endl;

	return 0;
}
