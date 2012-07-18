Cpp-Template-Metaprogramming
============================

Some small examples of template metaprogramming in action. This code is helpful if you've read a tutorial or two and would like to see TMP put to work on some canned problems. This code has a very slight Qt dependency (hence the .PRO files). It is fairly easy to remove if you want to use this code as vanilla C++.

The Idioms folder contains Idioms.sln, use that if you're on Windows and have access to Visual Studio. Otherwise, you can just use the headers and cpp files in your IDE of choice. 

The Idioms project contains series of bools in the main function that determine which TMP tests are performed. You can run some, none, or all of them at once by setting the various bools to true and false. The NoOperator library just demonstrates pretty basic template usage.