#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <ctime>
using namespace std;
struct Marks	
{
	bool visited;
	bool topmark;
	bool bottommark;
	bool inL;
	bool inK;
	Marks(bool a=0,bool b=0,bool c=0,bool d=0,bool e=0):visited(a),topmark(b),bottommark(c),inL(d),inK(e){}
};

int main()
{

    int l,t;
	int k,n;
	cout<<"Enter number of nodes in graph";
	cin>>t;
	queue<int> schedule;
	queue<int> from;//1 -from child, 2 - from both, 3 - from parent
	vector<vector<int>> graph(t,vector<int>(t));// строка - откуда, столбец - куда
	srand( (unsigned)time(NULL) ); 
	for (int i=0;i<t;i++)     
        for (int j=0;j<t;j++) 
            { 
			if (i==j) graph[i][j]=0; 
            else
                        {        
						graph[i][j]=(rand()%2 ); 
						graph[j][i]=0;
                        } 
            }  
	for(int i=0;i<t;i++)
		{
		for(int j=0;j<t;j++)
			{
			cout<<graph[i][j]<<' ';
			}
		cout<<endl;
		}

	vector<Marks> marks(t);

	for (int i=0;i<t;i++)
		{
		Marks temp(0);
		marks[i]=temp;
		}

	cout<<"Enter number of nodes in L:"<<endl;
	cin >>l;
	cout<<"Enter set L:"<<endl;
	for(int i=0;i<l;i++)
		{
		    cin>>t;
			marks[t-1].inL=true;
			schedule.push(t);
			from.push(1);
		}
	cout<<"Enter number of nodes in K:"<<endl;
	cin >>k;
	cout<<"Enter set K:"<<endl;
	for(int i=0;i<k;i++)
		{
		    cin>>t;
		    marks[t-1].inK=true;
		}
	while (!schedule.empty())
		{
		t=schedule.front();
		schedule.pop();
		if (marks[t].visited) continue;
		marks[t].visited=true;
		n=from.front();
		from.pop();
		if ((n<3)&&(!marks[t].inK))//(c)
			{
			if (!marks[t].topmark)//i
				{
				marks[t].topmark=true;
				for(int i=0;i<graph[0].size();i++)
					{
					if (graph[i][t]>0) 
						{
						schedule.push(i);
						from.push(1);
						}
					}
				}
			if (!marks[t].bottommark)//ii
				{
				marks[t].bottommark=true;
				for(int i=0;i<graph[0].size();i++)
					{
					if (graph[t][i]>0) 
						{
						schedule.push(i);
						from.push(2);
						}
					}
				}
			}
		if (n>1)//(d)
			{
			if ((marks[t].inK)&&(!marks[t].topmark))//i
				{
				marks[t].topmark=true;
				for(int i=0;i<graph[0].size();i++)
					{
					if (graph[i][t]>0) 
						{
						schedule.push(i);
						from.push(1);
						}
					}
				}
			if ((!marks[t].inK)&&(!marks[t].bottommark))//ii
				{
				marks[t].bottommark=true;
				for(int i=0;i<graph[0].size();i++)
					{
					if (graph[t][i]>0) 
						{
						schedule.push(i);
						from.push(2);
						}
					}
				}
			}


		}
	


	
	cout<<'L'<<char(193)<<'J'<<char(179)<<'K'<<endl;
	cout<<"J:"<<endl;
	for (int i=0;i<marks.size();i++)
		{
		if (!marks[i].bottommark) cout<<i<<endl;
		}
	system("Pause");
	return 0;

}
