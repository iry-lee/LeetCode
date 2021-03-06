# 引言
建立这个项目的目的是刷题的时候方便在本地进行调试，并辅助在LeetCode上刷题的工具。
针对于LeetCode上的C++题目，提供一些从文件或者命令行读取数据输入的函数，
使得使用者稍加组合就可以在本地对所写的程序进行调试。

# 文件目录
- my_solution 对应的题号的题解程序
- main.cpp 这是整个程序的入口
- solution.cpp 这是一个solution模板
- utils.cpp 这提供了一些工具函数
- utils.h

# 使用指南
### main.cpp
这是程序的入口，在这里需要做的主要是将utils.h中提供的获取输入的函数与自己的solution的函数连接起来。
修改完以后，只需要将 include 文件夹的中间的数字改成对应的题号，就可以运行对应的题解了。

### solution.cpp
这相当于是一个solution的模板，在my_solution中新增自己的题解的时候，只需要新建一个名字为题号的文件夹，并把这个文件复制进去
代码与LeetCode上的空白代码相同。可以完全在LeetCode和本地之间无缝复制粘贴。

### utils.cpp / utils.h
这主要是为了方便程序的输入输出搭建了一些工具，比如读入数组，读入整数，读入string。
当前刷题的数量较少，可能并不能完全覆盖所有的输入，随着笔者的刷题也会逐渐完善。
目前的鲁棒性也存在问题，比如，输入数组"[a,b,c,d]"，没有处理这里面带有空格的情况。
后续也会进一步完善。

# 更新方向
1. 增强输入函数的鲁棒性
2. 一批运行多测试点
3. 测试点的自测
4. ……
