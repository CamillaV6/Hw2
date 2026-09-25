#include <iostream>
#include <assert.h>
using namespace std;

#include "TimeCode.h"


void TestComponentsToSeconds(){
	cout << "Testing ComponentsToSeconds" << endl;
	
	// Random but "safe" inputs
	long long unsigned int t = TimeCode::ComponentsToSeconds(3, 17, 42);
	assert(t == 11862);
	
	t = TimeCode::ComponentsToSeconds(3, 63, 62);
	assert(t == (3 * 3600) + (60 * 63) + 62);
	
	cout << "PASSED!" << endl << endl;
}


void TestDefaultConstructor(){
	cout << "Testing Default Constructor" << endl;
	TimeCode tc;
	
	//cout << "Testing ToString()" << endl;
	//cout << "tc: " << tc.ToString() << endl;
	assert(tc.ToString() == "0:0:0");
	
	cout << "PASSED!" << endl << endl;
}


void TestComponentConstructor(){
	cout << "Testing Component Constructor" << endl;
	TimeCode tc = TimeCode(0, 0, 0);
	//cout << "Testing ToString()" << endl;
	//cout << "tc: " << tc.ToString() << endl;
	assert(tc.ToString() == "0:0:0");
	
	// Roll-over inputs
	TimeCode tc3 = TimeCode(4, 11, 3801);
	cout << "tc3: " << tc3.ToString() << endl;
	assert(tc3.ToString() == "5:14:21");
	
	cout << "PASSED!" << endl << endl;
}


void TestGetComponents(){
	cout << "Testing GetComponents" << endl;
	
	unsigned int h;
	unsigned int m;
	unsigned int s;
	
	// Regular values
	TimeCode tc = TimeCode(5, 2, 18);
	tc.GetComponents(h, m, s);
	assert(h == 5 && m == 2 && s == 18);
	
	unsigned int h2, m2, s2;
	TimeCode test2 = TimeCode(0, 62, 0);
	test2.GetComponents(h2, m2, s2);
	assert (h2 == 1 && m2 == 2 && s2 == 0);
	
	cout << "PASSED!" << endl << endl;
}


void TestSubtract(){
	cout << "Testing Subtract" << endl;
	TimeCode tc1 = TimeCode(1, 0, 0);
	TimeCode tc2 = TimeCode(0, 50, 0);
	TimeCode tc3 = tc1 - tc2;
	assert(tc3.ToString() == "0:10:0");
	
	
	TimeCode tc4 = TimeCode(1, 15, 45);
	try{
		TimeCode tc5 = tc1 - tc4;
		cout << "tc5: " << tc5.ToString() << endl;
		assert(false);
	}
	catch(const invalid_argument& e){
		// just leave this empty
		// and keep doing more tests
	}

	// more tests
	
	cout << "PASSED!" << endl << endl;
}


void TestSetMinutes()
{
	cout << "Testing SetMinutes" << endl;

	TimeCode tc = TimeCode(8, 5, 9);
	tc.SetMinutes(15); // test valid change
	assert(tc.ToString() == "8:15:9");

	try
	{
		tc.SetMinutes(80);  // test invalid change
		assert(false);
	}
	catch (const invalid_argument &e)
	{
		// cout << e.what() << endl;
	}

	assert(tc.ToString() == "8:15:9");

	cout << "PASSED!" << endl << endl;
}


void TestGetSeconds(){
	cout << "Testing GetSeconds" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	assert(tc.GetSeconds() == 9);
	cout << "PASSED!" << endl << endl;
}

void TestSetSeconds(){
	cout << "Testing SetSeconds" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	
	// test 1
	tc.SetSeconds(19);
	assert(tc.ToString() == "8:5:19");
	
	// test 2
	try{
		tc.SetSeconds(80);
	}
	catch( const invalid_argument& e) {
	}
	assert(tc.ToString() == "8:5:19");
	
	cout << "PASSED!" << endl << endl;
}

void TestSetHours(){
	cout << "Testing SetHours" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	
	// test 1
	tc.SetHours(18);
	assert(tc.ToString() == "18:5:9");
	
	// test 2
	tc.SetHours(600);
	assert(tc.ToString() == "600:5:9");	
	
	cout << "PASSED!" << endl << endl;
}

void TestGetHours(){
	cout << "Testing GetHours" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	assert(tc.GetHours() == 8);
	cout << "PASSED!" << endl << endl;
}


void TestGetMinutes(){
	cout << "Testing GetMinutes" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	assert(tc.GetMinutes() == 5);
	cout << "PASSED!" << endl << endl;
}
	
int main(){
	
	TestComponentsToSeconds();
	TestDefaultConstructor();
	TestComponentConstructor();
	TestGetComponents();

	
	
	TestSetHours();
	TestGetHours();
	TestGetMinutes();
	TestSetMinutes();
	TestSetSeconds();
	TestGetSeconds();
	
	cout << "PASSED ALL TESTS!!!" << endl;
	return 0;
}
