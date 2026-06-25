# not for every array should be sorted to apply binary search

Ex: like in binary search, we take -> if(arr[mid] == element);
    :- here we use different criteria.

    if its not the answer: we move left and right respectivily;
    :- but here different way to so. here we also negate the half and continue search on other part.


Example: peak element (the next upcomming question.)

<!--
Explanation:
This file introduces the concept of applying binary search on the answer space, pointing out that an array doesn't necessarily have to be strictly sorted.

Explanation steps:
1. Binary search can be adapted by defining specific criteria to navigate the halves.
2. Even if not purely sorted, if we can reliably eliminate one half of the search space based on a condition (like in the case of finding a peak element), binary search is still applicable.
-->