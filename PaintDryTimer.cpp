#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)

using namespace std;

struct DryingSnapShot {
	// This is a struct, it's like an object
	// that doesn't have any methods.
	// You can read more about them in the ZyBook
	// just search for "struct"
	string name;
	time_t startTime;
	TimeCode *timeToDry;
};

long long int get_time_remaining(DryingSnapShot dss){ 
	time_t nowTime = time(0);
	time_t difference = nowTime - dss.startTime;
	time_t Time_left = dss.timeToDry->GetTimeCodeAsSeconds() - difference;
	return Time_left;
}

string drying_snap_shot_to_string(DryingSnapShot dss){
	return "the time it takes to dry is " + dss.timeToDry->ToString() + " the time remaining is " + to_string(get_time_remaining(dss));
}

double get_sphere_sa(double rad){
	double sa = 4 * M_PI * pow(rad, 2);
	return sa;
}

TimeCode *compute_time_code(double surfaceArea){
	TimeCode *time = new TimeCode(0, 0, surfaceArea);
	return time;
}

void tests(){
	// get_time_remaining
	DryingSnapShot dss;
	dss.startTime = time(0);
	TimeCode tc = TimeCode(0, 0, 7);
	dss.timeToDry = &tc;
	long long int ans = get_time_remaining(dss);
	assert(ans > 6 && ans < 8);
	cout << drying_snap_shot_to_string(dss) << endl;
	
	// get_sphere_sa
	double sa = get_sphere_sa(2.0);
	assert (50.2654 < sa && sa < 50.2655);



	// compute_time_code
	TimeCode *tc2 = compute_time_code(1.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc2->GetTimeCodeAsSeconds() == 1);
	delete tc2;

	DryingSnapShot dss2;
	dss2.startTime = time(0);
	TimeCode tc3 = TimeCode(0, 0, 10);
	double sa2 = get_sphere_sa(3.0);
	cout << to_string(sa2) << endl;
	assert (112 < sa2 && sa2 < 114);
	TimeCode *tc4 = compute_time_code(sa2);
	dss2.timeToDry = tc4;
	ans = get_time_remaining(dss2);
	assert(112 < sa2 && sa2 < 114);
	cout << drying_snap_shot_to_string(dss2) << endl;
	
	delete tc4;
	
	


	cout << "ALL TESTS PASSED!" << endl;

}

int main(){
	
	tests();
	
	return 0;
}
