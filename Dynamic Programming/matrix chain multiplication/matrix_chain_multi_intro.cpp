// Program:

// 1)MCM
// 2) Printing MCM (recursion/memoization)
// 3) Evaluate Expression to true/ Boolean Parenthesization (recursion/memoization)
// 4) min/max value of an expression (recursion/memoization)
// 5) Palindrome partitiating (recursion/memoization)
// 6) scramble string (recursion/memoization)
// 7) egg droping problem (recursion/memoization)


//general code;

int solve(int arr[], int i, int j){
    //base condition: think of the invalid input
    if ( i > j ){
        return 0;
    }

    int ans = 0;

    for(int k = i; k < j; k++){
        //calculate temperaroy answer
        int tempans = solve(arr, i, k) + solve( arr, k + 1, i ); //operations depends upon the question

        // ans = f(n)(tempans)
    }

    return ans;
}




