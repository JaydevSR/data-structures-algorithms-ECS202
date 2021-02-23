# Recursion

Recursion simplifies many algorithm implementations.

> Refers to subroutines calling themsleves. 

Recursion requires a base case to avoid an infinite callback of functions. Each time the function calls itself then it should be getting closer to the base citeria.

The base criteria should not contain a callback to itself.

## Level and Depth

***Level***  
If P is a recursive procedure then:
1. First call to P is assigned level 1
2. With each subsequent call the level is increased by 1

***Depth***
The depth of a recursive procedure is the maximum level that the procedure reaches during its execution.

## Examples

### Factorial

```c

    => Factorial(N)

    if (N = 0)
        return 1
    else
        return N * Factorial(N-1)

```

### Ackermann Function

1. if m = 0 : A(m,n) = n+1

2. If m != 0 but n = 0 : A(m,n) = A(m-1, 1)

3. If m != 0 and n != 0 : A(m,n) = A(m-1, A(m, n-1))

### Fibonacci Sequence

1. if n = 0 or n = 1 then F(n) = 1.

2. Otherwise, F(n) = F(n-1) + F(n-2)

```c

    => Fibb(n)

    if (n = 0 or n = 1)
        return 1
    else
        return Fibb(n-1) + Fibb(n-2)

```


### Towers of Hanoi


1. Three pegs labeled A, B, C. There are a finite number of disks placed on peg A with decreasing size.
2. The objective is to move the disks from peg A to peg C using peg B. Only one disk can be moved at a time and it should be on the top of a peg. Also at no step larger disk can be placed on top of the smaller disk.

***Solution***
```
1. for n = 1: A -> C

2. for n = 2: A -> B, A -> C, B -> C 

3. for n = 3: A -> C, A -> B, C -> B, A -> C, B -> A, B -> C, A -> C
```
and so on...

So, in general to move n disks from A to C using B as an auxilary we move the top (n-1) disks from A to B, then move the n'th disk from A to C and then move the (n-1) disks from B to C using A as an auxilary peg. This algorithm can be implemented recursively.

### Psuedocode

```c

    => Tower(N, A, B, C) // Move N disks from A to C using B as auxilary

    if (N = 1)
        t = Pop(A)
        Push(C, t)
    if (N > 1)
        Tower(N-1, A, C, B) // A -> B, C is auxilary
        t = Pop(A)
        Push(C, t)
        Tower(N-1, B, A, C) // B -> C, A as auxilary
    exit

```

This recursive algorithm requires (2^n - 1) moves.