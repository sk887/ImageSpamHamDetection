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
int primes[10000001];
using namespace std;
map<string, int> m;
map<string, double> m_prob;
int main()
{
	LL total_words=0,total_ham=0,total_spam=0;
	ifstream  afile;
	ofstream outfile;
   	outfile.open("train_prob_spam");
	afile.open("spam_stemmed.txt", ios::out | ios::in );
	str s1,s2;
	afile>>s1;
	while(afile>>s2)
	{
		m[s1]++;
		m[s1+s2]++;
		s1=s2;
	}
	map<string ,int> ::iterator it=m.begin();
	for(;it!=m.end();it++)
	{
		total_words+=it->second;
	}
	total_spam=total_words;
	for(it=m.begin();it!=m.end();it++)
	{
		m_prob[it->first]=(double)it->second/total_words;
	}

	map<string, double> :: iterator it1;

	for(it1=m_prob.begin();it1!=m_prob.end();it1++)
	{
		outfile<<it1->first<<" "<<it1->second<<endl;
	}
	outfile.close();
	afile.close();
	m.clear();
	m_prob.clear();

	outfile.open("train_prob_ham");
	afile.open("ham_stemmed.txt", ios::out | ios::in );
	afile>>s1;
	while(afile>>s2)
	{
		m[s1]++;
		m[s1+s2]++;
		s1=s2;
	}
	it=m.begin();
	total_words=0;
	for(;it!=m.end();it++)
	{
		total_words+=it->second;
	}
	total_ham=total_words;
	for(it=m.begin();it!=m.end();it++)
	{
		m_prob[it->first]=(double)it->second/total_words;
	}


	for(it1=m_prob.begin();it1!=m_prob.end();it1++)
	{
		outfile<<it1->first<<" "<<it1->second<<endl;
	}
	afile.close();
	outfile.close();
	return 0;
}
