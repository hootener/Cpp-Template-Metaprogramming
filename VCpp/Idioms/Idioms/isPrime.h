#ifndef __ISPRIME_H__
#define __ISPRIME_H__

#include <iostream>
 
// Adapted from Erwin Unruh's non-compiling TMP program. 
// Source taken from: http://en.wikibooks.org/wiki/C%2B%2B_Programming/Templates/Template_Meta-Programming#History_of_TMP

template <int p, int i>
class is_prime {
public:
        //enum { prim = (p==2) || (p%i) && is_prime<(i>2?p:0),i-1>::prim }; //should generate warning in gcc. Not in VC 
        enum { prim = (p==2) || ((p%i) && is_prime<(i>2?p:0),i-1>::prim) };
}; 
 
template<>
class is_prime<0,0> {
public:
        enum {prim=1};
}; 
 
template<>
class is_prime<0,1> {
public:
        enum {prim=1};
}; 
 
template <int i>
class Prime_print {      // primary template for loop to print prime numbers
public:
        Prime_print<i-1> a; 
        enum { prim = is_prime<i,i-1>::prim
        }; 
        void f() {
                if (prim)
                {
                        std::cout << "prime number:" << i << std::endl;
                }
                a.f();
        } 
}; 
 
template<>
class Prime_print<1> {   // full specialization to end the loop
public:
        enum {prim=0}; 
        void f() {
        }; 
}; 
 
#endif // __ISPRIME_H__



 //Erwin Unruh's original output (will not be shown when this version builds):
 //unruh.cpp 30: conversion from enum to D<2> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<3> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<5> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<7> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<11> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<13> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<17> requested in Prime_print
 //unruh.cpp 30: conversion from enum to D<19> requested in Prime_print