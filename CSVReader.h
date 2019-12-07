/*
 * CSVReader.h
 *
 *  Created on: 5 Dec 2019
 *      Author: sergeynasekin
 */

#ifndef CSVREADER_H_
#define CSVREADER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CSVReader {
private:
	string filename { "" };
	char delimiter { ',' };

public:
	CSVReader(string fname);

	CSVReader(string fname, char delim);

	CSVReader(const CSVReader& other);

	vector<vector<double> > readFile();

};

#endif /* CSVREADER_H_ */
