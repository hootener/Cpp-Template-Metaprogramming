//System Includes
#include <QApplication>
#include <QMessageBox>

//Application Includes
#include "specialization.h"
#include "nooperator.h"

//Simple function template
template <class T>
T GetMax(T a, T b){
	return (a > b ? a:b);
}

QString TemplateSpecialization(){
	QString output;	
	mycontainer<int> intContainer(5);
	mycontainer<qreal> qrealContainer(3.2);
	mycontainer<QString> qStringContainer("abc");
	output = QString("The increased output: %1, %2, %3").arg(intContainer.increase()).arg(qrealContainer.increase()).arg(qStringContainer.increase());
	return output;	
}

int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	bool operatorTest = false;
	QMessageBox box;
	NoOperator a(7, "a"), b(6, "b");
	
	if(operatorTest){
		box.setText(QString("%1 is larger.").arg(GetMax<NoOperator>(a,b).GetName()));
	}
	else{
		box.setText(TemplateSpecialization());
	}
	
	box.show();
	return app.exec();
}


