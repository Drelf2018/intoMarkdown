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
	mp["title"]=3;
	mp["date"]=4;
	mp["categories"]=5;
	mp["tag"]=6;
}

void getInf()
{
	int k=3;
	string reader;
	ifstream fin("blog.inf");
	while(getline(fin,reader))
	{
		cout<<reader<<endl;
		int len=reader.length()-1,i=0;
		while(reader[i]!='=')i++;
		for(int j=++i;j<=len;j++)
		{
			cout<<"#";
			value[k][1][j-i]=reader[j];
		}
		slen[k]++;
		k++;
		cout<<"@"<<endl;
	}
	return ;
}

/*void write()
{
	ifstream fre("blog.txt");
	ofstream fout(name.c_str());
	int j;
	for(j=1;j<=2;j++)fout<<value[j][0]<<endl;
	
	fout<<value[j][0];
		int len=reader.length()-1,i=0;
		while(reader[i]!='=')i++;
		for(i=i+1;i<=len;i++)
		{
			fout<<reader[i];
		}
		fout<<endl;
		j++;
	for(j=7;j<=10;j++)fout<<value[j][0]<<endl;
	fout<<endl<<endl;
	
	while(getline(fre,reader))
	{
		if(reader!="<insert>")fout<<reader<<endl;
		else{
			getline(fre,reader); 
			ifstream fcode(reader.c_str());
			while(getline(fcode,reader))fout<<reader<<endl;
		} 
	}
}*/

int main()
{
	init();
	getInf();
	for(int i=1;i<=10;i++)
	{
		for(int j=0;j<=20;j++)
			cout<<value[i][1][j];
		cout<<endl;
	}
	return 0;
} 
