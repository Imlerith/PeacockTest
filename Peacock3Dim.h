/*
 * Peacock3Dim.h
 *
 *  Created on: 5 Dec 2019
 *      Author: sergeynasekin
 */

#ifndef PEACOCK3DIM_H_
#define PEACOCK3DIM_H_

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <cstddef>

using namespace std;

class Peacock3Dim {
private:
	const double tol = 1.0e-6;
	int n1;
	int n2;
	int n;
	int dd;
	int L;
	int d1;
	int d2;
	vector<double> s_2_col_1;
	vector<double> s_2_col_2;
	vector<double> s_2_col_3;
	vector<double> xy1;
	vector<double> xy2;
	vector<double> xy3;
	vector<size_t> indices_1;
	vector<size_t> indices_2;
	vector<size_t> indices_3;

public:
	Peacock3Dim(vector<vector<double> > sample_1,
			vector<vector<double> > sample_2);

	int gcd(int a, int b);

	vector<double> extract_col(vector<vector<double> > matrix, int col_idx);

	template<typename T>
	vector<size_t> sort_indices(const vector<T>& v);

	bool isEqual(double a, double b);

	double get_peacock_3d_stat();

};

#endif /* PEACOCK3DIM_H_ */
