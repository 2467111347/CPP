#include<iostream>
#include<string>
#include<stack>
using namespace std;

const int N=1e6+2;
int exp[N],len;//exp[i] 存储的是某个逻辑符号的下标 
int num[N];//num[exp[i]] 
string str;
int n;

int strtoint(string str){
	int s=0;
	for(int i=0;i<str.size();i++){
		s=s*10+str[i]-'0';
	}
	return s;
}
int calc(){
	//栈
	stack<int> st; 
	for(int i=1;i<=len;i++){
		if(exp[i]>0){
			st.push(num[exp[i]]);
		}else if(exp[i]==-3){ // !
			int t=st.top();
			st.pop();
			st.push(!t);
		}else{
			int t1=st.top();
			st.pop();
			int t2=st.top();
			st.pop();
			if(exp[i]==-1){// &
				st.push(t1&t2);
			}else{
				st.push(t1|t2);
			}
		}
	}
	return st.top();
}
int main(){
	while(1){
		cin>>str;
		if(str[0]>='0'&&str[0]<='9'){
			n=strtoint(str);
			break;
		}else{
			if(str[0]=='x'){
				int t=strtoint(str.substr(1));
				exp[++len]=t;
			}else{
				if(str[0]=='&'){
					exp[++len]=-1;
				}
				if(str[0]=='|'){
					exp[++len]=-2;
				}
				if(str[0]=='!'){
					exp[++len]=-3;
				}
			}
		}
	}	
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		num[x]=!num[x];
		cout<<calc()<<endl;
		num[x]=!num[x];
	}
	return 0;
}

