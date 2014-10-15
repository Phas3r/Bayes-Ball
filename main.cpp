#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

struct Marks 
	{
	bool visited;
	bool topmark;
	bool bottommark;
	bool inL;
	bool inK;
	Marks(bool a = 0, bool b = 0, bool c = 0, bool d = 0, bool e = 0)
		: visited(a), topmark(b), bottommark(c), inL(d), inK(e) {}
	};

void getmatrix(fstream& Matrix,vector<vector<int> >& graph)
	{


	if (Matrix)
		{
		string line;
		while (getline(Matrix, line)) 
			{
			istringstream iss(line);   
			graph.push_back(vector<int>(istream_iterator<int>(iss), istream_iterator<int>()));
			}
		for (int i=0;i<graph[0].size();++i)
			{
			for (int j = 0; j < graph[0].size(); ++j)
				{
				cout<<graph[i][j]<<' ';
				}
			printf("\n");
			}
		}
	else
		{
		cout<<" Wrong filename"<<endl;
		exit(1);

		}
	}

void Ball(vector<vector<int> >& graph, set<int>& a, const set<int> L, const set<int> K)
	{
	queue<int> schedule;
	queue<int> from;  // 1 -from child, 2 - from parent
	vector<Marks> marks(graph[0].size());
	for (int i = 0; i < marks.size(); i++) 
		{
		Marks temp(0);
		marks[i] = temp;
		}
	set<int>::iterator iter;
	for (iter=L.begin();iter!=L.end();++iter)
		{
		marks[*(iter)-1].inL = true;
		schedule.push(*(iter));
		from.push(1);
		}  
	for (iter=K.begin();iter!=K.end();++iter)
		{
		marks[*(iter) - 1].inK = true;
		}


	int t,n;
	while (!schedule.empty())
		{
		t = (schedule.front()-1);
		schedule.pop();
		marks[t].visited = true;
		n = from.front();
		from.pop();
		if ((n ==1) && (!marks[t].inK))  // (c)
			{ 
			if (!marks[t].topmark) // i
				{  
				marks[t].topmark = true;
				for (int i = 0; i < graph[0].size(); i++) 
					{
					if (graph[i][t] > 0) 
						{
						schedule.push(i+1);
						from.push(1);
						}
					}
				}
			if (!marks[t].bottommark)
				{  // ii
				marks[t].bottommark = true;
				for (int i = 0; i < graph[0].size(); i++)
					{
					if (graph[t][i] > 0)
						{
						schedule.push(i+1);
						from.push(2);
						}
					}
				}
			}
		if (n == 2) 
			{  // (d)
			if ((marks[t].inK) && (!marks[t].topmark))
				{  // i
				marks[t].topmark = true;
				for (int i = 0; i < graph[0].size(); i++) 
					{
					if (graph[i][t] > 0) 
						{
						schedule.push(i+1);
						from.push(1);
						}
					}
				}
			if ((!marks[t].inK) && (!marks[t].bottommark))
				{  // ii
				marks[t].bottommark = true;
				for (int i = 0; i < graph[0].size(); ++i) 
					{
					if (graph[t][i] > 0)
						{
						schedule.push(i+1);
						from.push(2);
						}
					}
				}
			}
		}
	for (int i = 0; i < marks.size(); ++i)
		{
		if (!marks[i].bottommark) a.insert(i+1);
		}
	}
int main() 
	{
	int l, t;
	int k, n;
	vector<vector<int> > graph;
	set<int> L,J,K;
	char filename[80];
	cout<<"Enter path: \n";
	cin>>filename;
	fstream ifst(filename);
	getmatrix(ifst,graph);
	cout << "Enter number of nodes in L:" << endl;
	cin >> l;
	cout << "Enter set L:" << endl;
	for (int i = 0; i < l; i++) 
		{
		cin >> t;
		L.insert(t);
		}
	cout << "Enter number of nodes in K:" << endl;
	cin >> k;
	cout << "Enter set K:" << endl;
	for (int i = 0; i < k; i++)
		{
		cin >> t;
		K.insert(t);
		}
	Ball(graph,J,L,K);

	cout << 'J' << static_cast<char>(193) << 'L'
		<< static_cast<char>(179) << 'K' << endl;
	cout << "J:" << endl;
	set<int>::iterator ik;
	for(ik=J.begin(); ik!=J.end(); ++ik)
		cout<<*ik<<"  ";
	return 0;
	}
