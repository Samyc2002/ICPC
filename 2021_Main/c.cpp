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

float height(float uy, float t, float gy)
{
	float h = (uy * t)	- 0.5 * gy * t * t;
	return h;
}

float time_period(float uy, float gy)
{
	float t = 2 * (uy / gy);
	return t;
}

float range(float ux, float t, float gx)
{
	float r = ux * t + 0.5 * gx * t * t;	
	return r;
}

float velx(float ux, float gx, float t)
{
	float v = ux + gx * t;
	return v;
}
void solve(){
    //code here.
	float h, t, angle;
	float pi = 3.1415926535897932384626433832795;
	cin >> h >> t >> angle;
	angle = pi * (angle / 180.0);

	float gy, gx, distx, disty, tp, uy, ux, nb;
	int n;

	gy = 10 * cos(angle);
	gx = 10 * sin(angle);
	uy = pow(20 * h, 0.5f) * cos(angle);
	ux = pow(20 * h, 0.5f) * sin(angle);
	tp = time_period(uy, gy);
	nb = t / tp; // number of bounces
	n = (int)(t / tp);
	float rem = nb-n;
	
	distx = 0;
	for (int i = 0; i < n; i++)
	{
		distx += range(ux, tp, gx);	
		ux = velx(ux, gx, tp);
	}
	distx += range(ux, rem, gx);
	disty = height(uy, rem, gy);
	float dist = pow(distx * distx + disty * disty, 0.5);
	cout << dist << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;  
	cin >> t;   
    while(t--){ //default test cases pattern change if neccassary
        solve();
    }
    return 0;
}
