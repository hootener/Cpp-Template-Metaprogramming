TEMPLATE   = app
CONFIG	  += qt warn_on no_keywords console embed_manifest_exe
QT        +=
TARGET     = Idioms
SOURCES += main.cpp
HEADERS += factorial.h isPrime.h ifandswitch.h ifElseDemo.h dimensionalAnalysis.h
LIBS    +=


# Treat warnings as errors
#win32:QMAKE_CXXFLAGS += /WX

CONFIG(debug, debug|release){
	# Debug build options
}
else{
	# Release build options
}