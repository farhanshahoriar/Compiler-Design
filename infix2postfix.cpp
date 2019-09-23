#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;
char infix[100],pf[100],prc[200],tc;
int main()
{
    int i,j,a,b,ts,f=1,cn=0,pi=0,ln;
    freopen("test.txt","r",stdin);
    prc['+']=1;
    prc['-']=1;
    prc['*']=2;
    prc['/']=2;
    prc['^']=3;
    prc['(']=0;

    stack <char> st;
    scanf("%s",infix);
    ln=strlen(infix);
    //P2(infix,ln)
    //(A-B)*(D/E)
    //A+(B*C-(D/E^F)*G)*H
    // ABC*DEF^/G*-H*+
    for(i=0;i<ln;i++){
    P(i)
        tc=infix[i];
        if(isalnum(infix[i])){
            pf[pi++]=infix[i];
        }
        else if(infix[i]==')'){
            while(st.top()!='('){
                pf[pi++]=st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if(st.empty()||tc=='(' || prc[st.top()]<=prc[tc])st.push(tc);
            else {
                while(1){

                    pf[pi++]=st.top();
                    st.pop();
                    if(st.empty()||prc[st.top()]<prc[tc]){
                        st.push(tc);
                        break;
                    }

                }

            }
        }

    }

    while(!st.empty()){
        pf[pi++]=st.top();
        st.pop();
    }

    puts(pf);
    return 0;
}
