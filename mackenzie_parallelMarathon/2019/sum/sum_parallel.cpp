/* 
  
  To compile: g++ sum_parallel.cpp -O3 -fopenmp
  
  Problem: Harmonic Sum
  Input: decimal precision and sum iterations

  Optimization: The part of the code optimized was the division
  of each term, which is an independent part the whole process. 
  Also, some data structures and initialization methods were
  altered from the original (in sum.cpp). 
  
  Maybe there are even more ways to improve this code only using 
  CPU Parallelism and good practices, but for now this is 
  what I managed to achieve.

*/

#include <iostream>
#include <omp.h>
#include <string.h>

// Assuming 8 as max_threads for the machine I'm currently using (i7) 
#define NUM_THREADS 8

void sum(const long unsigned int d, const long unsigned int n) {

	long unsigned int digits[d + 11];
	long unsigned int sum[NUM_THREADS][d+11];
	
	// Fast Init
	memset(sum, 0, sizeof(long unsigned int) * NUM_THREADS * (d+11));
	memset(digits, 0, sizeof(long unsigned int) * (d+11));

	// Meat of the program (Sum 1/i while i!=n) a.k.a. Harmonic Sum
	#pragma omp parallel for 
	for (long unsigned int i = 1; i <= n; ++i) {

		long unsigned int remainder = 1;
		int id = omp_get_thread_num(); // will be used as index
		
		for (long unsigned int digit = 0; digit < d + 11; ++digit) {
			
			long unsigned int div = remainder / i;
			long unsigned int mod = remainder % i;
			
			sum[id][digit] += div; // storing each thread current sum for given digit
			remainder = mod * 10;
			// since breaks are a messy thing in OpenMP, we can use this little trick to avoid unecessary work
			digit = (remainder)?digit:(d+11); 
		}
	}

	int threads = omp_get_max_threads();
	for(int j=0; j<threads; j++)
		#pragma unroll
		for(int k=0; k<d+11; k++)
			digits[k] += sum[j][k];

	for (long unsigned int i = d + 11 - 1; i > 0; --i) {
		digits[i - 1] += digits[i] / 10;
		digits[i] %= 10;
	}

	if (digits[d + 1] >= 5)	++digits[d];

	for (long unsigned int i = d; i > 0; --i) {
		digits[i - 1] += digits[i] / 10;
		digits[i] %= 10;
	}
	
	std::cout << digits[0];
	
	// A little less costy data structure and print function
	char *output;
	output = (char*) malloc(sizeof(char)*(d+1));
	output[0] = '.';
	for (long unsigned int i = 1; i <= d; ++i) 
		output[i] = (char) digits[i] + '0';
	output[d+1] = '\0';

	printf("%s\n", output);
}

int main() {

	long unsigned int d, n;
	std::cin >> d >> n;	
	sum(d, n);

}
