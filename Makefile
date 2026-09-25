
all:
	g++ -Wall TimeCodeTests.cpp TimeCode.cpp -o tct
	g++ -Wall NasaLaunchAnalasis.cpp TimeCode.cpp -o nasa
	g++ -Wall PaintDryTimer.cpp TimeCode.cpp -o paint
