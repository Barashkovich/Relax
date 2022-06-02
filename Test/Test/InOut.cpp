#include "InOut.h" 

vector<double> FileInOut::get_A()
{
	return a;
}

vector<double> FileInOut::get_b()
{
	return b;
}

int FileInOut::set_A_b(string file_A, string file_b)
{
	fileName_A = file_A;
	fileName_b = file_b;
	fileExists_A = false;
	fileExists_b = false;
	goodData_x = false;
	fstream fInA, fInB;

	fInA.open(fileName_A.c_str(), std::ios::in);
	if (!fInA)
	{
		cout << "File '" << fileName_A << "' can not exist." << endl;
		return 1;
	}
	else fileExists_A = true;

	fInB.open(fileName_b.c_str(), std::ios::in);
	if (!fInB)
	{
		cout << "File '" << fileName_b << "' can not exist." << endl;
		fInA.close();
		return 2;
	}
	else fileExists_b = true;

	double t;
	a.resize(0);
	while (fInA >> t)
		a.push_back(t);

	fInA.close();
	if (a.empty())
	{
		cout << "File '" << fileName_A << "' empty." << endl;
		fInB.close();
		return 3;
	}

	b.resize(0);
	while (fInB >> t)
		b.push_back(t);

	fInB.close();
	if (b.empty())
	{
		cout << "File '" << fileName_b << "' empty." << endl;
		return 4;
	}

	goodData_x = true;
	return 0;
}

bool FileInOut::print_x_tofile(vector <double> x, string file_x)
{
	goodData_x = true;
	fileName_x = file_x;

	if (!x.size())
	{
		goodData_x = false;
		cout << "Vector x is empty." << endl;
		return goodData_x;
	}

	fstream fOutx;
	fOutx.open(fileName_x.c_str(), std::ios_base::in);

	fOutx.close();
	if (fOutx.fail())
		fOutx.clear();

	fOutx.open(fileName_x.c_str(), std::ios::out);
	if (!fOutx)
	{
		goodData_x = false;
		cout << "Fail in writing to file " << fileName_x << "" << endl;
		return goodData_x;
	}

	for (size_t i = 0; i < x.size(); i++)
		fOutx << x[i] << endl;

	fOutx.close();
	return goodData_x;
	return 1;
}
