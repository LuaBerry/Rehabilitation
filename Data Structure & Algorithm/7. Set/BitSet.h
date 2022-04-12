#ifndef __BitSet
#define __Bitset

typedef unsigned long BitSet;

#define BitSetNull 0
#define BitSetMax 32
#define SetOf(n) ((BitSet)1 << (n))

int IsMember(const BitSet s, int n);

void Add(BitSet* s, int n);

void Remove(BitSet* s, int n);

int Size(const BitSet *s);

void Print(const BitSet s);

void Println(const BitSet s);

#endif