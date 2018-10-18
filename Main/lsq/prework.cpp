#include<bits/stdc++.h>
using namespace std;
const int SZ=80;
const string s[SZ]={
"<<=","stdin","isdigit",">>=","puts","unique","first","second","?","static","EOF","fwrite","upper_bound","+=","-=","%=","*=","/=","/","++","--","<=",">=","||","&&","getchar","cout","!","%","^","&","*","(",")","+","[","]","{","}","<",">",";",":",",","for","const","return","main","int","long","if","pair","typedef","using","namespace","std","bool","double","while","fread","char","inline","break","continue","else","queue","stack","priority_queue","=","printf","scanf","cin","min","max","struct","<<",">>","!=","==","goto"};//41
int main(){
	freopen("headers.h","w",stdout);
	printf("const int SZ=%d;\n",SZ);
	puts("using namespace std;");
	puts("const string KeyWord[SZ]={");
	for(int i=0;i<SZ;i++){
		cout<<'\"'<<s[i]<<'\"';
		if(i!=SZ-1) putchar(',');
		else cout<<"};";
	}
	puts("\nmap<string,string>mp;");
	puts("void init(){");
	string now;
	for(int i=0;i<SZ;i++){
		cout<<"mp[\""<<s[i]<<"\"]=\"";
		for(int j=0;j<=i;j++) putchar('_');
		cout<<"\";"<<endl;
		now+='_';
	}
	puts("}");
	cout<<"string now=\""<<now<<"\";"<<endl;	
	return 0;
}
