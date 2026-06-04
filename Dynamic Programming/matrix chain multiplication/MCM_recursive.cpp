//given: //dim of matrix arr[];
//task = multiply all the martix with minimal cost
//#cost = multiply(dim of resultant metrix)* column of first matix/row of second matrix
//eg: m1(2*3), m2(3*6); cost = 2 * 6 * 3 = 36;

//identification:
//given: string/arr[]
//impulse to break/divide into two and solve seperately -> find ans for both part -> f(n)(ans1,ans2) = main answer


//ex: arr[] = 40 20 30 10 30
//M1 = 40*20
//M2 = 20*30
//M3 = 30*10
//M4 = 10*30

//general... arr[i-1]*ar[i]

#include <iostream>
#include <vector>
using namespace std;


int solve(const vector<int>& arr, int i, int j){
    
    //base condition
    if(i >= j){       //single index; pointing to single index; size = 1 -> invalid input 
        return 0;
    }
    int mn = INT_MAX;

    for(int k = i; k < j; k++){
        //finding temp answer
        int temp = solve(arr,i,k) + solve(arr,k+1, j) + (arr[i-1]*arr[k]*arr[j]); // cost to do fn(i -> k) and fn(k+1 -> j) 
        
        mn = min(temp,mn);
    }
    return mn;
}

int main(){
    // scheme: k = i to k = j-1 -> fn(i to k) and fn(k+1 to j)
    //         k = i+1 to k = j -> fn(i to k-1) and fn(k to j) 
    vector<int> arr{40,20,30,10,30};
    int i = 1; // temp = arr[i-1][k] / arr[k+1][j]
    int j = arr.size() - 1;
    cout<<solve(arr,i,j);
    return 0;
}