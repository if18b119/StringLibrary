stringlibrary.exe: String.o
	g++ -std=c++14 -static StringLibrary/String.o -o stringlibrary.exe
	
String.o: StringLibrary/MyString.cpp
		g++ -std=c++14 -c StringLibrary/MyString.cpp -o String.o