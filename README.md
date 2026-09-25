# Hw2

TimeCode.cpp
Contains the TimeCode class, timecode takes three integers as inputs, hrs, min, sec
TimeCode class has many functions to change the TimeCode, use math operation like addition, or boolean operations like ==

TimeCodeTests.cpp
Contains tests that use TimeCode
tests are in functions that are called in the main function
values in the tests can be changed to do different tests

NasaLaunchAnalasis
takes the launch time from a csv file and calculates the average using TimeCode.cpp
If using different file, must be in the same format at the Space_Corrected.csv file

PaintDryTimer.cpp
contains DryingSnapShot struct with has three variables in it, a string name, time_t startTime, and TimeCode timeToDry
name can be used if you want to name to struct
startTime tells the initial starting time of when the paint starts drying
timeToDry tells how long it takes for the paint to dry
get_time_remaining calculates how much time is left for the paint to dry based on the time passed using the DryingSnapShot struct
drying_snap_shot_to_string is used to print out the time it takes to dry and how much time is left for the paint to dry

get_sphere_sa calculates the surface area of a sphere using the radius

compute_time_code returns a pointer to a TimeCode in the heap, make sure to use delete to delete the TimeCode at the end of the program
compute_time_code calculates the amount of time it would take paint to dry on a sphere using the surface area

