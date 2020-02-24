#include"time.h"
#include"bus.h"
#include<fstream>
std::ifstream fin2("save2.txt");
std::ofstream fout2;

Time& Time::init(char m[],char n[])
{
	if(m[2]!=':'||n[2]!=':')return *this;
	for(int i=0;i<5;i++)
		s[i]=m[i];
	for(int j=0;j<5;j++)
		a[j]=n[j];
	a[5]=s[5]='\0';
	start=((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
	arrive=((a[0]-'0')*10+(a[1]-'0'))*60+(a[3]-'0')*10+(a[4]-'0');
	interval=arrive-start;
	return *this;
}

void Time::save()
{
	fout2<<s<<" "<<a<<" ";
}


Bus& Bus::init(string num, string type, string rider, int person)
{
	int c;
	char m[6], n[6];
	bus_num = num;
	bus_type = type;
	rider_name = rider;
	person_max = person;
	person_num = 0;
	cout << "编制运行时刻表\n运行时段数量：";
	cin >> c;
	time_num = c;
	for (int i = 0; i < c; i++){
		cout << "输入离开乘车点的时间和到达目的地的时间（XX：XX）：\n";
		cin >> m >> n;
		riding[i].init(m, n);
	}
	all_time=riding[c-1].arrive-riding[0].start;
	cout << "OK\n";
	return *this;
}

Bus& Bus::f_init(string num, string type, string rider, int person)
{
	int c;
	char m[6], n[6];
	bus_num = num;
	bus_type = type;
	rider_name = rider;
	person_max = person;
	person_num = 0;
	fin2 >> c;
	time_num = c;
	for (int i = 0; i < c; i++){
		fin2 >> m >> n;
		riding[i].init(m, n);
	}
	all_time=riding[c-1].arrive-riding[0].start;
	return *this;
}

Bus& Bus::count(string num)
{
	if (num == bus_num){
		if (person_num == person_max){
			cout << "达到载乘人数，禁止继续上车\n";
			return *this;
		}
		person_num++;
		cout << bus_num << "号车已乘坐人数：" << person_num<<endl;
		return *this;
	}
	else return *this;
}

Bus& Bus::c_time(string num)
{
	if (num == bus_num){
		char m[6], n[6];
		for (int i = 0; i < time_num; i++){
			cout << "输入实际离开乘车点的时间和到达目的地的时间（XX：XX）：\n";
			cin >> m >> n;
			c_riding[i].init(m, n);
		}
		c_all_time = c_riding[time_num - 1].arrive - c_riding[0].start;
		return *this;
	}
	else return *this;
}

void Bus::inform()
{
		double a, b, c, count1 = 0, count2 = 0;
		for (int i = 0; i < time_num; i++)
			if (riding[i].start == c_riding[i].start)count1++;
		for (int j = 0; j < time_num;j++)
			if (riding[j].arrive == c_riding[j].arrive)count2++;
		a = person_num / (double)person_max * 100;
		b = count1 / (double)time_num * 100;
		c = count2 / (double)time_num * 100;
		cout << "车牌号：" << bus_num << endl;
		cout << "型号：" << bus_type << endl;
		cout << "驾驶员姓名：" << rider_name << endl;
		cout << "实际乘车人数与承载人数比:" << a << "%" << endl;
		cout << "发车准时率:" << b << "%" << endl;
		cout << "按时到达率:" << c << "%" << endl;
}

int Bus::if_full(string num)
{
	if (person_num == person_max)return 1;
	else return 0;
}

void Bus::save()
{

	fout2<<bus_num<<" "<<bus_type<<" "<<rider_name<<" "<<person_max<<" "<<time_num<<" ";

	for(int i=0;i<time_num;i++){
		riding[i].save();
	}
	fout2<<endl;
}
	


