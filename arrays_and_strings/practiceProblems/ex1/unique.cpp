// 1.1 - Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//loop through and mark which chars have been used, if notice duplicate return false
// runtime O(n)

bool uniqueCheck(string s) {
  if(s.size() > 128) {
    return false;
  }
  
  bool values[128] = {false};

  for(int i; i < s.size(); ++i) {
    if(values[(int)s[i]]) {
      return false;
    }
    values[(int)s[i]] = true;
  }
  return true;
}

int main() {
  string input;

  cout << "Enter string: ";
  cin >> input;

  cout << "Is this string unique (all chars different): " << uniqueCheck(input) << endl;

  return 0;
}
