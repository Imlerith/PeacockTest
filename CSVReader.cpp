/*
 * CSVReader.cpp
 *
 *  Created on: 24 Oct 2019
 *      Author: naseser
 */

#include "CSVReader.h"

CSVReader::CSVReader(string fname) :
		filename(fname) {
}

CSVReader::CSVReader(string fname, string delim) :
		filename(fname), delimiter(delim) {
}

CSVReader::CSVReader(const CSVReader& other) {
	this->delimiter = other.delimiter;
	this->filename = other.filename;
}

vector<vector<double> > CSVReader::readFile() {
	// initialize empty array
	vector<vector<double> > sample;

	// read the file into the array
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		stringstream iss(line);
		string val;
		vector<double> row;
		while (getline(iss, val, ',')) {
			double val_num = stod(val);
			row.push_back(val_num);
		}
		sample.push_back(row);
	}
	// close fstream
	file.close();

	return sample;
}

