#ifndef __SPECIALIZATION_H__
#define __SPECIALIZATION_H__

#include <QString>

// class template
template <class T>
class mycontainer {
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}

protected:    
    T element;
    T previousElement;
};


// class template specialization
template <>
class mycontainer <qreal> {
public:
    mycontainer (qreal arg) {element=arg;}
    qreal increase (){return (element += 0.1);}

protected:    
    qreal element;
};

//another template specialization
template <>
class mycontainer <QString>{
public:
	mycontainer(QString arg){element = arg;}
	QString increase(){ return(element = QString(element.toAscii() + QByteArray(1,'1')));}
protected:
	QString element;
	
};

#endif // __SPECIALIZATION_H__
