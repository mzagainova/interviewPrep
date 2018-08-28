/* Two numbers, in reverse order stored in a linked list
Add the two numbers and return as a linked list */

#include <iostream>
#include <list>

using namespace std;

list<int> sumDigits(list<int> a, list<int> b) {
  int carry = 0;
  list<int> sum;
  std::list<int>::iterator it_a = a.begin();
  std::list<int>::iterator it_b = b.begin();
  for(; it_a != a.end() && it_b != b.end(); it_a++, it_b++) {
    if(it_a == a.end()) {
      sum.push_back((*it_b + carry) % 10);
      carry = (*it_b + carry) /  10;
    }
    else if(it_b == b.end()) {
      sum.push_back((*it_a + carry) % 10);
      carry = (*it_a + carry) /  10;
    }
    else {
      sum.push_back((*it_a + *it_b + carry) % 10);
      carry = (*it_a + *it_b + carry) /  10;
    }
    cout << sum.back() << "->";
  }
  cout << endl;
  return sum;
}

int main(void) {
  list<int> a = {7, 5, 2};
  list<int> b = {5, 6, 3};

  cout << "Sum: ";
  sumDigits(a, b);

  /*std::list<int>::iterator it_a = sumDigits(a, b).begin();
  for(;)*/

  return 0;
}
