#include "TimeCode.h"
#include <iostream>

TimeCode::TimeCode(unsigned int hr, unsigned int min, long long unsigned int sec) {
	t = (hr * 3600) + (min * 60) + sec;
}

TimeCode::TimeCode(const TimeCode& tc) {
	t = tc.t; //used google summary feature to get t value from other TimeCode
}

//set functions
void TimeCode::SetHours(unsigned int hours) { // set functions changes hr/min/sec by subtracting then adding
	unsigned int hr, min, sec;
	GetComponents(hr, min, sec); //use GetComponents to decrease redundancy with codee
	t = t - (hr * 3600) + (hours * 3600);
}

void TimeCode::SetMinutes(unsigned int minutes) {
	unsigned int hr, min, sec;
	GetComponents(hr, min, sec);
	t = t - (min * 60) + (minutes * 60);
}

void TimeCode::SetSeconds(unsigned int second){
	unsigned int hr, min, sec;
	GetComponents(hr, min, sec);
	t = t - (sec) + (second);
}

void TimeCode::reset() {
	t = 0;
}

//get functions
unsigned int TimeCode::GetHours() const{
	return t / 3600;
}

unsigned int TimeCode::GetMinutes() const{
	return t / 60;
}

unsigned int TimeCode::GetSecond() const{
	return t;
}

void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const {
	hr = t / 3600;
	unsigned int s = t % 3600; //save seconds after removing seconds from hours to use for min and sec calculations
	min = s / 60;
	sec = s % 60;	
}

long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned long long int sec) {
return (hr * 3600) + (min * 60) + sec;
}
 //to string fucntion
string TimeCode::ToString() const {
	unsigned int hr, min, sec;
	GetComponents(hr, min, sec);
	string TimeStr = to_string(hr) + ":" + to_string(min) + ":" + to_string(sec);
	
	return TimeStr;
}

//operator functions returning TimeCode
TimeCode TimeCode::operator+(const TimeCode& other) const{
	unsigned int timesec = other.t + t;
	
	
	return TimeCode(0, 0, timesec);
}

TimeCode TimeCode::operator-(const TimeCode& other) const{
	int timesec = t - other.t;
	if (timesec < 0) { //subtracting can result in - t value
		throw invalid_argument("Negative arguments not allowed: " + to_string(timesec));
	}
	
	return TimeCode(0, 0, timesec);	
}

TimeCode TimeCode::operator*(double a) const{
	if (a < 0) { //if statement used for * and / since double is not unsigned
		throw invalid_argument("Negative arguments not allowed: " + to_string(a));
	}
	
	unsigned int timesec = t * a;
	return TimeCode(0, 0, timesec);	
}

TimeCode TimeCode::operator/(double a) const{
	if (a < 0) {
		throw invalid_argument("Negative arguments not allowed: " + to_string(a));
	}
	
	unsigned int timesec = t / a; 
	return TimeCode(0, 0, timesec);
}

//operator functions returning bool
bool TimeCode::operator == (const TimeCode& other) const {
	if (other.t == t) {
		return true;
	}
	return false;
}

bool TimeCode::operator != (const TimeCode& other) const{
	if (other.t != t) {
		return true;
	}
	return false;
}

bool TimeCode::operator < (const TimeCode& other) const{
	if (other.t < t) {
		return true;
	}
	return false;	
}

bool TimeCode::operator<= (const TimeCode& other) const{
		if (other.t <= t) {
		return true;
	}
	return false;
}

bool TimeCode::operator > (const TimeCode& other) const{
		if (other.t > t) {
		return true;
	}
	return false;
}

bool TimeCode::operator >= (const TimeCode& other) const{
		if (other.t >= t) {
		return true;
	}
	return false;
}
