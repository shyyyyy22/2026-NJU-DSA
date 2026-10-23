# 2026-NJU-DSA
## This is a repository for learning in NJU-DSA
All DataStructures are in `DataStructure.h` and all algorithms are in `Algorithms.h`, they are STB files.
If you wany to use a datastructure or related algorithms, following is an example:
```cpp
#define DS_SINGLYLINKEDLIST_IMPLEMENTATION // To use SinglyLinkedList
#include "DataStructure.h"
// You can use SinglyLinkedList now
#define ALGO_STRING_IMPLEMENTATION
#include "Algorithms.h"
// You can use some algorithms related to String now
// Code...
```
If you want to use all ds and algo:
```cpp
#define DS_IMPLEMENTATION
#define ALGO_IMPLEMENTATION
#include "Algorithms.h" // Must be included before DataStructure.h
#include "DataStructure.h"
```

## The DataStuuctures supported now (2026-10-16):

1. SeqList
2. SinglyLinkedList
3. CircularLinkedList
4. DoublyLinkedList 
5. SeqStack
6. LinkedStack
7. SeqQueue
8. LinkedQueue
9. PQueue
10. SeqDeque
11. SymmetricMatrix
12. TriDiagonalMatrix
13. BandMatrix
14. SparseMatrix
15. OrthogonalList
16. String
17. GenList
18. BinaryTree
19. ThreadTree
20. Tree
21. MinHeap
 
## The Algorithms supported now (2026-10-10):
- String
1. BF
2. KMP