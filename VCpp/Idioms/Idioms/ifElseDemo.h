#ifndef __IFELSEDEMO_H__
#define __IFELSEDEMO_H__

template <bool Condition, typename TrueResult, typename FalseResult>
class if_;
 
template <typename TrueResult, typename FalseResult> 
struct if_<true, TrueResult, FalseResult>
{
/* True condition. Typedefs the type stored in TrueResult as result so that
we can access the type later.*/
  typedef TrueResult result;
};
 
template <typename TrueResult, typename FalseResult>
struct if_<false, TrueResult, FalseResult>
{
/* False condition. Typedefs the type stored in FalseResult as result so that
we can access the type later.*/
  typedef FalseResult result;
};
 
#endif // __IFELSEDEMO_H__
