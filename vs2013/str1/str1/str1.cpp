#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<memory>
using std::string;
const int NUM = 26;
const string wordlist[NUM] = { "apiary", "beetle", "cereal", "danger", "ensign", "florid", 
								"garage", "health", "insult", "jackal", "keeper", "loaner", 
								"manage", "nonce", "onset", "plaid", "quilt", "remote", 
								"stolid", "train", "useful", "valid", "whence", "xenon", 
								"yearn", "zippy"};


class Report
{
public:
	Report(const string s):str(s)
	{
		std::cout << "Object created!\n";
	}
	~Report()
	{
		std::cout << "object deleted!\n";
	}
	void comment() const{ std::cout << str << "\n"; }

private:
	string str;
};

void main()
{
	/*
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	std::srand(std::time(0));
	char play;

	cout << "will you play a word game?Y/N";
	cin >> play;
	play = tolower(play);
	*/

	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}

	system("pause");
}