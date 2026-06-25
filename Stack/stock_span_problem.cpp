//asks: for each day; consecutive smaller or equal before it including the number itself( a type of NGL)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> SSP(const vector<int>& arr){
    vector<int> v;
    int n = arr.size();
    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        while (!s.empty() && s.top().second <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(i+1);
        }
        else{
            v.push_back(i-s.top().first)
        }
        s.push(make_pair(i, arr[i]));
    }
    return v;
}

int main(){
    vector<int> arr{100, 80, 60, 70, 60, 75, 85};
    vector<int> result = SSP(arr);

    for(int x: result){
        cout << x << " ";
    }
    return 0;
}

/*
 * Explanation:
 * This algorithm calculates the stock span for each day, which is the maximum number of consecutive days just before the given day (including the day itself) where the stock price was less than or equal to its price on the current day.
 * It works by finding the Nearest Greater Element to the left (NGL) using a stack. The stack stores pairs of `(index, value)`.
 * For each day's price, it pops all prices from the stack that are less than or equal to the current price.
 * If the stack becomes empty, it means all previous prices were smaller, so the span is `i + 1`. Otherwise, the span is the difference between the current index and the index of the nearest greater element (`i - s.top().first`).
 * Time complexity is O(N) since each element is pushed and popped exactly once.
 */