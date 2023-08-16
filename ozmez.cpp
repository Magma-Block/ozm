#include<bits/stdc++.h>
using namespace std;
string song[100];
bool m[100][10000];
bool m2[1000],m3[1000];//m2开过的歌  m3歌有字母被开了  
int sonum=20;
char oped[100000];//开过的字母 
int opn;

void printsong()
{
	for(int i=1;i<=sonum;i++)
	{
		cout<<i<<".";
		if(m2[i])
		{
			cout<<song[i];
		}
		else
		{
			for(int j=0;j<song[i].size();j++)
			{
				if(song[i][j]==' ')
				{
					cout<<" ";
					continue;
				}
					
					
				if(m[i][j])
					cout<<song[i][j];
				else
					cout<<"*";
			}
		}
		cout<<endl;
	}
}

void ozm(char n)
{
	for(int i=1;i<=opn;i++)
	{
		if(n==oped[i])
		{
			cout<<"opened\n";
			system("pause");
			return;
		}
	}
	bool flag=false;
	for(int i=1;i<=sonum;i++)
	{
		if(m2[i]==true)
			continue;
		for(int j=0;j<song[i].size();j++)
		{
			if(song[i][j]==n)
			{
				m3[i]=true;
				m[i][j]=true;
				flag=true;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\n\nNO\n";
		system("pause");
		return;
	}
	else oped[++opn]=n;
}

void osong(int n)
{
	int score=0;
	if(m3[n])
		score=5;
	else
		score=10;
	m2[n]=1;
	for(int j=0;j<song[n].size();j++)
	{
		if(song[n][j]==' '||m[n][j]==true)
		{
			continue;
		}
		else
			score++;
	}
	cout<<"得分:+"<<score<<endl;
	system("pause");
}

void printopened()
{
	cout<<"已开的字母:";
	for(int i=1;i<=opn;i++)
		cout<<oped[i]<<' ';
	cout<<endl<<endl;
}

/*void printNoApWord()
{
	system("cls");
	int wo[27];
	memset(wo,0,sizeof(wo));
	for(int i=1;i<=sonum;i++)
	{
		for(int j=0;j<song[i].size();j++)
		{
			if(song[i][j]==n)
			{
				m3[i]=true;
				m[i][j]=true;
				flag=true;
			}
		}
	}
}*/

int main()
{
	memset(m,0,sizeof(m));
	memset(m2,0,sizeof(m2));
	memset(m3,0,sizeof(m3));
	for(int i=1;i<=sonum;i++)
	{
		getline(cin,song[i]);
	}
	system("cls");
	for(int i=1;i<=sonum;i++)
		cout<<i<<"."<<song[i]<<endl;
	
	system("pause");
	int ii=1;
	while(true)
	{
		system("cls");
		printopened();
		printsong();
		cout<<endl<<endl<<"1:开子母 2:开歌;\n";
		int h;
		cin>>h;
		if(h==1)
		{
			char h2;
			cout<<"要开的子母:" ;
			cin>>h2;
			ozm(h2);
		}
		if(h==2)
		{
			int h2;
			cout<<"歌曲编号:";
			cin>>h2;
			osong(h2);
		}
	}
 } 
