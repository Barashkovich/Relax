#include "Relax.h"

vector<double> Relax::get_x()
{
	return x;
}

bool Relax::set_A_b(vector<double> a, vector<double> b)
{
	goodData = false;
	if (a.empty() || b.empty() || a.size() != nn * nn || b.size() != nn)
		return goodData;
	A.resize(nn);
	vect.resize(nn);
	for (size_t i = 0; i < nn; i++)
	{
		A[i].resize(nn);
		vect[i] = b[i];
		for (size_t j = 0; j < nn; j++)
			A[i][j] = a[i * nn + j];
	}

	goodData = true;
	return goodData;

}

bool Relax::find_x() {

	size_t k = 0;	//номер итерации
	double Eps = 0.001;	//точность эпсилон
	double omega = 1.5;	//параметр релаксации
	size_t nn = A.size();
	size_t i = 0;
	double temp2 = 0;

	if (!goodData)
		return goodData;

	vector<vector<double>> temp = transpose(A);
	A = MatricesMultiplication(temp, A);
	vect = MatrixVectorMultiplication(temp, vect);

	//Метод зейделя

	vector<double> z(A.size(), 0), zPrev(A.size(), 1), xPrev(A.size());
	double s = 0;
	x.resize(nn);
	do
	{
		for (size_t zi = 0; zi < z.size(); zi++)
		{
			double sOld = 0, sNew = 0;
			for (size_t zj = 0; zj < z.size(); zj++)
				if (zj > zi)
					sOld += A[zi][zj] * zPrev[zj];
				else if (zj < zi)
					sNew += A[zi][zj] * z[zj];
			z[zi] = (vect[zi] - sNew - sOld) / A[zi][zi];
			x[zi] = omega * z[zi] + (1 - omega) * zPrev[zi];//релаксируем значение

		}
		s = 0;
		for (size_t zi = 0; zi < z.size(); zi++)
			s += ::pow(::fabs(x[zi] - xPrev[zi]), 2.0);
		s = ::sqrt(s);

		zPrev = z;
		xPrev = x;
		k++;
	} while (s > Eps);
	cout << "k = " << k << endl;

	//vector<double> z(A.size(), 0), zPrev(A.size(), 1);
	//double s = 0;
	//do
	//{
	//	for (size_t zi = 0; zi < z.size(); zi++)
	//	{
	//		double sOld = 0, sNew = 0;
	//		for (size_t zj = 0; zj < z.size(); zj++)
	//			if (zj > zi)
	//				sOld += A[zi][zj] * zPrev[zj];
	//			else if (zj < zi)
	//				sNew += A[zi][zj] * z[zj];
	//		z[zi] = (b[zi] - sNew - sOld) / A[zi][zi];
	//	}
	//	s = 0;
	//	for (size_t zi = 0; zi < z.size(); zi++)
	//		s += ::pow(::fabs(z[zi] - zPrev[zi]), 2.0);
	//	s = ::sqrt(s);
	//	zPrev = z;
	//} while (s > Eps);

	goodData = true;
	return goodData;
}
