/* Checks if a string is a permutation (rearrangement of letters) of a
palindrome (word that is same forward and backword) */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool palPermCheck(string w){
  // insert all chars in w into a hash table
  // false == even, true == odd
  std::unordered_map<char, bool> hashMap;
  for(int i = 0; i < w.size(); ++i) {
    if(hashMap.find((char)w[i]) == hashMap.end()) {
      hashMap.emplace((char)w[i], true);
    }
    // if char is already in hash table, remove it
    else {
      hashMap.erase((char)w[i]);
    }
  }
  // at end, check that there is only one or none remaining chars
  if(hashMap.size() == 1 || hashMap.size() == 0){
    return true;
  }
  else {
    return false;
  }
}

int main(void) {
  string s;
  cout << "Enter string: ";
  cin >> s;

  cout << "Permutation of Palindrome? " << palPermCheck(s) << endl;

  return 0;
}
