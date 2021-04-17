# Arrays

## Algorithms (Psuedocode)


### Linear Search

---

```c

    => Search(ARR, N, ITEM, LOC)

    j := 1
    while (j <= N)
        if (ARR[j] = ITEM)
            LOC := j
            exit
        
    LOC := -1
    exit

```

### Insertion

---

```c

    => Insert(ARR, N, LOC, ITEM)

    j := N
    while (j >= LOC)
        ARR[j+1] := ARR[j]
        j := j-1

    ARR[LOC] := ITEM
    N := N+1
    exit

```

### Deletion

---

```c

    => Delete(ARR, N, LOC, ITEM)

    ITEM := ARR[LOC]
    j := LOC
    while (j < N)
        ARR[j] := ARR[j+1]
        j := j+1

    N := N - 1
    exit

```

### Bubble Sort

---

```c

    => BubbleSort(ARR, N)

    k := 1
    while (k < N)
        j := 1
        while (j <= N-k)
            if (ARR[j] > ARR[j+1])
                temp := ARR[j+1]
                ARR[j+1] := ARR[j]
                ARR[j] := temp
                
            j := j+1
        k := k+1
    exit

```

### Binary Search

---

```c

    => BinarySearch(ARR, N, ITEM, LOC)

    beg := 1
    end := N

    while (beg < end)
        mid := floor((beg + end) / 2)
        if (ARR[mid] = ITEM)
            LOC := mid
            exit
        else if (ARR[mid] > ITEM)
            end := mid - 1
        else if (ARR[mid] < ITEM)
            beg := mid + 1

    LOC := -1
    exit

```