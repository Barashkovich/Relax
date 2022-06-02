
#include <iostream>
#include <vector>
#include "InOut.h"
#include "Relax.h"

int main()
{
	cout << "System of linear equations is solved" << endl;
	const string FILE_NAME_A2("AMatrix_5x5.txt"), FILE_NAME_b2("bVector_5x1.txt"), FILE_NAME_x2("xVector_5x1.txt");
	FileInOut fio2;
	Relax g2(5);
	bool goodSet = false;

	if (!fio2.set_A_b(FILE_NAME_A2, FILE_NAME_b2))
		goodSet = g2.set_A_b(fio2.get_A(), fio2.get_b());
	else
	{
		cout << ".txt files hasn't been read" << endl;
		return 1;
	}
	if (!goodSet)
	{
		cout << ".txt files are empty, or A matrix isn't square" << endl;
		return 2;
	}
	bool goodPrint = false;
	if (g2.find_x())
		goodPrint = fio2.print_x_tofile(g2.get_x(), FILE_NAME_x2);
	else
	{
		cout << "A matrix or b vector sizes don't match" << endl;
		return 3;
	}
	if (!goodPrint)
	{
		cout << "file cannot be written " << endl;
		return 4;
	}
	cout << "It`s OK" << endl;

	cin.get();
	return 0;
}