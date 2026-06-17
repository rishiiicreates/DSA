/*
Tower of Hanoi:

This problem has 3 rods: Source, Helper, and Destination, and N disks stacked on the source rod from biggest (bottom) to smallest (top). Goal is to move all disks from Source to Destination.

Rules:
1) Move only one disk at a time.
2) Only top disk can be moved.
3) Bigger disk cannot be placed on smaller disk.

Core idea:
To move N disks, you first need to move the top (N-1) disks out of the way. Then move the largest disk to destination. After that, move the (N-1) disks back onto the largest disk.

So recursion becomes:
1) Move (N-1) disks from Source -> Helper
2) Move largest disk from Source -> Destination
3) Move (N-1) disks from Helper -> Destination

Base case:
If only 1 disk exists, directly move it to destination.

Minimum moves follow:
T(n) = 2*T(n-1) + 1
which simplifies to:
2^n - 1

Time Complexity: O(2^n)
Space Complexity: O(n)

Main intuition:
A big problem is solved by solving two smaller identical problems around one main move.
*/


#include <iostream>
using namespace std;

void solve(int s,int d, int h, int n){

    //base condition:
    if(n==1) {
        cout<< s<< "->" << d <<endl;
        return;
    }
    //hypothesis
    solve(s,h,d,n-1);
    cout<<s<< "->" <<d<<endl;
    solve(h,d,s,n-1);

}
int main(){
    int n;
    cin>>n;
    int S = 1;
    int H = 2;
    int D = 3;
    solve(S,D,H,n);
    return 0;
}