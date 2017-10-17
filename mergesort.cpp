#include <iostream>
#include <cassert>

using namespace std;

void ComB (int a[], int x[], int MiD,int s , int e){
	
	int i = s;

	int j = MiD + 1;

	int k = 0;

	while(i <= MiD && j <= e){

		if(a[i] < a[j]){

			x[k] = a[i];
			k++;
			i++;
		}

		else{
			x[k] = a[j];
			k++;
			j++;
		}
	}

	while(i <= MiD){
 		x[k] = a[i];
                k++;
                i++;
	}

	while(j <= e){
		x[k] = a[j];
                k++;
                j++;
	}

	for (i = s; i <= e; i++){
		a[i] = x[i - s];
	}
		
}

void msort(int a[], int x[], int s, int e) {
	
	if (e - s < 1) return;

	int MiD = (s + e) / 2; 

	msort(a, x, s, MiD);

	msort(a, x, MiD + 1, e);

	ComB (a, x, MiD, s, e);
}

void mergesort(int a[], int n) {

	int * x = new int[n];

	msort(a, x, 0, n - 1);

	delete[]x;
}


bool sorted(int a[], int n){

	for (int i = 0; i < n - 1; ++i) {

		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int main(int argc, char * args[]) {

	int a[1000];
	
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;

	mergesort(a, 1000);
	
	assert(sorted(a, 1000));

	int b[1001];
	
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;

	mergesort(b, 1001);

	assert(sorted(b, 1001));

	int c[] = { 2 };

	mergesort(c, 1);

	assert(sorted(c, 1));

	int d[] = { 1, 2, 3, 4, 5 };

	mergesort(d, 5);

	assert(sorted(d, 5));

//*/

	cout << "All tests passed." << endl;
}
