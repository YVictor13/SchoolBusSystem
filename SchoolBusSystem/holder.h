class Holder
{
	string name;
	string sex;
	string job;
	string company;
	string number;
	int card_n;
	int card[10];
	int times;
public:
	Holder& init(string nname,string ssex,string work,string com,string num);
	Holder& count_times(Card card);


