#ifndef __NOOPERATOR_H__
#define __NOOPERATOR_H__

#include <QString>

class NoOperator{
public:
	NoOperator(int number, QString name){m_Number = number; m_Name = name;}
	
	bool operator>(NoOperator noOp);	
	
	int GetNumber(){return m_Number;}
	QString GetName(){return m_Name;}
	
protected:
	int m_Number;
	QString m_Name;
};

bool NoOperator::operator>(NoOperator noOp){
	if(m_Number > noOp.GetNumber()) return true;
	else return false;
}


#endif // __NOOPERATOR_H__
