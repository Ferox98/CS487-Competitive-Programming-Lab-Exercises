#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> ll;
    ll.emplace_front(12);
    ll.emplace_back(23);
    for (list<int>::iterator it = ll.begin(); it != ll.end(); it++) {
        cout << *it << " , ";
    }
    cout << endl;
}