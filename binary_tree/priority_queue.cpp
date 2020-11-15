#include <queue>
#include <iostream>
using namespace std;

void showPriority1(priority_queue<int>& a)
{
    while (!a.empty()) {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;
}

void showPriority2(priority_queue<int, vector<int>, greater<int> >& a)
{
    while (!a.empty()) {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;
}

int main()
{
    // 存放基础类型
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (int i = 0; i < 10; ++i) {
        maxHeap.push(i);
        minHeap.push(i);
    }
    showPriority1(maxHeap); // 9 8 7 6 5 4 3 2 1 0 
    showPriority2(minHeap); // 0 1 2 3 4 5 6 7 8 9 
    return 0;
}