#include<bits/stdc++.h>
using namespace std;

int _____[110],______[110];

int main()
{
	int _______;
	scanf("%d",&_______);
	for(int ________=1;________<=_______;________++)
		scanf("%d",_____+________),______[_____[________]]++;
	sort(_____+1,_____+_______+1,greater<int>());
	int _________=(_____[1]+1)/2,__________=(_____[1]&1)+1;
	if(_____[_______]<_________||______[_________]!=__________) return puts("Impossible"),0;
	for(int ________=_____[1];________>_________;________--) if(______[________]<2) return puts("Impossible"),0;
	puts("Possible");
	return 0;
}