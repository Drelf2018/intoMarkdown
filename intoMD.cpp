#include <bits/stdc++.h>
using namespace std;

string name;
string value[15][5];
int slen[15];
map<string,int> mp; 

void init()
{
	value[1][0]="---";
	value[2][0]="layout: post";
	value[3][0]="title: ";
	value[4][0]="date:   ";
	value[5][0]="categories: ";
	value[6][0]="tag: ";
	value[7][0]="---";
	value[8][0]="";
	value[9][0]="* content";
	value[10][0]="{:toc}";
	value[11][0]="";
	value[12][0]="";
	mp["title"]=3;
	mp["date"]=4;
	mp["categories"]=5;
	mp["tag"]=6;
}

void getInf()
{
	int pos,s,t,len,num;
	string reader;
	ifstream fin("blog.inf");
	while(getline(fin,reader))
	{
		cout<<reader<<endl;
		len=reader.length()-1,pos=s=t=num=0;
		while(pos<=len&&reader[pos++]!='[');s=pos;
		while(pos<=len&&reader[pos++]!=']');t=pos-2;
		num=mp[reader.substr(s,t)];
		value[num][1]=reader.substr(pos,len);
		slen[num]++;
	}
	return ;
}

void write()
{
	string reader;
	ifstream fre("blog.txt");
	ofstream fout("blog.md");
	
	for(int i=1;i<=12;i++)
	{
		for(int j=0;j<=slen[i];j++)
			fout<<value[i][j];
		fout<<endl;
	}
	
	while(getline(fre,reader))
	{
		if(reader!="[insert]")
		{
			if(reader!="")fout<<reader<<endl<<endl;
			else fout<<endl;
		}
		else{
			getline(fre,reader); 
			ifstream fcode(reader.c_str());
			while(getline(fcode,reader))
				if(reader!="")fout<<reader<<endl<<endl;
				else fout<<endl;
		} 
	}
}

int main()
{
	init();
	getInf();
	write();
	return 0;
} 
