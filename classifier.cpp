#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define S 1000005
#define W while
#define M 1000000007
#define str string
#define pi 3.14159265
LL mini=INT_MAX;
LL maxi=INT_MIN;
using namespace std;
map<string, int> m;
map<str,double> spam,ham;
vector<str> message;
int main()
{
	ifstream infile,spamfile,hamfile;
	infile.open("newfile.txt");
	spamfile.open("train_prob_spam");
	hamfile.open("train_prob_ham");
	str s;
	double d;
	while(spamfile>>s)
	{
		spamfile>>d;
		spam[s]=d;
	}
	while(hamfile>>s)
	{
		hamfile>>d;
		ham[s]=d;
	}
	string s1;
	W(cin>>s1)
	{

		message.push_back(s1);
	}
	double hp=0,sp=0;
	map<str,double> ::iterator it;

	for(int i=0;i<message.size()-1;i++)
	{
		string word1, word2, word3;
		word1 = message[i], word2 = message[i + 1];
		word3 = word1 + word2;

		it = spam.find(word1);
		if ( it != spam.end() )
		{
			sp += -1*log10(it -> second);
		}

		it = spam.find(word3);
		if ( it != spam.end() )
		{
			sp += -1*log10(it -> second);
		}

		it = ham.find(word1);
		if ( it != ham.end() )
		{
			hp += -1*log10(it -> second);
		}

		it = ham.find(word3);
		if ( it != ham.end() )
		{
			hp += -1*log10(it -> second);
		}
	}
   if(spam.find(message[message.size()-1])!=spam.end())
		sp+=-1*log10(spam[message[message.size()-1]]);
	if(ham.find(message[message.size()-1])!=ham.end())
		hp+=-1*log10(ham[message[message.size()-1]]);
    sp+=-1*log10((double)spam.size()/(spam.size()+ham.size()));
    hp+=-1*log10((double)ham.size()/(ham.size()+spam.size()));
    sp+=.86;
    hp+=.14;
	if(sp>hp)
		cout<<"\n\n\n\n..........message is spam.........\n\n"<<sp<<endl;
	else cout<<"\n\n\n\n...........message is ham.........\n\n"<<hp<<endl;

	spamfile.close();
	hamfile.close();
	infile.close();
}
































































































































/*	if(spam.find(message[message.size()-1])!=spam.end())
		sp+=-1*log10(spam[message[message.size()-1]]);
	if(ham.find(message[message.size()-1])!=ham.end())
		hp+=-1*log10(ham[message[message.size()-1]]); */
//	sp+=-1*log10((double)spam.size()/(spam.size()+ham.size()));
//	hp+=-1*log10((double)ham.size()/(ham.size()+spam.size()));
//	cout<<sp<<endl<<hp;

