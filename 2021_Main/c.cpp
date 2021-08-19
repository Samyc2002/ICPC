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

double height(double uy, double t, double gy)
{
	double h = (uy * t)	- 0.5 * gy * t * t;
	return h;
}

double time_period(double uy, double gy)
{
	double t = (2 * uy) / gy;
	return t;
}

double range(double ux, double t, double gx)
{
	double r = ux * t + 0.5 * gx * t * t;	
	return r;
}

double velx(double ux, double gx, double t)
{
	double v = ux + gx * t;
	return v;
}
void solve(){
    //code here.
	double h, t, angle;
	double pi = 3.1415926535897932384626433832795;

	cin >> h >> t >> angle;
	angle = (pi * angle) / 180.0f;

	double gy, gx, distx, disty, tp, uy, ux, nb = 0, rem = t;

	gy = 10 * cos(angle);
	gx = 10 * sin(angle);
	uy = pow(20 * h, 0.5f) * cos(angle);
	ux = pow(20 * h, 0.5f) * sin(angle);
	tp = time_period(uy, gy);

	while (rem > tp)
	{
		rem -= tp;
		nb++;
	}

	distx = range(ux, t, gx);
	disty = height(uy, rem, gy);

	double dist = pow(distx * distx + disty * disty, 0.5f);
	printf("%.10f\n",dist);
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
