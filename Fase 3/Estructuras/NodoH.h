#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

class NodoH{
public:
    char c;
    int n;
    NodoH *sig;
    NodoH *izq;
    NodoH *der;

    NodoH(char);
};