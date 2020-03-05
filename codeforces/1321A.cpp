#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int rc[n];
    int bs[n];

    int rc_n = 0;
    int bs_n = 0;

    for(int i=0; i<n; i++) scanf("%d", &rc[i]);
    for(int i=0; i<n; i++) scanf("%d", &bs[i]);
    
    // Counting points
    for(int i=0; i<n; i++) {
        if(rc[i] && bs[i]==0) rc_n++;
        if(bs[i] && rc[i]==0) bs_n++;
    }

    // Checking if they scored in the same questions
    bool equals = true;
    for(int i=0; i<n; i++) { 
        equals = bs[i] && rc[i];
        if(!equals) break;
    }

    if(rc_n == 0 || equals) cout << "-1" << "\n";
    else cout << bs_n/rc_n + 1 << "\n";

    return 0;

}