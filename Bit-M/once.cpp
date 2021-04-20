/*
Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3} 
Output: 2 
In the given array all element appear three times except 2 which appears once.

Input: arr[] = {10, 20, 10, 30, 10, 30, 30} 
Output: 20 
In the given array all element appear three times except 20 which appears once. 
*/

#include "bits/stdc++.h"
using namespace std;
int main(){

    int arr[] = { 3, 3, 2, 3 };
    int twos = 0,ones=0;
    int common_bit_mask=0;

    for(int i = 0;i<4;i++){
        twos = twos | (ones & arr[i]);
        ones = ones ^ arr[i];
        common_bit_mask = ~(ones & twos);
        ones &= common_bit_mask;
        twos &= common_bit_mask;
    }
    cout << ones;
    return 0;
}


