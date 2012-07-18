#ifndef __IFANDSWITCH_H__
#define __IFANDSWITCH_H__

#include <iostream>

/* NOTE: the IF and SWITCH statements shown here are useful for illustrative
purposes but they aren't really robust enough for everyday use. We will
need meta-metaprogramming constructs in order to make IF and SWITCH robust
enough for practical use. 

These examples also illustrate the class based approach to TMP, whereas the
factorial example implements TMP using structs. Either approach is valid.*/

//FOR USELESS IF

template< bool Condition >
class IF {
public:
    static inline void EXEC(){
    std::cout << "Statement is true";
    }
};

template<>
class IF<false> {
public:
    static inline void EXEC(){
    std::cout << "Statement is false";
    }
};



//FOR  USELESS SWITCH
template< int _case >
class SWITCH {
public:
    static inline void EXEC(){
       std::cout << " SWITCH - default ";
    }
};

template<>
class SWITCH< 1 > {
    public:
    static inline void EXEC(){
        std::cout << " SWITCH - 1 ";
    }
};

template<>
class SWITCH< 2 > {
    public:
    static inline void EXEC(){
        std::cout << " SWITCH - 2 ";
    }
};
#endif // __IFANDSWITCH_H__

///Alternate if, can be used to compare types.

template<typename X, typename Y> // False condition.
struct IfType
{
   enum { result = 0 };
};
 
template<typename T>
struct IfType<T, T> // True condition, both types are the same.
{
   enum { result = 1 };
};

