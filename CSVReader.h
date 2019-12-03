/*
 * CSVReader.h
 *
 *  Created on: 24 Oct 2019
 *      Author: Sergey
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
	string filename{""};
	string delimiter{","};

public:
	CSVReader(string fname);

	CSVReader(string fname, string delim);

	CSVReader(const CSVReader& other);

	vector<vector<double> > readFile();

};

#endif /* CSVREADER_H_ */
