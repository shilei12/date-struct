/* 二叉堆的概念很简单，分为两种， 最大堆和最小堆。其中最大堆指的是任意节点的父节点的值
 * 都要比自身大，而最小堆指的是，任意节点的父节点都要比自身小。
 *  在插入和删除操作中只有两种操作， 上浮和下沉，通过这两种操作来使对结构平衡。
 * 时间复杂度是O（log(n))
 */

/*. C++ 标准库<algorithm>中有构建堆结构的函数， 不过上层是堆， 下层是vector或者数组。
 *
 */

// 1. make_heap(_first, _last, _comp)
// 2. push_heap(_first, _last, _comp)
// 3. pop_heap(_first, _last, _comp)
// 4. sort_heap(_first, _last, _comp)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintHeap(const vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> vec{9, 8, 7, 11, 2, 4, 3, 5};

    // build heap
    make_heap(vec.begin(), vec.end(), greater<int>()); // 采用最小堆/降序
    PrintHeap(vec); // 2 5 3 9 8 4 7 11

    // push to the vec firstly.
    vec.emplace_back(20);
    push_heap(vec.begin(), vec.end(), greater<int>());
    PrintHeap(vec); // 2 5 3 9 8 4 7 11 20

    pop_heap(vec.begin(), vec.end(), greater<int>());
    // minimum value in the vec has been replace at the end position of the heap
    // we need to pop it from the vec
    PrintHeap(vec); // 3 5 4 9 8 20 7 11 2
    vec.pop_back(); 
    PrintHeap(vec);// 3 5 4 9 8 20 7 11

    sort_heap(vec.begin(), vec.end(), greater<int>()); // heap sort, actually, calling the function pop_heap() several times
    PrintHeap(vec); // 20 11 9 8 7 5 4 3 
}