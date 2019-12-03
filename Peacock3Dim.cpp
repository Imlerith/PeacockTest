/*
 * Peacock3Dim.cpp
 *
 *  Created on: 3 Dec 2019
 *      Author: Sergey
 */

#include "Peacock3Dim.h"

Peacock3Dim::Peacock3Dim() = default;

Peacock3Dim::~Peacock3Dim() = default;

Peacock3Dim::Peacock3Dim(vector<vector<double> > sample_1,
		vector<vector<double> > sample_2) {
	n1 = sample_1.size();
	n2 = sample_2.size();
	n = n1 + n2;
	dd = gcd(n1, n2);
	L = n1 / dd * n2;
	d1 = L / n1;
	d2 = L / n2;

	xy1 = extract_col(sample_1, 1);
	xy2 = extract_col(sample_1, 2);
	xy3 = extract_col(sample_1, 3);

	s_2_col_1 = extract_col(sample_2, 1);
	s_2_col_2 = extract_col(sample_2, 2);
	s_2_col_3 = extract_col(sample_2, 3);

	xy1.insert(xy1.end(), s_2_col_1.begin(), s_2_col_1.end());
	xy2.insert(xy2.end(), s_2_col_2.begin(), s_2_col_2.end());
	xy3.insert(xy3.end(), s_2_col_3.begin(), s_2_col_3.end());

	indices_1 = sort_indices(xy1);
	indices_2 = sort_indices(xy2);
	indices_3 = sort_indices(xy3);

	sort(xy1.begin(), xy1.end());
	sort(xy2.begin(), xy2.end());
}

int Peacock3Dim::gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

vector<double> Peacock3Dim::extract_col(vector<vector<double> > matrix,
		int col_idx) {
	vector<double> col;
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (int j = col_idx; j < col_idx + 1; j++) {
			col.push_back(matrix[i][j]);
		}
	}
	return col;
}

template<typename T>
vector<int> Peacock3Dim::sort_indices(const vector<T> &v) {

	// initialize original index starting from 0
	vector<int> idx(v.size());
	iota(idx.begin(), idx.end(), 0);

	// sort index comparing values in array
	sort(idx.begin(), idx.end(), [&v](int i1, int i2) {return v[i1] < v[i2];});

	return idx;
}

int Peacock3Dim::get_peacock_3d_stat() {
	int max_hnnn = 0;
	int max_hnpn = 0;
	int max_hpnn = 0;
	int max_hppn = 0;

	int max_hnnp = 0;
	int max_hnpp = 0;
	int max_hpnp = 0;
	int max_hppp = 0;

	for (const double& zu : xy1) {
		for (const double& zv : xy2) {
			int hnnn = 0;
			int hnpn = 0;
			int hpnn = 0;
			int hppn = 0;

			int t = 0;

			while (t < n) {
				int& w = indices_3[t];

				if (xy1[w] <= zu) {
					if (xy2[w] <= zv) {

						if (w <= n1) {
							hnnn += d1;
						} else {
							hnnn -= d2;
						}

						max_hnnn = max(max_hnnn, abs(hnnn));

					} else {

						if (w <= n1) {
							hnpn += d1;
						} else {
							hnpn -= d2;
						}

						max_hnpn = max(max_hnpn, abs(hnpn));

					}
				} else {
					if (xy2[w] <= zv) {

						if (w <= n1) {
							hpnn += d1;
						} else {
							hpnn -= d2;
						}

						max_hpnn = max(max_hpnn, abs(hpnn));

					} else {

						if (w <= n1) {
							hppn += d1;
						} else {
							hppn -= d2;
						}

						max_hppn = max(max_hppn, abs(hppn));

					}
				}

				t++;

			}

			int hnnp = 0;
			int hnpp = 0;
			int hpnp = 0;
			int hppp = 0;

			t = n - 1;

			while (t > 0) {
				int& w = indices_3[t];

				if (xy1[w] <= zu) {
					if (xy2[w] <= zv) {

						if (w <= n1) {
							hnnp += d1;
						} else {
							hnnp -= d2;
						}

						max_hnnp = max(max_hnnp, abs(hnnp));

					} else {

						if (w <= n1) {
							hnpp += d1;
						} else {
							hnpp -= d2;
						}

						max_hnpp = max(max_hnpp, abs(hnpp));

					}
				} else {
					if (xy2[w] <= zv) {

						if (w <= n1) {
							hpnp += d1;
						} else {
							hpnp -= d2;
						}

						max_hpnp = max(max_hpnp, abs(hpnp));

					} else {

						if (w <= n1) {
							hppp += d1;
						} else {
							hppp -= d2;
						}

						max_hppp = max(max_hppp, abs(hppp));

					}
				}

				t--;

			}

		}

	}

	int stats[] = { max_hnnn, max_hnpn, max_hpnn, max_hppn, max_hnnp, max_hnpp,
			max_hpnp, max_hppp };
	return *max_element(stats, stats + 8);
}



