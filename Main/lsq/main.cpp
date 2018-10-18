#include<bits/stdc++.h>
using namespace std;
#include"headers.h"
string buf;
bool ck(string tmp){
	if(!mp.count(tmp)){
		now+='_';
		mp[tmp]=now;
		return 0;
	}
	return 1;
}
#define two(a,b) \
	if(buf[p]==a&&p<(int)buf.length()-1&&buf[p+1]==b){\
			string tmp;\
			tmp+=a;\
			tmp+=b;\
			ss<<mp[tmp]<<' ';\
			p+=2;\
	}

#define thr(a,b,c) \
	if(buf[p]==a&&p<(int)buf.length()-2&&buf[p+1]==b&&buf[p+2]==c){\
		string tmp;\
		tmp+=a,tmp+=b,tmp+=c;\
		ss<<mp[tmp]<<' ';\
		p+=3;\
	}

int main(int argv,char* argc[]){
	freopen(argc[2],"w",stdout);
	freopen(argc[1],"r",stdin);
	init();
	for(int i=0;i<SZ;i++){
		cout<<"#define "<<mp[KeyWord[i]]<<' '<<KeyWord[i]<<endl;
	}
	stringstream ss;
	while(getline(cin,buf)){
		int p=0,flag=1;
		for(;p<(int)buf.length();){
			if(flag&&buf[0]=='#'){
				flag=0;
				if(buf[1]=='i'){
					ss<<buf<<endl;
					break;
				}
				else ss<<"#define ",p=8;
			}
			if(isalpha(buf[p])||buf[p]=='_'){
				string tmp;
				while(isalpha(buf[p])||buf[p]=='_'||isdigit(buf[p])) tmp+=buf[p],p++;
				ck(tmp);			
				ss<<mp[tmp]<<' ';
			}
			else thr('>','>','=')
			else thr('<','<','=')
			else two('<','<')
			else two('>','>')
			else two('!','=')
			else two('=','=')
			else two('|','|')
			else two('&','&')
			else two('<','=')
			else two('>','=')
			else two('+','+')
			else two('-','-')
			else two('+','=')
			else two('-','=')
			else two('%','=')
			else two('/','=')
			else two('*','=')	
			else if(buf[p]=='\"'){
				string tmp;
				tmp+='\"';
				p++;
				while(buf[p]!='\"') tmp+=buf[p],p++;
				p++;
				tmp+='\"';
				if(!ck(tmp))cout<<"#define "<<mp[tmp]<<' '<<tmp<<endl;
				ss<<mp[tmp]<<' ';
			}
			else if(buf[p]=='\''){
				string tmp;
				tmp+='\'';
				p++;
				while(buf[p]!='\'') tmp+=buf[p],p++;
				p++;
				tmp+='\'';
				if(!ck(tmp))cout<<"#define "<<mp[tmp]<<' '<<tmp<<endl;
				ss<<mp[tmp]<<' ';
			}
			else if(isdigit(buf[p])){
				string tmp;
				while(isdigit(buf[p])||buf[p]=='.'||isalpha(buf[p])) tmp+=buf[p],p++;
				if(!ck(tmp)) cout<<"#define "<<mp[tmp]<<' '<<tmp<<endl;
				ss<<mp[tmp]<<' ';
			}
			else{
				string tmp;
				tmp+=buf[p];
				if(mp.count(tmp)) ss<<mp[tmp]<<' ';
				else ss<<tmp<<' ';
				p++;
			}
		}
		ss<<endl;
	}
	string result=ss.str();
	cout<<result<<endl;
	return 0;
}
