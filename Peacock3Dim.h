/*
 * Peacock3Dim.h
 *
 *  Created on: 3 Dec 2019
 *      Author: naseser
 */

#ifndef PEACOCK3DIM_H_
#define PEACOCK3DIM_H_

#include <numeric>      // std::iota
#include <algorithm>    // std::sort
#include <vector>
#include <stdlib.h>

using namespace std;

class Peacock3Dim {
private:
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
	vector<int> indices_1;
	vector<int> indices_2;
	vector<int> indices_3;

public:
	Peacock3Dim(vector<vector<double> > sample_1,
			vector<vector<double> > sample_2);

	Peacock3Dim();

	virtual ~Peacock3Dim();

	int gcd(int a, int b);

	vector<double> extract_col(vector<vector<double> > matrix, int col_idx);

	template<typename T>
	vector<int> sort_indices(const vector<T>& v);

	int get_peacock_3d_stat();

};

#endif /* PEACOCK3DIM_H_ */
