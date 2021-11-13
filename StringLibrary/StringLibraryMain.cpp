#include <iostream> 
#include "MyString.h"
#include <cassert>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
    #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
    #define DBG_NEW new
#endif
using namespace thebetterstring;

void CreateMyStringWithString()
{
    MyString myString("Hello World!");
    assert(myString.ToString() == "Hello World!");  
    assert(myString.GetLength() == 12);

}

void CreateMyStringWithOtherMyString()
{
    MyString myString("Hello World!");
    MyString myString2(myString);
    assert(myString.ToString() == "Hello World!");
    assert(myString2.GetLength() == 12);
}

void ConcatenateMyStringWithString()
{
    MyString myString("Hello");
    myString.Concatenate(" World!");
    assert(myString.ToString() == "Hello World!");
    assert(myString.GetLength() == 12);
}

void ConcatenateMyStringWithAnotherMyString()
{
    MyString myString("Hello");
    MyString myString2(" World!");
    myString.Concatenate(myString2);
    assert(myString.ToString() == "Hello World!");
    assert(myString.GetLength() == 12);
    assert(myString2.ToString() == " World!");
    assert(myString2.GetLength() == 7);
}

void MyStringEqualsAnotherMyString()
{
    MyString myString("Hello World!");
    MyString myString2("This should change into - Hello World! -");
    myString2 = myString;
    assert(myString.ToString() == "Hello World!");
}

void CreatingConstMyStringAndExtendedAdditions()
{
    MyString myString("Hello");
    MyString myString2(" World");
    myString += myString2;
    MyString myString3 = myString + myString2;
    assert(myString3.ToString() == "Hello World World");

    /*myString3 += " Hello";
    const MyString myString4 = myString3 + " World";
    assert(myString4.ToString() == "Hello World World Hello World");*/

}

void TestingCopyConstructorWhenDeletedOneOfBoth()
{
    MyString myString("Hello World!");
    MyString myString2(myString);
    myString.~MyString();
    std::string testString = "Hello World!";
    const char* cstr = myString2.c_str();
    for (int i = 0; testString[i] != '\0'; i++)
    {
        assert(cstr[i] == testString[i]);
    }

}

void TestingMoveConstructor()
{
    //Memorie leak
    MyString myString("Hello World!");
    MyString myString2 = std::move(myString);
    std::string testString = "Hello World";
    const char* cstr = myString2.c_str();
    for (int i = 0; testString[i] != '\0'; i++)
    {
        assert(cstr[i] == testString[i]);
    }
}


using Iterator = thebetterstring::MyString::MyStringIterator<char>;
//Die testfälle sollten in einer eigenen Methode geschrieben werden
//jeder einzelne schritt alleine und in der main mit assert dann überprüfen
int main() // Einstiegsfunktion jedes compilers
{
    
    CreateMyStringWithString();
    CreateMyStringWithOtherMyString();
    ConcatenateMyStringWithString();
    ConcatenateMyStringWithAnotherMyString();
    MyStringEqualsAnotherMyString();
    //CreatingConstMyStringAndExtendedAdditions();
    //TestingCopyConstructorWhenDeletedOneOfBoth();
    TestingMoveConstructor();

    MyString test("Hello World");
    for (Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
    //std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';
    //myString.Concatenate(myString);
    //MyString otherString(myString);
    //std::cout << otherString << std::endl;
    //MyString yetAnotherString("AnotherWorld");
    //otherString = yetAnotherString;

    ////Teil2
    //std::cout << "Teil 2\n_________________________________" << std::endl;
    //MyString s1("Hello");
    //const MyString s2("World");
    //s1 += s2;
    //std::cout << s1 << std::endl;
    //MyString s3 = s1 + s2;
    //s3 += "Hello";
    //const MyString s4 = s3 + "World";
    //puts(s4);
    //To check memory leaks
    _CrtDumpMemoryLeaks();
    exit(0);
    //Teil3
    // 
    //const String test("Hello World");
   // for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
   //std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';


}
/*
    int a = 3;
    std::cout << &a << std::endl; //die Speicheradresse der variable 

    int* b = &a;  // ich lege einen Pointer an der eine speicheradresse beinhaltet
    std::cout << &b << std::endl; //die Peicheradresse des Pointers
    std::cout << b << std::endl;  //der Inhalt des Pointers (die Speicheradresse der variable a) 

*/

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
