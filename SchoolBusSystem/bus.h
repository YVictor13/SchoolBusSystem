#include<iostream>
#include<string>
using namespace std;

class Bus
{
	friend Card& Teacher::use(int num);
	friend Card& Student::use(int num);
	friend Card& Limit::use(int num);
	Time riding[20];
	Time c_riding[20]; 
	string bus_num;
	string bus_type;
	string rider_name;
	int person_max;
	int person_num;
	int time_num;
	int all_time;
	int c_all_time;
public:
	Bus& init(string num,string type,string rider,int person);
	Bus& f_init(string num,string type,string rider,int person);
	Bus& count(string num);
	Bus& c_time(string num);
	int if_full(string num);
	void save();
	void inform();
};