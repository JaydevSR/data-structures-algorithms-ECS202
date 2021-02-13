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

### Polish notation *(Arithmatic expressions)*

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


