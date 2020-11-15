/* 二叉堆的概念很简单，分为两种， 最大堆和最小堆。其中最大堆指的是任意节点的父节点的值
 * 都要比自身大，而最小堆指的是，任意节点的父节点都要比自身小。
 *  在插入和删除操作中只有两种操作， 上浮和下沉，通过这两种操作来使对结构平衡。
 * 时间复杂度是O（log(n))
 */

/*. C++ 标准库<algorithm>中有构建堆结构的函数， 不过上层是堆， 下层是vector或者数组。
 *
 */