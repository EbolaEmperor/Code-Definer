#include<bits/stdc++.h>
using namespace std;

char var_type[100][100];
int var_count=8;

void var_type_init()
{
    sprintf(var_type[0],"int");
    sprintf(var_type[1],"bool");
    sprintf(var_type[2],"short");
    sprintf(var_type[3],"long");
    sprintf(var_type[4],"long long");
    sprintf(var_type[5],"char");
    sprintf(var_type[6],"void");
    sprintf(var_type[7],"double");
}

bool is_type(char *s,int len)
{
    s[len]='\0';
    for(int i=0;i<var_count;i++)
        if(strcmp(s,var_type[i])==0) return 1;
    return 0;
}

char source[1000000],*H,*T;
vector<char*> vars;
vector<int> lenth;
int len_source;

bool var_in_law(char c)
{
    if(c>='a'&&c<='z') return 1;
    if(c>='A'&&c<='Z') return 1;
    if(c=='_') return 1;
    return 0;
}

void add_type_before(int p)
{
    static char word_before[510];
    int word_before_lenth = 0;
    while(var_in_law(source[p-1]))
        word_before[word_before_lenth++] = source[--p];
    reverse(word_before, word_before + word_before_lenth);
    word_before[word_before_lenth]='\0';
    sprintf(var_type[var_count++],word_before);
}

bool is_main(char *s,int len)
{
    s[len]='\0';
    static char s_main[5]="main";
    if(strcmp(s,s_main)==0) return 1;
    return 0;
}

bool is_typedef(char *s,int len)
{
    s[len]='\0';
    static char s_typedef[8]="typedef";
    if(strcmp(s,s_typedef)==0) return 1;
    return 0;
}

bool is_var(char *s,int len)
{
    s[len]='\0';
    for(char* var : vars)
        if(strcmp(s,var)==0) return 1;
    return 0;
}

int get_var(char *s,int len)
{
    s[len]='\0';
    for(int i=0;i<vars.size();i++)
        if(strcmp(s,vars[i])==0) return i;
}

void delete_source(int p)
{
    for(int i=p;i<len_source;i++) source[i]=source[i+1];
    source[--len_source]='\0';
}

void insert_source(int p)
{
    for(int i=len_source;i>p;i--) source[i]=source[i-1];
    source[++len_source]='\0';
    source[p]='_';
}

void modify(int &p,char *s,int len)
{
    int idx=get_var(s,len);
    p-=len;
    for(int i=0;i<len;i++) delete_source(p);
    for(int i=0;i<lenth[idx];i++) insert_source(p);
    p+=lenth[idx];
}

void next_line(int &p){while(source[p]!=';') p++;}

void Main()
{
    static char word[50];int i=0;
    bool read_var_modal=0,read_var_modal_pre=0,match=0;
    bool assignment_modal=0;
    int read_var_stop_deep=0;
    while(i<len_source)
    {
        int top=0;
        while(!var_in_law(source[i]))
        {
            if(read_var_modal_pre&&(source[i]==';'||source[i]=='{'))
            {
                read_var_modal=0;
                read_var_modal_pre=0;
                read_var_stop_deep=0;
                assignment_modal=0;
                match=0;
            }
            if(read_var_modal_pre&&(source[i]=='['||source[i]=='('||source[i]=='='||((source[i]=='\''||source[i]=='\"')&&!match)))
            {
                read_var_modal=0;
                read_var_stop_deep++;
                if(source[i]=='\''||source[i]=='\"') match=1;
                if(source[i]=='=') assignment_modal=1;
                i++;continue;
            }
            if(read_var_modal_pre&&(source[i]==']'||source[i]==')'||(assignment_modal&&source[i]==',')||((source[i]=='\''||source[i]=='\"')&&match)))
            {
                if(!--read_var_stop_deep) read_var_modal=1;
                if(source[i]=='\''||source[i]=='\"') match=0;
                if(source[i]==',') assignment_modal=0;
            }
            if(!read_var_modal&&((source[i]=='\''||source[i]=='\"')&&!match)){i++;match=1;continue;}
            if(!read_var_modal&&((source[i]=='\''||source[i]=='\"')&&match)) match=0;
            i++;
        }
        while(var_in_law(source[i])) word[top++]=source[i++];
        if(is_typedef(word,top))
        {
            next_line(i);
            add_type_before(i);
            continue;
        }
        if(is_type(word,top))
        {
            read_var_modal=1;
            read_var_modal_pre=1;
            continue;
        }
        if(read_var_modal&&!is_var(word,top))
        {
            if(is_main(word,top))
            {
                read_var_modal=0;
                read_var_modal_pre=0;
                read_var_stop_deep=0;
                assignment_modal=0;
                match=0;
                continue;
            }
            vars.push_back(nullptr);
            vars.back()=new char[top+1];
            sprintf(vars.back(),word);
            vars.back()[top]='\0';
            if(lenth.empty()) lenth.push_back(5);
            else lenth.push_back(lenth.back()+1);
        }
        if(!match&&is_var(word,top)&&!isdigit(source[i-top-1])) modify(i,word,top);
    }
}

int main(int argv,char* argc[])
{
    freopen(argc[1],"r",stdin);
    freopen(argc[2],"w",stdout);
    var_type_init();
    T=(H=source)+fread(source,1,1000000,stdin);
    len_source=T-H;
    Main();
    fwrite(source,1,len_source,stdout);
    fclose(stdin);
    fclose(stdout);
    return 0;
}