//A nibble is a four-bit aggregation or half an octet. There are two nibbles in a byte. 
//For example, 100 is represented as 01100100 in a byte (or 8 bits). The two nibbles are (0110) and (0100). 

//Problem statement :
//Given a number N, swap the two nibbles in it and find the resulting number. 

// C++ program to swap two nibbles in a byte
#include <bits/stdc++.h>
using namespace std;

int swap_Nibbles(int N) {
		int right = (N & 0b00001111);
		right= (right<<4);
		int left = (N & 0b11110000);
		left = (left>>4);
		return (right | left);
	}

int main(){
	int n = 100;
	cout << "Original: " << n << " Swapped: " << swapNibbles(n);	
	return 0;
}

//question link:- https://practice.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

//For more, visit https://www.geeksforgeeks.org/swap-two-nibbles-byte/



