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
	string fileName_A, fileName_b, fileName_x;	//����� ������ ��� ������
	bool fileExists_A, fileExists_b, goodData_x;	//�������/��������� ������/������ �/�� �����
	vector <double> a;	//������������� ������� ������������� � � ������
	vector <double> b;	//������ ��������� ������
public:
	int set_A_b(string file_A, string file_b);	//������ � �������� ������
	bool print_x_tofile(vector <double> x, string file_x);	//����� ������� � � ����
	vector <double> get_A();	//���������� ��������
	vector <double> get_b();	//

	FileInOut() : fileExists_A(false), fileExists_b(false), goodData_x(false), fileName_A(), fileName_b(), fileName_x()
	{}
};

#endif
