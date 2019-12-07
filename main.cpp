/*
 * main.cpp
 *
 *  Created on: 5 Dec 2019
 *      Author: sergeynasekin
 */

#include <chrono>

#include "CSVReader.h"
#include "Peacock3Dim.h"

using namespace std;

int main() {

	// Initialize 2 samples
	vector < vector<double> > sample_1;
	vector < vector<double> > sample_2;

	// Initialize readers and samples
	CSVReader reader_1("/Users/sergeynasekin/eclipse_workspace_cpp/Peacock3/sample_1.csv");
	// CSVReader reader_2 = reader_1;
	CSVReader reader_2("/Users/sergeynasekin/eclipse_workspace_cpp/Peacock3/sample_2.csv");
	sample_1 = reader_1.readFile();
	sample_2 = reader_2.readFile();

	// Initialize the test object
	Peacock3Dim peacock3dim(sample_1, sample_2);

	// Run the test and do timing
	auto start = chrono::steady_clock::now();
	double ks_3d_stat = peacock3dim.get_peacock_3d_stat();
	auto end = chrono::steady_clock::now();
	auto time_diff = end - start;


	cout << "Test statistic is: " << ks_3d_stat << "\n"
			<< "Test statistic calculation takes "
			<< chrono::duration<double, milli>(time_diff).count() / 60000.0
			<< " minutes" << endl;

	return 0;
}

