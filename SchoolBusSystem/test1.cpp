
#include<fstream>

std::ofstream fout1;

#include"card.h"
/*
Card::Card(string nname,int num,int cardnum,string com)
{ 
	name=nname;
	card_num=cardnum;
	company=com;
	if(num==1)id="Teacher Card";
	else if(num==2)id="Student Card";
	else if(num==3)id="Limit Card";
	else cout<<"Wrong Input!\n";
	money=0;
	times=0;
}
*/
Card& Card::init(string nname,int num,int cardnum,string com,int mon,int t)
{
	name=nname;
	card_num=cardnum;
	company=com;
	if(num==1)id="Teacher Card";
	else if(num==2)id="Student Card";
	else if(num==3)id="Limit Card";
	else cout<<"Wrong Input!\n";
	money=mon;
	times=t;
	return *this;
}

void Card::del(int num){
	if(card_num==num){
		name="0";
		card_num=0;
	}
	else return;
}

/*
Teacher::Teacher(string nname,int cardnum,string com)
{
	Card(nname,1,cardnum,com);
}

Student::Student(string nname,int cardnum,string com)
{
	Card(nname,2,cardnum,com);
}

Limit::Limit(string nname,int cardnum,string com)
{
	Card(nname,3,cardnum,com);
}
*/

void Card::ask_money(int num)
{
	if (num == card_num){
		cout << "��" << money << endl;
		if (money <= 5)cout << "�����ͣ���ʱ��ֵ\n";
	}
	else return;
}

void Card::ask_times(int num)
{
	if (num == card_num){
		cout << "�Ѿ�ʹ�ô�����" << times << endl;
	}
	else return;
}

void Card::ask_inform(int num)
{
	//�ֿ���������һ��ͨ��š�������λ����������Ч�ڵ�
	if (num == card_num){
		cout << "�ֿ�������:" << name << endl;
		cout << "һ��ͨ���:" << card_num << endl;
		cout << "������λ:" << company << endl;
	}
}

bool Card::money_out()
{
	if(money<2){
	    ask_inform(card_num);
		cout<<"���㣬��׼�˳�\n"<<endl;
		return false;
	}
	return true;
}

void Card::save()
{
	if(name!="0")
	fout1<<name<<" "<<card_num<<" "<<company<<" "<<money<<" "<<times<<endl;
}

Card& Teacher::add_money(int num,int n)
{
	cout<<"��ʦ�����ܳ�ֵ��\n";
	return *this;
}

Card& Limit::add_money(int num,int n)
{
	if (num == card_num){
		if (n > 0)money += n;
		cout << "OK\n";
		return *this;
	}
	else return *this;
}

Card& Student::add_money(int num,int n)
{
	if (num == card_num){
		if (n > 0)money += n;
		cout << "OK\n";
		return *this;
	}
	else return *this;
}


Card& Teacher::use(int num)
{
	if (num == card_num){
		times++;
		ask_inform(card_num);
		cout << "��ѳ˳�\n" << endl;
		return *this;
	}
	else return *this;
}

Card& Student::use(int num)
{
	if (num == card_num){
		if (money_out() == 0)
			return *this;
		times++;
		money -= 2;
		ask_inform(card_num);
		ask_money(card_num);
		cout << endl;
		return *this;
	}
	else return *this;
}

Card& Limit::use(int num)
{
	if (num == card_num){
		if (money_out() == 0)
			return *this;
		if (times < 19){
			times++;
			ask_inform(card_num);
			ask_times(card_num);
			cout << endl;
			return *this;
		}
		if (times == 19){
			times++;
			ask_inform(card_num);
			ask_times(card_num);
			cout << "�������һ����ѳ˳�\n" << endl;
			return *this;
		}
		if (times == 20){
			times++;
			ask_inform(card_num);
			cout << "���ο�ʼ�շ�\n";
			money -= 2;
			ask_money(card_num);
			cout << endl;
			return *this;
		}
		if (times > 20){
			times++;
			money -= 2;
			ask_inform(card_num);
			ask_money(card_num);
			cout << endl;
			return *this;
		}
	}
	else return *this;
}