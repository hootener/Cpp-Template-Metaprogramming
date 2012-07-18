TEMPLATE   = app
CONFIG	  += qt warn_on no_keywords embed_manifest_exe
QT        +=
TARGET     = NoOperator
HEADERS =  specialization.h nooperator.h
SOURCES =  main.cpp
LIBS      +=


# Treat warnings as errors
win32:QMAKE_CXXFLAGS += /WX

CONFIG(debug, debug|release){
	# Debug build options
	# Enable a read-only console window (i.e. for printf etc.)
	# CONFIG   += console
}
else{
	# Release build options
	# Enable a read-only console window (i.e. for printf etc.)
	# CONFIG   += console
}