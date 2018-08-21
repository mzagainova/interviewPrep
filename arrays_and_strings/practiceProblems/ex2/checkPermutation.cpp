// given two strings, write a method to decide if one is a permutation of the other

// permutations use same characters, just in different order
// can put them in order, then test if they are equal

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool permCheck(string s1, string s2) {
  if(s1.size() != s2.size()) {
    return false;
  }

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  if(s1 == s2) {
    return true;
  }
  return false;
}

int main() {
  string s1, s2;

  cout << "Enter string 1: ";
  cin >> s1;
  cout << "Enter string 2: ";
  cin >> s2;

  cout << "Permutations? " << permCheck(s1, s2) << endl;

  return 0;
}
