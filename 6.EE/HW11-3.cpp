#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

//############################# Modify the code below #############################//
// ===================================== Sample 1 ===================================== //
void Sample1(){
    int n;
    cin >> n;

    // Allocate a vector with 10 elements
    vector<int> vec1(n);
    // TODO: Use subscripting (vec1[.]) to access elements
    for(int i=0; i<n; i++) vec1[i] = i * i;
    // TODO: Use subscripting (vec1[.]) to traverse and print elements
    for (int i=0; i<n; i++) cout << vec1[i] << " ";
    cout << endl;

    // Allocate an empty vector
    vector<int> vec2;
    // TODO: Use push_back() to add elements
    for(int i=0; i<n; i++) vec2.push_back(2 * i);
    // TODO: Use iterators to traverse and print elements
    for (vector<int>::iterator iter = vec2.begin(); iter!= vec2.end(); iter++) cout << *iter << " ";

    cout << endl;
    return;
}
// ==================================================================================== //

// ===================================== Sample 2 ===================================== //
// ===== point2d.h ===== //
class Point2D {
private:
    int x;
    int y;
public:
    Point2D();
    Point2D(int a, int b);
    friend ostream &operator << (ostream &out, const Point2D &p);
};
// ===== point2d.cpp ===== //
Point2D::Point2D() {
    x = y = -1;
}
Point2D::Point2D(int a, int b) {
    x = a;
    y = b;
}
ostream &operator << (ostream &out, const Point2D &p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

void Sample2(){
    int n;
    cin >> n;

    // Call Point2D() with size n
    vector<Point2D> vec(n);

    // TODO: Use subscripting (vec[.]) to call Point2D(int a, int b)
    for (int i=0; i<n; i++){
        vec[i] = Point2D(2*i , 3*i);
    }
    // TODO: Use subscripting (vec[.]) to traverse and print elements
    for (int i=0; i<n; i++) cout << vec[i] << " ";
    cout << endl;
    return;
}
// ==================================================================================== //

// ===================================== Sample 3 ===================================== //
void printVector(const vector<int> &vec){
    // TODO: Use subscripting (vec[.]) to traverse and print elements
    for (int i=0; i<vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
    return;
}

void Sample3(){
    int n = 5;
    vector<int> vec(n, -1); // vec = {-1,-1,-1,-1,-1}
    vector<int> u(3);
    for (int i = 0; i < 3; i++) u[i] = i; // u = {0,1,2}

    // TODO: Insert elements
    vec.insert(vec.begin() + 2 , u.begin() , u.end());
    printVector(vec);   // vec = {-1,-1,0,1,2,-1,-1,-1}

    // TODO: Insert a single element
    vec.insert(vec.begin() + 1 , 10);
    printVector(vec);   // vec = {-1,10,-1,0,1,2,-1,-1,-1}

    // TODO: Remove the last element
    vec.pop_back();
    printVector(vec);   // vec = {-1,10,-1,0,1,2,-1,-1}

    // TODO: Erase the fourth element
    vec.erase(vec.begin() + 3);
    printVector(vec);   // vec = {-1,10,-1,1,2,-1,-1}

    // TODO: Clear all elements
    vec.clear();
    printVector(vec);   // vec = {}
    return;
}
// ==================================================================================== //

// ===================================== Sample 4 ===================================== //
void Sample4() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(0);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(4);

    // TODO: Sort the vector
    sort(vec.begin() , vec.end());
    printVector(vec);                   // vec = {0,1,2,4,4,4,7,8,8,9}

    // TODO: Reverse the vector
    reverse(vec.begin() , vec.end());
    printVector(vec);                   // vec = {9,8,8,7,4,4,4,2,1,0}

    // TODO: Find the number 8
    vector<int>::iterator iter;
    for(iter = vec.begin(); iter != vec.end(); iter++) if(*iter == 8) break;
    if (iter != vec.end())
        cout << "8 is in the vector." << endl;
    else
        cout << "8 is not in the vector." << endl;
    return;
}
// ==================================================================================== //

//############################# Modify the code above #############################//

//############################# Do not modify the code below #############################//
int main(){
    int choice;
    cin >> choice;

    if (choice == 1)
        Sample1();
    else if (choice == 2)
        Sample2();
    else if (choice == 3)
        Sample3();
    else if (choice == 4)
        Sample4();
    else
        cout << "Invalid choice" << endl;

    return 0;
}
//############################# Do not modify the code above #############################//