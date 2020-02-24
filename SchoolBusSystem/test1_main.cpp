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

	cout << "��Ϣ��������\n\n";
	cout << "ѡ1����ҵ��ѡ2����೵ҵ��ѡ0�˳�\n";
	while (cin >> x&&x != 0){
		if (x == 1)
		{
			cout << "ѡ1�����¿���ѡ2��ֵҵ��ѡ3��ѯ��ѡ4��ѯ��ʹ�ô�����ѡ5ע������ѡ6���ĳֿ�����Ϣ��ѡ0�˳�\n";
			while (cin >> y &&y != 0) {
				if (y == 1)
				{
					cout << "�����¿���\n�������������������ࣨ��ʦ��Ϊ1��ѧ����Ϊ2�����ƿ�Ϊ3����������˾\n";
					cout << "���롰0 0 0���˳�ҵ�����\n";
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
					cout << "���뿨�ż���ֵ��";
					cin >> id >> money;
					if (id >= 10000 && id < 20000)
						cout << "��ʦ�����ܳ�ֵ��\n";
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
					cout << "���뿨��:";
					cin >> id;
					if (id >= 10000 && id < 20000){
						cout << "��ʦ�����ܳ�ֵ��\n";
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
					cout << "���뿨��:";
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
					cout<<"���뿨�ţ�";
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
				cout << "ѡ1�����¿���ѡ2��ֵҵ��ѡ3��ѯ��ѡ4��ѯ��ʹ�ô�����ѡ5ע������ѡ6���ĳֿ�����Ϣ��ѡ0�˳�\n";
			}
		}
		if (x == 2)
		{
			cout << "�½��೵��Ϣ\n�������복�ƺš��ͺš���ʻԱ�������س�����\n";
			cout << "���롰0 0 0 0���˳��½��೵\n";
			while (cin >> b_num >> b_type >> b_rider >> b_person&&b_num != "0"){
				B[d].init(b_num, b_type, b_rider, b_person);
				d++;
			}
		}
		cout << "ѡ1����ҵ��ѡ2����೵ҵ��ѡ0�˳�ҵ�����\n";
	}
	cout << "\n\n�ϳ�\n\n";
	cout << "���복�ƺš�һ��ͨ����\n���롰0 0������\n";
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
		cout << "���복�ƺš�һ��ͨ����\n���롰0 0������\n";
	}
	cout << "\n\n����೵�뿪�˳����ʱ��͵���Ŀ�ĵص�ʱ��\n\n";
	cout << "���복�ƺ�\n���롰0������\n";
	while (cin >> b_num&&b_num != "0"){
		for (int i = 0; i < d; i++){
			B[i].c_time(b_num);
		}
		cout << "���복�ƺ�\n���롰0������\n";
	}
	cout << "\n\n���ܰ೵������Ϣ\n\n";
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

