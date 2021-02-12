# Linked Lists

## Design

```c

    Record NODE {
        1. Record INFO {
            1. ...
            2. ...
            .
            .
            .
        }

        2. Pointer LINK
    }

```

## Algorithms (Psuedocode)

### Traversal

---

```c

    => TraverseLL(START, INFO(), LINK())

    ptr := START

    while (ptr != NULL)
        Apply Procedure to INFO(ptr)
        ptr := LINK(ptr)
    
    exit

```

### Searching

---

```c

    => Search(START, INFO(), LINK(), LOC, ITEM) // UNSORTED

    ptr := START

    while (ptr !=  NULL)
        if (INFO(ptr) = ITEM)
            LOC := ptr
            exit
        
    LOC := NULL
    exit

```

```c

    => Search(START, INFO(), LINK(), LOC, ITEM) // SORTED

    ptr := START

    while (ptr != NULL)
        if (INFO(ptr) <  ITEM)
            ptr := LINK(ptr)
        else if (INFO(ptr) = ITEM)
            LOC := ptr
            exit
        else
            LOC := NULL
            exit
    
    LOC := NULL
    exit

    // Same time complexity as search for unsorted linked list

```

### Insertion

---

```c

    => Insert(START, AVAIL, INFO(), LINK(), LOC, ITEM)

    if (AVAIL = NULL)
        ERROR: Overflow
        exit
    
    newn := AVAIL
    AVAIL := LINK(AVAIL)
    INFO(newn) := ITEM

    if (LOC = NULL) // Start of list
        LINK(newn) := START
        START := newn
    else            // After LOC
        LINK(newn) := LINK(LOC)
        LINK(LOC) := newn

    exit

```

### Deletion

```c

    => Delete(START, AVAIL, INFO(), LINK(), LOC)

    if (START = NULL)
        ERROR: Underflow
        exit
    
    if (LOC = NULL) // Start of the list
        temp := START
        START := LINK(START)
        LINK(temp) := AVAIL
        AVAIL := temp
    else
        temp := LINK(LOC)
        LINK(LOC) := LINK(temp)
        LINK(temp) := AVAIL
        AVAIL := temp
    
    exit

```