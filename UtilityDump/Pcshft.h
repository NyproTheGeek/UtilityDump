#ifndef PCSHFT_H
#define PCSHFT_H
#include <vector>

using namespace std;


void pcshft(double a, double b, vector<double> &d)
{
	int k, j, n = d.size();

	double cnst = 2.0 / (b - a), fac = cnst;

	for (j = 1; j<n; j++) {
		d[j] *= fac;
		fac *= cnst;
	}

	cnst = 0.5*(a + b);

	for (j = 0; j <= n - 2; j++)
		for (k = n - 2; k >= j; k--)
			d[k] -= cnst*d[k + 1];
}

void ipcshft(double a, double b, vector<double> &d) {
	pcshft(-(2. + b + a) / (b - a), (2. - b - a) / (b - a), d);
}

#endif // PCSHFT_H