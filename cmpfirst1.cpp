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
vector<string> rl[200];

set<char> fir(char ch){
    set<char> as,ts;
    int i,j;
    char c;
    for(i=0;i<rl[ch].size();i++){
        for(j=0;j<rl[ch][i].size();j++){
            c=rl[ch][i][j];
            if(isupper(c)){
                ts=fir(c);
                //if(!ts.contains('e')){
                if(ts.end()==ts.find('e')){
                    as.insert(ts.begin(),ts.end());
                    break;
                }
                ts.erase('e');
                as.insert(ts.begin(),ts.end());
            }
            else {
                as.insert(c);
                break;
            }
       }
    }
    return as;
}

int main()
{
    int i,j,a,b,ts,f=1,cn=0;
    freopen("test.txt","r",stdin);
    rl['S'].push_back("ABbc");
    rl['A'].push_back("cB");
    rl['A'].push_back("e");

    rl['B'].push_back("d");
    rl['B'].push_back("e");
    set <char> sta;
    set <char> ::iterator it;
    cout<<"first(S):\n";
    sta=fir('S');
    for (it=sta.begin(); it!=sta.end(); ++it) cout << ' ' << *it;
    cout<<"\n\nfirst(A):\n";
        sta=fir('A');
    for (it=sta.begin(); it!=sta.end(); ++it) cout << ' ' << *it;
    cout<<"\n\nfirst(B):\n";
    sta=fir('B');
    for (it=sta.begin(); it!=sta.end(); ++it) cout << ' ' << *it;

    return 0;
}
