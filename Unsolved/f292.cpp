#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef pair<int , int> pii;

const int N = 1e5 + 5;

pii set[N];

void print(int n){

    for(int i=1; i<=n; i++) cout << i << " ";
    cout << '\n';
    for(int i=1; i<=n; i++) cout << set[i].ff << " ";
    cout << '\n';
    for(int i=1; i<=n; i++) cout << set[i].ss << " ";
    cout << '\n';

    cout << '\n';

}

int queryUp(int x){

    if(set[x].ff == x) return x;

    return queryUp(set[x].ff);

}

int queryDown(int x){

    if(set[x].ss == x) return x;

    return queryDown(set[x].ss);

}

void update(int p , int q){

    int tempp = queryUp(p) , tempq = queryUp(q);

    int head = max(tempp , tempq) , tail = queryDown(min(tempp , tempq));

    set[head].ff = tail;
    set[tail].ss = head;

}

void countUp(int x , int& cnt , int& sum){

    //cout << "Here\n";

    sum += x;
    cnt++;

    if(set[x].ff == x) return;
    return countUp(set[x].ff , cnt , sum);

}

void countDown(int x , int& cnt , int& sum){

    //cout << "Here\n";

    sum += x;
    cnt++;

    if(set[x].ss == x) return;
    return countDown(set[x].ss , cnt , sum);

}

int main(){

    IO

    int n , m;

    while(cin >> n >> m){

        //int temp = n;

        for(int i=1; i<=n; i++) set[i] = mp(i , i);

        while(m--){

            int type;
            cin >> type;

            if(type == 1){

                int p , q;
                cin >> p >> q;

                update(p , q);

            }else if(type == 2){

                int p , q;
                cin >> p >> q;

                if(queryUp(p) != queryDown(q)){

                    int u = set[p].ff , d = set[p].ss;

                    //cout << "u = " << u << '\n';
                    //cout << "d = " << d << '\n';

                    if(u == p && d != p) set[d].ff = d;
                    if(d == p && u != p) set[u].ss = u;

                    set[d].ff = u;
                    set[u].ss = d;

                    set[p].ff = set[p].ss = p;

                    //print(temp);

                    update(p , q);

                }

            }else{

                int p;
                cin >> p;

                int cnt = -1 , sum = -p;

                countUp(p , cnt , sum);
                countDown(p , cnt , sum);

                cout << cnt << " " << sum << '\n';

            }

            //print(temp);

        }

    }

    return 0;

}