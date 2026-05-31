// variations:

// subset sum
// equal sum partition
// count of subset sum
// minimum subset sum difference
// target sum
// no of subset and given difference



// we have 3 types of knapsack problem:

// a) fractional knapsack - greedy
// b) 0-1
// c) unbounded knapsack



// what is knapsack problem ??

// knapsack - bag
// input = bag capacity , weight arr(Kg), value arr(price)

// items =     it1     it2     it3     it4
// arr[w] =    w1      w2      w3      w4
// arr[v] =    v1      v2      v3      v4
// given capacity = (x)Kg

// constrain: fixed wight
// we try to fill (not necessary to fill completely) the bag to get maximum profit




//#  Fractions knapsack:     we can fill the fraction of the item and increase the profit fractionally. (greedy aproach)
//#  0-1 knapsack:           we need to fill the item as whole( either goes full (1) or dosent goes(0))
//#  Unbounded knapsack:     we can add infinitly an item in the bag, no limit.



// The 0-1 knapsack (DP):

// identification:
//     1. choice
//     2. optimal

// # DP = recursion + storage

