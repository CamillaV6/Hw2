#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>

#include "TimeCode.h"

using namespace std;

vector<string> split_row(string line) { //seperates each row of the file
	vector<string> row;
	stringstream l(line); //found this online as well
	
	while (getline(l, line, ',')) {
		row.push_back(line);
	}
	return row;	
}

void extract_times(string full_time, unsigned int& hour, unsigned int& min) {//takes the hour and minutes from launch times and converts to integers
	string time = full_time.substr(6,6);
	
	string hour_str = time.substr(0,2);
	string min_str = time.substr(3,5);
	
	hour = stoi(hour_str); //use passby referenc because to change both hours and minutes in one function
	min = stoi(min_str);
}

int main() {
	fstream Nasa;
	Nasa.open("Space_Corrected.csv", ios::in);
	
	string line;
	unsigned int hour, min;
	int count = 0;
	TimeCode total = TimeCode(0, 0, 0);
	
	while (getline(Nasa, line)){ //found this online
		vector<string> row = split_row(line);
		
		if (row[4].find("UTC") != string::npos) { //Finding if includes UTC because that determines if the time is included or just the year
			extract_times(row[4], hour, min);
			
			total = total.operator +(TimeCode(hour, min, 0));
			count += 1; //counts how many times TimeCode added to total to divide later
		}
	}
	total = total.operator /(count);
	cout << total.ToString() << " with " << to_string(count) << " data points" << endl;
	
	Nasa.close();
	
	return 0;
}
