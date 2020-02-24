#include<iostream>
#include<string>
using namespace std;

class Time
{
	friend class Bus;
	char s[6];
	char a[6];
	int start;
	int arrive;
	int interval;
public:
	Time& init(char m[],char n[]);
	void save();
};
