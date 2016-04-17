#ifndef CHEBYSHEV_H
#define CHEBYSHEV_H
#include "math.h"
#include <vector>

using namespace std;

struct Chebyshev {
	int n, m;
	vector<double> c;
	double a, b;

	Chebyshev(vector<double> &pc);

	Chebyshev(double func(double), double aa, double bb, int nn);

	Chebyshev(vector<double> &cc, double aa, double bb)
		: n(cc.size()), m(n), c(cc), a(aa), b(bb) {}

	int setm(double thresh) {
		while (m>1 && abs(c[m - 1])<thresh) 
			m--; 
		return m; 
	}

	double eval(double x, int m);

	inline double operator() (double x) { 
		return eval(x, m); 
	}

	Chebyshev derivative();

	Chebyshev integral();

	vector<double> polycofs(int m);

		
	inline vector<double> polycofs() {
		return polycofs(m); 
	}

};


/*-----------------------------------------------------*/

Chebyshev::Chebyshev(vector<double> &d)
	: n(d.size()), m(n), c(n), a(-1.), b(1.)
{
	c[n - 1] = d[n - 1];

	c[n - 2] = 2.0*d[n - 2];

	for (int j = n - 3; j >= 0; j--) {
		c[j] = 2.0*d[j] + c[j + 2];
		for (int i = j + 1; i<n - 2; i++) {
			c[i] = (c[i] + c[i + 2]) / 2;
		}
		c[n - 2] /= 2;
		c[n - 1] /= 2;
	}
}

Chebyshev::Chebyshev(double func(double), double aa, double bb, int nn = 50)
	: n(nn), m(nn), c(n), a(aa), b(bb)
{
	const double pi = 3.141592653589793;

	int k, j;

	double fac, bpa, bma, y, sum;

	vector<double> f(n);

	bma = 0.5*(b - a);

	bpa = 0.5*(b + a);

	for (k = 0; k<n; k++) {
		y = cos(pi*(k + 0.5) / n);
		f[k] = func(y*bma + bpa);
	}

	fac = 2.0 / n;

	for (j = 0; j<n; j++) {
		sum = 0.0;
		for (k = 0; k<n; k++)
			sum += f[k] * cos(pi*j*(k + 0.5) / n);
		c[j] = fac*sum;
	}
}


double Chebyshev::eval(double x, int m)
{
	double d = 0.0, dd = 0.0, sv, y, y2;
	int j;

	if ((x - a)*(x - b) > 0.0) 
		throw("x not in range in Chebyshev::eval");

	y2 = 2.0*(y = (2.0*x - a - b) / (b - a)); 

	for (j = m - 1; j>0; j--) {
		sv = d;
		d = y2*d - dd + c[j];
		dd = sv;
	}

	return y*d - dd + 0.5*c[0];
}

Chebyshev Chebyshev::derivative()
{
	int j;

	double con;

	vector<double> cder(n);

	cder[n - 1] = 0.0;

	cder[n - 2] = 2 * (n - 1)*c[n - 1];

	for (j = n - 2; j>0; j--)
		cder[j - 1] = cder[j + 1] + 2 * j*c[j];
	
	con = 2.0 / (b - a);

	for (j = 0; j < n; j++) 
		cder[j] *= con;

	return Chebyshev(cder, a, b);
}

Chebyshev Chebyshev::integral()
{
	int j;

	double sum = 0.0, fac = 1.0, con;
	
	vector<double> cint(n);

	con = 0.25*(b - a);

	for (j = 1; j<n - 1; j++) {
		cint[j] = con*(c[j - 1] - c[j + 1]) / j;
		sum += fac*cint[j];
		fac = -fac;
	}
	cint[n - 1] = con*c[n - 2] / (n - 1);

	sum += fac*cint[n - 1];

	cint[0] = 2.0*sum;
	
	return Chebyshev(cint, a, b);
}

vector<double> Chebyshev::polycofs(int m)
{
	int k, j;

	double sv;

	vector<double> d(m), dd(m);

	for (j = 0; j<m; j++) 
		d[j] = dd[j] = 0.0;

	d[0] = c[m - 1];

	for (j = m - 2; j>0; j--) {
		for (k = m - j; k>0; k--) {
			sv = d[k];
			d[k] = 2.0*d[k - 1] - dd[k];
			dd[k] = sv;
		}

		sv = d[0];
		d[0] = -dd[0] + c[j];
		dd[0] = sv;
	}

	for (j = m - 1; j>0; j--) 
		d[j] = d[j - 1] - dd[j];

	d[0] = -dd[0] + 0.5*c[0];

	return d;
}



#endif // CHEBYSHEV_H