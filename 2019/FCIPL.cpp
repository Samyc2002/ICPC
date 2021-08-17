#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define gfoi(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define gfod(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define foi(i, j) gfoi(i, 0, j, 1)
#define fod(i, j) gfod(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define endl "\n"
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vii;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef pair<int, int> pii;
typedef map<int, int>::iterator mi;

int minar(int ar[], int n) {
    int min = *min_element(ar, ar + n);
    return min;
}

int maxar(int ar[], int n) {
    int max = *max_element(ar, ar + n);
    return max;
}

void swap (int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)        // function to support quicksort
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)        // to be used only for small arrays and datasets
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)          // function to support merge sort
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){          // to be used only for larger arrays or datasets
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

const int MOD = 998244353;

const int N = 111;
int fac[N], ifac[N];
int dp1[N][N], dp2[N][N];

int C(int n, int k) {
	if(k < 0 || k > n)
		return 0;
	return (long long) fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int binpow(int base, int e) {
	int ret = 1;
	while(e) {
		if(e & 1)
			ret = (long long) ret * base % MOD;
		base = (long long) base * base % MOD;
		e >>= 1;
	}
	return ret;
}

void preprocess() {

	fac[0] = 1;
	for(int i = 1; i < N; i++)
		fac[i] = (long long) i * fac[i - 1] % MOD;

	ifac[N - 1] = binpow(fac[N - 1], MOD - 2);
	for(int i = N - 2; i >= 0; i--)
		ifac[i] = (long long) ifac[i + 1] * (i + 1) % MOD;

	dp1[0][0] = 1;

	for(int i = 1; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < j; k++)
				dp1[i][j] = (dp1[i][j] + (long long) C(j - 1, k) * dp1[i - 1][j - 1 - k] % MOD) % MOD;
		}
	}

	dp2[0][0] = 1;
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 1; k < N; k++)
				dp2[i][j] = (dp2[i][j] + (long long) C(j - 1, k) * dp2[i - 1][j - 1 - k] % MOD) % MOD;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preprocess();
    int t;
	cin >> t;
    while(t--) {
        int p, q, r;
        cin >> p >> q >> r;
        int res = 0;
        for(int i = 0; i <= r; i++) {
            res = (res + (long long) dp1[i][p] * dp2[r - i][q] % MOD) % MOD;
        }
        cout << res << endl;
    }
    return 0;
}