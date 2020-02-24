#include"test1.cpp"
#include"test2.cpp"
#include<fstream>
#define MAX 999
using namespace std;
ifstream fin1("save1.txt");
ifstream fin3("save3.txt");

int main()
{
	Teacher T[MAX];
	Student S[MAX];
	Limit   L[MAX];
	Bus     B[20];
	string name, com, b_num, b_type, b_rider;
	int id, a = 0, b = 0, c = 0, d = 0, e=0, x, y, num, money,time,b_person;
	while (fin1 >> name >> id >> com>>money>>time)
	{
		if (id > 10000&&id<20000){
			T[a].init(name, 1 ,id, com,money,time);
			a++;
		}
		else if (id > 20000 && id<30000){
			S[b].init(name,2,id, com,money,time);
			b++;
		}
		else if (id > 30000 && id<40000){
			L[c].init(name,3, id, com,money,time);
			c++;
		}
		else cout << "Wrong!\n";
	}
	while (fin2 >> b_num >> b_type >> b_rider >> b_person){
				B[d].f_init(b_num, b_type, b_rider, b_person);
				d++;
			}

	cout << "信息管理中心\n\n";
	cout << "选1管理卡业务，选2管理班车业务，选0退出\n";
	while (cin >> x&&x != 0){
		if (x == 1)
		{
			cout << "选1办理新卡，选2充值业务，选3查询余额，选4查询已使用次数，选5注销卡，选6更改持卡人信息，选0退出\n";
			while (cin >> y &&y != 0) {
				if (y == 1)
				{
					cout << "办理新卡：\n依次输入姓名、卡种类（教师卡为1，学生卡为2，限制卡为3）、所属公司\n";
					cout << "输入“0 0 0”退出业务办理\n";
					while (cin >> name >> id >> com&&name != "0")
					{
						if (id == 1){
							T[a].init(name, id, 10001 + a, com);
							a++;
						}
						else if (id == 2){
							S[b].init(name, id, 20001 + b, com);
							b++;
						}
						else if (id == 3){
							L[c].init(name, id, 30001 + c, com);
							c++;
						}
						else cout << "Wrong!\n";
					}
				}
				if (y == 2)
				{
					cout << "输入卡号及充值金额：";
					cin >> id >> money;
					if (id >= 10000 && id < 20000)
						cout << "教师卡不能充值！\n";
					if (id >= 20000 && id < 30000){
						for (int i = 0; i < b; i++)
							S[i].add_money(id, money);
					}
					if (id >= 30000 && id < 40000){
						for (int i = 0; i < c; i++)
							L[i].add_money(id, money);
					}
				}
				if (y == 3)
				{
					cout << "输入卡号:";
					cin >> id;
					if (id >= 10000 && id < 20000){
						cout << "教师卡不能充值！\n";
					}
					if (id >= 20000 && id < 30000){
						for (int i = 0; i < b; i++)
							S[i].ask_money(id);
					}
					if (id >= 30000 && id < 40000){
						for (int i = 0; i < c; i++)
							L[i].ask_money(id);
					}
				}
				if (y == 4)
				{
					cout << "输入卡号:";
					cin >> id;
					if (id >= 10000 && id < 20000){
						for (int i = 0; i < a; i++)
							T[i].ask_times(id);
					}
					if (id >= 20000 && id < 30000){
						for (int i = 0; i < b; i++)
							S[i].ask_times(id);
					}
					if (id >= 30000 && id < 40000){
						for (int i = 0; i < c; i++)
							L[i].ask_times(id);
					}
				}
				if(y == 5)
				{
					cout<<"输入卡号：";
					cin>>id;
					if (id >= 10000 && id < 20000){
						for (int i = 0; i < a; i++)
							T[i].del(id);
							
					}
					if (id >= 20000 && id < 30000){
						for (int i = 0; i < b; i++)
							S[i].del(id);
					}
					if (id >= 30000 && id < 40000){
						for (int i = 0; i < c; i++)
							L[i].del(id);
					}
				}
				cout << "选1办理新卡，选2充值业务，选3查询余额，选4查询已使用次数，选5注销卡，选6更改持卡人信息，选0退出\n";
			}
		}
		if (x == 2)
		{
			cout << "新建班车信息\n依次输入车牌号、型号、驾驶员姓名、载乘人数\n";
			cout << "输入“0 0 0 0”退出新建班车\n";
			while (cin >> b_num >> b_type >> b_rider >> b_person&&b_num != "0"){
				B[d].init(b_num, b_type, b_rider, b_person);
				d++;
			}
		}
		cout << "选1管理卡业务，选2管理班车业务，选0退出业务办理\n";
	}
	cout << "\n\n上车\n\n";
	cout << "输入车牌号、一卡通卡号\n输入“0 0”结束\n";
	int m;
	while (cin >> b_num >> id&&b_num != "0"){
		for (int j = 0; j < d; j++){
			m = B[j].if_full(b_num);
			B[j].count(b_num);
			break;
		}
		if (m != 1){
			if (id >= 10000 && id < 20000){
				for (int i = 0; i < a; i++)
					T[i].use(id);
			}
			if (id >= 20000 && id < 30000){
				for (int i = 0; i < b; i++)
					S[i].use(id);
			}
			if (id >= 30000 && id < 40000){
				for (int i = 0; i < c; i++)
					L[i].use(id);
			}
		}
		cout << "输入车牌号、一卡通卡号\n输入“0 0”结束\n";
	}
	cout << "\n\n输入班车离开乘车点的时间和到达目的地的时间\n\n";
	cout << "输入车牌号\n输入“0”结束\n";
	while (cin >> b_num&&b_num != "0"){
		for (int i = 0; i < d; i++){
			B[i].c_time(b_num);
		}
		cout << "输入车牌号\n输入“0”结束\n";
	}
	cout << "\n\n汇总班车运行信息\n\n";
	for (int i = 0; i < d; i++)
		B[i].inform();

	fout1.open("save1.txt");
	fout2.open("save2.txt");
	for(int j=0;j<a;j++)
		T[j].save();
	for(int k=0;k<b;k++)
		S[k].save();
	for(int l=0;l<c;l++)
		L[l].save();
	for(int p=0;p<d;p++)
		B[p].save();
	return 0;
}

