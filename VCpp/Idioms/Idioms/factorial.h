#ifndef __RTFACTORIAL_H__
#define __RTFACTORIAL_H__

//Run-time factorial example.
class RTFactorial{
	public:
		RTFactorial(int num);
		int GetFactorial(){ return m_Factorial;}
	protected:
		int m_Factorial;
		int CalculateFactorial(int num);
};

RTFactorial::RTFactorial(int num){
	m_Factorial = CalculateFactorial(num);
}

int RTFactorial::CalculateFactorial(int num){
	if (num == 0) return 1;
    return num * CalculateFactorial(num - 1);
}
#endif // __FACTORIAL_H__



// Compile-time TMP factorial example.
// Note that the recursive base case is handled through 
// the use of TEMPLATE SPECIALIZATION.

#ifndef __CTFACTORIAL__
#define __CTFACTORIALAL__

//Base recursive case
template <int N>
struct CTFactorial 
{
    enum { value = N * CTFactorial<N - 1>::value };
};
 
//Terminating condition - uses template specialization.
template <>
struct CTFactorial<0> //Specialized not on a type, but a constant.
{
    enum { value = 1 };
};

#endif // __CTFACTORIAL__

#ifndef __DBLFACTORIAL__
#define __DBLFACTORIAL__

//Another factorial implementation. This implementation does not use enums.

template <unsigned long N>
struct LFactorial{
	static unsigned const value = N * LFactorial<N-1>::value;
};

template<>
struct LFactorial<0>{
	static unsigned const value = 1;
};
#endif