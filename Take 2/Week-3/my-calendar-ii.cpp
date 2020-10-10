#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
    map<pii, int> pair;
    pii event(10, 20);
    pair[event] = 1;
    vector<pii> events;
    events.push_back(event);
    pii event2(10, 20);
    cout << pair[event2] << endl;
}