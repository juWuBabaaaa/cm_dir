#include <iostream>
#include <math.h>
using namespace std;

double fun(double x);

int main(int argc, char* argv[]) {

	cout << fun(-.5) << endl;
	return 0;
}

double fun(double x) {
	double re = -1.;
	re = (re > x) ? re:fabs(x);
	return re;
}
