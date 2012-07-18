#include <iostream>

//types redifned here since VS 2008 doesn't contain stdint.
#ifdef _MSC_VER
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#include "factorial.h"
#include "isPrime.h"
#include "ifandswitch.h"
#include "ifElseDemo.h"
#include "dimensionalAnalysis.h"

 
//preprocessor define constants can be used in your template metaprograms.
#ifndef LAST 
#define LAST 250
#endif

 int main()
{
	bool runRTFactorial = false;
	bool runCTFactorial = false;
	bool runPrimes = true;
	bool ifTest = false;
	bool hiddenExample = false;
	bool typeCheckingExample = false;
	const int numberToCompute = 5;//17;
	const int showIf = false;
	
	if(runPrimes){
		Prime_print<LAST> a; 
   		a.f();	
	}
	else if(runRTFactorial){
		RTFactorial runTimeFact(numberToCompute);
		std::cout<<"Run time factorial: "<<runTimeFact.GetFactorial()<<std::endl;		
	}
	else if(runCTFactorial){
		int compileTimeFact = CTFactorial<numberToCompute>::value;
		std::cout <<"Compile-Time Factorial: "<<compileTimeFact<<std::endl;
		
		std::cout<<"Compile-Time Factorial using long: " <<LFactorial<numberToCompute>::value<<std::endl;
	}
	else if(ifTest){
		IF<showIf>::EXEC();
		std::cout<<"\n";
		
		SWITCH< 2 > myTwoSwitch; // store for delayed execution
		myTwoSwitch.EXEC(); //execute the output of the switch here.
		std::cout<<"\n";
	}
	else if(hiddenExample){
		typedef long SomeHiddenType;
		if(IfType<SomeHiddenType,long>::result){
			//Some Hidden Type is actually a long, so we can treat it as one
			//with sureity.
			std::cout<<"SomeHiddenType is actually a long \n";
		}
		else{
			//Some Hidden Type is not a long, so we should treat it defensively
			//since it is not what we expect it to be.
			std::cout<<"SomeHiddenType is not a long \n";
		}
	}
	else if(typeCheckingExample){
		  //true is passed, so result is an int (the TrueResult type). So, this 
		  //line of code creates an int named number and sets its value to 3. 
		  if_<true, int, void*>::result number(3);
		  
		  std::cout<< "Sizeof int on this machine: "<<sizeof(number)<<std::endl;
		  std::cout<<"Sizeof void* on this machine: "<<sizeof(void *)<<std::endl;

		  //false is passed, so result is a void*. This line of code creates
		  //pointer, which is a void* pointer to number, created in line 27.
		  if_<false, int, void*>::result aPointer(&number);
		 
		 std::cout<<"Sizeof pointer on this machine: "<<sizeof(aPointer)<<std::endl;
		   
		 //more interesting, here we pass in a conditional comparing the size of void*
		   //to uint32. Since sizeof is platform dependent, we can choose the correct size
		   // AT COMPILE TIME for the void* pointer for the particular platform.
		   typedef if_<(sizeof(void *) > sizeof(uint32_t)), uint64_t, uint32_t>::result
		      integral_ptr_t;
		
		   //we can then convert the void* to a pointer of a known (and correct) size.
		   integral_ptr_t converted_pointer = reinterpret_cast<integral_ptr_t>(aPointer);
		   
		   std::cout<<"Sizeof converted pointer on this machine: "<<sizeof(converted_pointer)<<std::endl;
		   
	}
	else{
		//typedef Unit<1,0> Distance;
		//typedef Unit<0,1> Time;
		//typedef Unit<1,-1> Velocity;
		//typedef Unit<1,-2> Acceleration;
		
		#define Distance Unit<1,0>
		#define Time     Unit<0,1>
		#define Second   Time(1.0)
		#define Meter    Distance(1.0)
		
		Distance moved1 = Meter * 5;
		Distance moved2 = Meter * 10;
   		Time time1 = Second * 10;
   		Time time2 = Second * 20;
   		
   		//Time time4 = moved1 + time1;
		
	}
	std::cin.get();	
}
