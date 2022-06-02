#pragma once
#ifndef FILE_IO_H 
#define FILE_IO_H 

#include <iostream> 
#include <string>		
#include <fstream>		
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::getline;
using std::vector;

class FileInOut
{
private:
	string fileName_A, fileName_b, fileName_x;	//имена файлов для чтения
	bool fileExists_A, fileExists_b, goodData_x;	//удачное/неудачное чтение/запись в/из файла
	vector <double> a;	//запзаписываем матрицу коэффициентов А в вектор
	vector <double> b;	//Вектор свободных членов
public:
	int set_A_b(string file_A, string file_b);	//Чтение и сохрание данных
	bool print_x_tofile(vector <double> x, string file_x);	//вывод вектора х в фаил
	vector <double> get_A();	//Возвращаем значения
	vector <double> get_b();	//

	FileInOut() : fileExists_A(false), fileExists_b(false), goodData_x(false), fileName_A(), fileName_b(), fileName_x()
	{}
};

#endif
