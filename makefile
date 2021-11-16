stringlibrary.exe: Program.o MyString.o
	g++ -std=c++14 -static Program.o MyString.o -o stringlibrary.exe
	
MyString.o: StringLibrary/MyString.cpp
		g++ -std=c++14 -c StringLibrary/MyString.cpp -o MyString.o
Program.o: StringLibrary/StringLibraryMain.cpp
		g++ -std=c++14 -c StringLibrary/StringLibraryMain.cpp -o Program.o
clean:
		rm -f Program.o MyString.o stringlibrary.exe