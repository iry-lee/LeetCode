# C++ STL

## 序列式容器

### vector

### list

### deque

### stack

### queue

### heap

heap并不属于STL容器组件，它是一个幕后英雄，扮演priority queue的助手。priority queue 允许用户以任何次序将元素推入容器内，但是取出时一定是从优先权最高的开始。binary max heap 正是具有这样的特性，适合作为 priority queue的底层机制。

相比binary search tree，例如 RB-tree，虽然元素的插入和极值的取得都有O(logn)的表现，但是有点小题大作。一来是binary search tree 的输入需要有足够的随机性，二来 binary search tree并不容易实现，priority queue的复杂度最好能够介于queue 和 binary search tree之间才算是合适，这样，使用 完全二叉树 complete binary tree的binary heap也便应运而生。

使用完全二叉树的好处在于，可以直接使用连续的数组来存储数据。堆heap可以分为大顶堆max-heap和min-heap小顶堆。STL提供的是max-heap，如果想要构造小顶堆，只需要传入自己重写的比较函数即可。

#### push_heap()

时间复杂度O(logN)，它所做的操作是将vector的最后一个元素，加入到堆中。

### priority_queue

priority_queue是由max-heap实现

### slist

## 关联容器

标准的关联容器分为set（集合）和map（映射表）两大类，以及这两大类的衍生体multimap（多键集合）和multimap（多键映射表）。这些容器的底层机制由R-B Tree（红黑树）完成。RB-tree也是一个独立容器，但并不开放给外界使用。此外，SGI STL还提供了一个不在标准规格之列的关联式容器：hash table（散列表），以及以此hash table作为底层机制而完成的hash_set（散列表集合）、hash_map（散列映射表）、hash_multiset、hash_multimap。

关联式容器中没有所谓的头尾（只有最大元素、最小元素），所以不会有所谓 push_back()、push_front()、pop_back()、pop_front()、begin()、end()这样的操作。

### set

set的特性是，所有元素都回根据元素的键值自动被排序，set的元素不像map那样可以同时拥有实值和键值，set元素值就是其键值。set不允许两个元素具有相同的键值。

在set中，不能通过其迭代器改变其元素值。因为set的元素值就是其键值，关系到set元素在树中的位置，任意改变回破坏其结构。

由于RB-tree是一种平衡二叉搜索树，自动排序的效果不错，所以标准的STL set即以RB-tree作为底层机制。又由于set所开放的各种操作的接口RB-tree也都提供了，所以几乎所有的set操作行为都只是转调用RB-tree的操作行为而已。

#### set常用的一些函数

```c++
set<int> iset;
...
iset.size();	// 返回iset的大小
iset.count(i);	// 返回iset中i的数量
iset.insert(i);	// 将i插入到iset中	
iset.erase(i);	// 将i从iset中删除
iset.find(i);	// 在iset中查找i，如果找不到返回iset.end()
```

遍历操作：

```c++
set<int> iset;
...
set<int>::iterator ite1=iset.begin();
set<int>::iterator ite2=iset.end();
for(; ite1 != ite2; ++ite1)
    cout << *ite1;
```

查找操作：

```
ite1 = iset.find(3);
if(ite1 != iset.end())
	cout << "3 found" << endl;
```

### map

map的特性是，所有元素都会根据元素的键值自动被排序。map的所有元素都是pair，同时拥有实值（value）和键值（key）。pair的第一个元素被视为键值，第二元素被视为实值。map不允许两个元素拥有相同的键值。

在map中，我们可以使用迭代器修改元素的实值，但是不能修改它的键值。因此，map iterators 既不是 constant iterators 也不是一种 mutable iterators。



### multiset

multiset的特性以及用法与set完全相同，唯一的差别在于它允许键值重复，因为它插入操作采用的是底层机制RB-tree的insert_equal()而非insert_unique()。



### multimap

multimap的特性以及用法与map完全相同，唯一的差别在于它允许键值重复，因此它的插入操作采用的是底层RB-tree的insert_equal()而非insert_unique()。



## 无序关联容器