#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int ans = 0;
bool stop = false;
string s;

void print_grid(int** grid , int m , int n) {

    for (int i=0; i<m; i++) {

        for (int j=0; j<n; j++) {

            if (grid[i][j] == -1) cout << " *";
            else if (grid[i][j] == -2 || grid[i][j] == -5) cout << "  ";
            else if (grid[i][j] == -3) cout << " $";
            else if (grid[i][j] == -4) cout << " !";
            else cout << setw(2) << grid[i][j];

        }

        cout << '\n';

    }

}

void dfs(int** grid , int m , int n , int i , int j , int cnt){

    if(i < 0 || j < 0 || i >= m || j >= n) return;
    if(grid[i][j] == -3 || grid[i][j] == -4) stop = true , ans = grid[i][j];
    if(grid[i][j] != -2) return;

    grid[i][j] = cnt;

    //print_grid(grid , m , n);

    for(int ii=0; ii<4; ii++){

        if(s[ii] == 'U') dfs(grid , m , n , i - 1 , j , cnt + 1);
        else if(s[ii] == 'R') dfs(grid , m , n , i , j + 1 , cnt + 1);
        else if(s[ii] == 'D') dfs(grid , m , n , i + 1 , j , cnt + 1);
        else if(s[ii] == 'L') dfs(grid , m , n , i , j - 1 , cnt + 1);

        if(stop) break;

    }
    
    if(!stop) grid[i][j] = -5;

}

int main(){

    IO

    int m , n , sti , stj;
    cin >> m >> n >> sti >> stj >> s;

    int** grid = new int*[m];
    for(int i=0; i<m; i++) grid[i] = new int[n];

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++) cin >> grid[i][j];
        
    }

    dfs(grid , m , n , sti , stj , 0);

    if(ans == -3) cout << "Goal\n";
    else if(ans == -4) cout << "Trap\n";

    print_grid(grid , m , n);

    for(int i=0; i<m; i++) delete[](grid[i]);
    delete []grid;

    return 0;

}