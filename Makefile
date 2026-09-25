
all:
	g++ -Wall TimeCodeTests.cpp TimeCode.cpp -o tct
	g++ -Wall NASALaunchAnalasys.cpp TimeCode.cpp -o nasa
	g++ -Wall PaintDryTimer.cpp TimeCode.cpp -o paint
	
nasa:
	g++ -Wall NASALaunchAnalasys.cpp TimeCode.cpp -o nasa
	
paint:
	g++ -Wall PaintDryTimer.cpp TimeCode.cpp -o paint
