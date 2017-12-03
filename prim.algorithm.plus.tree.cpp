// by stamacake Prim alrofithm and it's tree, random ostovnoe tree


// прога для постоения дерева
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=8;
/*
999	8	999	5	999	4	2	999
3	999	4	5	11	999	999	999
999	22	999	999	4	12	10	999
9	15	999	999	999	13	999	6
999	8	21	999	999	999	7	24
13	999	13	10	999	999	999	8
1	999	17	999	1	999	999	6
999	999	999	22	5	9	15	999
  */
int main()
{
	// part 1.1
	int a[N][N]={0};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int buff=0;
			cin>>buff;
			a[i][j]=buff;
		}
	}
	vector<string> way; //сам путь
	vector<int> used; // использованные вершины
	used.push_back(0);
	int min=0;
	int i=0;
	int jj=0;
	int minway=0;
	while(used.size()!=N){
		min=998;
		for(int j=0;j<N;j++){
			int check=0;
			if((a[i][j]<min)){
				for(auto ff:used){
					if(j==ff){
						check++;
					}
				}
				if(check==0){
				min=a[i][j];
				jj=j;
				}
			}
		}
		if(min != 998){
		used.push_back(jj);
		minway +=min;
		string ii=to_string(i+1);
		string jjj=to_string(jj+1);
		way.push_back(ii+"-"+jjj);
		i=jj;
		} else {
			i -=1;
		}
	}
	cout<<"random tree: \n";
	for(auto a:way){
		cout<<a<<endl;
	}

	// part 2 prim algorithm
	vector<int> allused;
	int currentmin=0;
	allused.push_back(0);
	vector<string> minway2;
	int minways=0;
	int buff3=0;
	int buff31=0;
	while(allused.size()!=N){
		currentmin=998;
		for(auto cur:allused){
			for(int i=0;i<N;i++){
				if(a[cur][i]<currentmin&&find(allused.begin(),allused.end(),i)==allused.end()){
					currentmin=a[cur][i];
					buff31=cur;
					buff3=i;

				}
			}
		}
		minways +=currentmin;
		allused.push_back(buff3);
		minway2.push_back(to_string(buff31+1)+" - "+to_string(buff3+1));

	}

	cout<<"min way: "<<minways<<endl;;
	for(auto gg:minway2){
		cout<<gg<<endl;
	}





    return 0;
}
