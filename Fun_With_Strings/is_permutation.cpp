// Determines whether one string is a permutation of another.
#include <string>
#include <string.h>
#include <assert.h>
#include <iostream>
#define ASCII_SIZE 128

using namespace std;

bool isPermutation(string s1, string s2){
	
	if(s1.length() != s2.length()){
		return false;
	} else{

		unsigned int a1[ASCII_SIZE];
		unsigned int a2[ASCII_SIZE];
		// Beware of memset!
		memset(a1, 0, ASCII_SIZE*sizeof(unsigned int));
		memset(a2, 0, ASCII_SIZE*sizeof(unsigned int));


		for(int i=0;i<s1.length();i++){
			a1[s1[i]] += 1;
		}
		
		for(int i=0;i<s2.length();i++){
			a2[s2[i]] += 1;
		}

		for(int k=0;k<ASCII_SIZE;k++){
			if(a1[k] != a2[k]){
				cout << k << endl;
				return false;
			}
		}
		return true;
	}
}

void test(){
	// Normal cases
	assert(isPermutation("Gandalf", "aGnalfd"));
	assert(!isPermutation("foo", "lo0f"));
	assert(!isPermutation("bar", "baar"));
	cout << "Normal cases OK" << endl;
	// Extreme cases
	// - We assume we have a 3 GB machine.
	// Create two strings, each of size 2^30.
	string s1('f', 2^30);
	string s2('e', 2^30);
	string s3('f', 2^30);
	assert(isPermutation(s1,s3));
	assert(!isPermutation(s2,s3));
	cout << "Extreme cases OK" << endl;
	// Nulls and illegal input
	assert(isPermutation("",""));
	assert(!isPermutation("","Gau"));
	cout << "Nulls and illegal input OK" << endl;
	// Strange input
	assert(isPermutation("Gandalf", "Gandalf"));
	cout << "Strange input OK" << endl;
}

int main(){
	test();
	return 0;
}
