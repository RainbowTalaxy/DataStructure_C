# DataStructure_C
*Normal data structure*

|file|name
|:-:|:-:
|SeqList |循序表
|LinkList |单链表
|SeqStack |顺序栈
|LinkStack |链栈
|SeqQueue |顺序队列
|LinkQueue |链队列
|DiaMatrix |对角矩阵
|SymMatrix |对称矩阵
|TriMatrix |三角矩阵

可以在该目录新建一个test.c文件，然后键入：
```c
#include"DiaMatrix.c"

int main() {
    DiaMatrix * m = create_diamatrix(0, 1);
    print_diamatrix(m);
}
```
运行后可以获得输出：
```
[ 0 0 0 1 1 1 1 1 1 1 ]
[ 0 0 0 0 1 1 1 1 1 1 ]
[ 0 0 0 0 0 1 1 1 1 1 ]
[ 1 0 0 0 0 0 1 1 1 1 ]
[ 1 1 0 0 0 0 0 1 1 1 ]
[ 1 1 1 0 0 0 0 0 1 1 ]
[ 1 1 1 1 0 0 0 0 0 1 ]
[ 1 1 1 1 1 0 0 0 0 0 ]
[ 1 1 1 1 1 1 0 0 0 0 ]
[ 1 1 1 1 1 1 1 0 0 0 ]
```
