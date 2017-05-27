#include <iostream>
using namespace std;

int main() {
	int i = 20;
	
	for(int n=1; n<=i; n++) {	
		for(int s=0; s<=(i-n-1); s++) { cout << " "; }
		for(int x=1; x<=n*2-1; x++) { cout << "X"; }
		cout << '\n';
	}
	return 0;
}


