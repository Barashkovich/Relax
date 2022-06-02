#pragma once
#ifndef RELAX_H
#define RELAX_H

#include <iostream>
#include <vector>
#include <cfloat> 

using std::cin;
using std::cout;
using std::endl;
using std::vector;


class Relax
{
private:
	const size_t nn;

	vector<vector<double>> transpose(const vector<vector<double>>& A)
	{
		vector<vector<double>> At;	//в At храниться транспонированная матрица А
		At.resize(A[0].size());
		for (size_t zi = 0; zi < At.size(); zi++)
			At[zi].resize(A.size());
		for (size_t zi = 0; zi < A[0].size(); zi++)
			for (size_t zj = 0; zj < A.size(); zj++)
			{
				At[zi][zj] = A[zj][zi];
			}

		return At;
	};
	vector<vector<double>> MatricesMultiplication(const vector<vector<double>>& A, const vector<vector<double>>& B)
	{
		vector<vector<double>> AB;//тут хранится положительно определённая матрица полученная в результате умножении слева матрицы А на At
		size_t nn = A.size();
		AB.resize(nn);
		for (size_t i = 0; i < nn; i++)
		{
			AB[i].resize(nn);
			for (size_t j = 0; j < nn; j++)
				for (size_t k = 0; k < nn; k++)
					AB[i][j] += A[i][k] * B[k][j];
		}
		return AB;
	};
	vector<double> MatrixVectorMultiplication(const vector<vector<double>>& A, const vector<double>& vect)
	{
		vector<double> Ab;	//отвечает за хранение ввектора b посе транспонирования

		size_t nn = A.size();
		Ab.resize(nn);
		for (size_t i = 0; i < nn; i++)
		{
			double temp = 0;
			for (size_t j = 0; j < nn; j++)
			{
				temp += A[i][j] * vect[j];
			}
			Ab[i] = temp;
		}
		return Ab;
	};

	vector<double> x;	//отвечает за хранение вектора х
	vector<vector<double>>A;//
	vector<double> vect;
	bool goodData;	//проверка на удачное или неудачное решение
public:
	bool set_A_b(vector<double>, vector<double>);
	bool find_x();	//решение СЛАУ
	vector<double> get_x();	//возвращение х
	Relax(size_t _n = 3) : nn(_n < 2 ? 2 : _n > 10 ? 10 : _n), goodData(false)
	{}
};

#endif#pragma once
