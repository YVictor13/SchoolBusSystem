#include<iostream>
#include<string>
using namespace std;
class Card
{
	friend class Teacher;
	friend class Student;
	friend class Limit;
	string name;
	string id;
	int card_num;
	string company;
	int money;
	int times;
public:
//	Card(string nname,int num,int cardnum,string com);
	Card& init(string nname,int num,int cardnum,string com,int mon=0,int t=0);
	void del(int num);
	void ask_inform(int num);
	void ask_money(int num);
	void ask_times(int num);
	bool money_out();
	void save();
};

class Teacher:public Card
{
public:
//	Teacher(string nname,int num,int cardnum,string com):Card(nname,num,cardnum,com){};
	virtual Card& add_money(int num,int n);
	virtual Card& use(int num);
};

class Student:public Card
{
public:
//	Student(string nname,int num,int cardnum,string com):Card(nname,num,cardnum,com){};
	virtual Card& add_money(int num,int n);
	virtual Card& use(int num);
};

class Limit:public Card
{
public:
//	Limit(string nname,int num,int cardnum,string com):Card(nname,num,cardnum,com){};
	virtual Card& add_money(int num,int n);
	virtual Card& use(int num);
};


