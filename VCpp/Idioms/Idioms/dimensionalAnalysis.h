#ifndef __DIMENSIONALANALYSIS_H__
#define __DIMENSIONALANALYSIS_H__

//TMP implementation of some SI units. Note that, numerically, all
//of these values are doubles. However, this TMP approach allows us 
//to provide meta information to the doubles. This meta information can
//then be checked at comopile time to prevent things like adding a distance
//to a time....which is good since adding distance to time results in 
//gibberish in most scientific circles.

template<int d,int t> class Unit
{
    double value;
public:
    Unit(double n){
        value = n;
    }
    Unit<d,t> operator+(Unit<d,t> n){
        return Unit<d,t>(value + n.value);
    }
    Unit<d,t> operator-(Unit<d,t> n){
        return Unit<d,t>(value - n.value);
    }
    Unit<d,t> operator*(double n){
        return Unit<d,t>(value * n);
    }
    Unit<d,t> operator/(double n){
        return Unit<d,t>(value / n);
    }       
};


#endif // __DIMENSIONALANALYSIS_H__
