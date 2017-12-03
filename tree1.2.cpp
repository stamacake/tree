// прога для постоения дерева
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=8;
/*
999	1	999	1	999	1	1	999
1	999	1	1	1	999	999	999
999	1	999	999	1	1	1	999
1	1	999	999	999	1	999	1
999	1	1	999	999	999	1	1
1	999	1	1	999	999	999	1
1	999	1	999	1	999	999	1
999	999	999	1	1	1	1	999
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
	cout<<"tree: \n";
	for(auto a:way){
		cout<<a<<endl;
	}

    return 0;
}
