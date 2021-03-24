# Stacks

## Design 

> *LIFO* : Last in first out

An element can be inserted of deleted at only one end of this linear DS, i.e, *the top*

*Example*: Stack of dishes, coins, clothes (not for me ;>)

### Representations

1. Array (Is static, has drawbacks)
2. Linked List


## Operations

### PUSH (insertion)

---

```c

    => Push(STACK[], TOP, MAX, ITEM) // ARRAY REPRESENTAION

    if (TOP = MAX)
        ERROR: Overflow
        exit
    else
        TOP := TOP + 1
        STACK[TOP] := ITEM
        exit

```
```c

    => PushLL(TOP, AVAIL, INFO(), LINK(), ITEM) // LL REPRESANTAION

    if (AVAIL = NULL)
        ERROR: Overflow
        exit
    new := AVAIL
    AVAIL := LINK(AVAIL)
    INFO(new) := ITEM
    LINK(new) := TOP
    TOP := new
    exit

```

### POP (deletion)

---

```c

    => Pop(STACK[], TOP, ITEM) // ARRAY REPRESENTATION

    if (TOP = 0)
        ERROR: Underflow
        exit
    else
        ITEM := STACK[TOP]
        TOP := TOP - 1
        exit

```
```c

    PopLL(TOP, AVAIL, INFO, LINK, ITEM) // LL REPRESENTATION

    if (TOP = NULL)
        ERROR: Underflow
        exit
    ITEM := INFO(TOP)
    temp := TOP
    TOP := LINK(TOP)
    LINK(temp) := AVAIL
    AVAIL := temp
    exit

```

## Applications

### Polish notation *(Arithmetic expressions)*

#### *Examples*

```m
Postfix: (2 * (3 + 4)) / 5  <=> (2 * [3 4 +]) / 5 <=> [2 3 4 + *] / 5 <=> 2 3 4 + * 5 /
```

or

```m
Prefix: (2 * (3 + 4)) / 5 <=> (2 * [+ 3 4]) / 5 <=> [* 2 + 3 4] / 5 <=> / * 2 + 3 4 5
```

#### *Algorithms*
1. Infix to Postfix / Prefix
2. Evaluation of Postfix / Prefix
            


# Queues

## Design

> *FIFO*: First in first out

### Representations

1. Array (Is static, has drawbacks)
2. Linked List

## Operations

### Enqueue
---

```c

    => Enqueue(Q, X) // Array Representation

    if ((Q.tail + 1) mod Q.length == Q.head)
        ERROR: Overflow
    else
        Q[Q.tail] = X
        if (Q.tail = Q.length)
            Q.tail = 1
        else
            Q.tail = Q.tail + 1

```

### Dequeue
---

```c

    => Dequeue(Q) // Array Representation

    if (Q.head == Q.tail)
        ERROR: Underflow
    else
        X = Q[Q.head]
        if (Q.head == Q.length)
            Q.head = 1
        else
            Q.head = Q.head + 1

```

# Algorithms Using Stacks

## Quicksort

Based on Divide-and-Conquer. 

### Description

```

    Subroutine: Find correct position of a number.

    1. Start from right
    2. Mark the first element from left (let A) and mark the first element from the right (let B).
    3. Scan the list from right to left starting at B and stop at first element smaller than A (call this new B).
    4. Interchange A and B.
    5. Mark the new position of B and scan from left to right till we find a number bigger than A.
    6. If a bigger number found then interchange A and this number and call this new B. 
    7. Repeat steps 3 to 6 until there are no interchages possible anymore.
    8. Then divide the list into two parts one before the correct postion of A and one after the correct position of A.
    9. If length of any of the lists is one then it is correctly sorted.
    10. Repeat this subroutine for the lists which have lenght greater than 1.

    Implementation: Maintain two stacks, lower and upper.  
    The stack lower consists of the lower indices of sublists and the stack upper consists of upper indices of the sublists.  
    Once a sublist is futher divided then we add then we push the lower and upper indices of the new sublists onto these stacks   
    and after that we pop the indices from these stacks and perform the quicksort subroutine on the list consisting of these indices.  
    We keep performing this routine till both the stacks are empty.

```

### Psuedocode

```c
    // Subprocedure for quicksort
    => Quicksub(A, BEG, END)

    left := BEG
    right := END
    loc := BEG

    while (TRUE)
        while (A[loc] <= A[right] and loc != right)
            right := right - 1
        
        if (loc = right)
            return loc

        if (A[loc] >= A[right])
            Interchange(A[loc], A[right])
            loc := right

        while (A[left] <= A[loc] and loc != left)
            left := left + 1
        
        if (loc = left)
            return loc

        if (A[loc] <= A[left])
            Interchange(A[loc], A[left])
            loc := left
    
```

```c

    => Quickmain(A, N)

    lowers := init empty Stack
    uppers := init empty Stack

    Push(lowers, 1)
    Push(uppers, N)

    while (not Empty(lowers) and not Empty(uppers))
        low = Pop(lowers)
        high = Pop(uppers)
        loc = Quicksub(A, low, high)
        if (loc != low)
            Push(lowers, low)
            Push(uppers, loc - 1)
        if (loc != high)
            Push(lowers, loc + 1)
            Push(uppers, high)
```

### Time complexity

1. Worst Case: When the list is already sorted. The algorithm required (n - i) comparisons to confirm that i'th element is at its correct position. So, the time complexity is O(n^2)

2. Average Case: At the k'th division of sublists, 2^(k-1) elements are correctly placed. So, there are log2(n) reductions. So, as each reduction makes atmost n comparisons then, the time complexity is O(n log n)
