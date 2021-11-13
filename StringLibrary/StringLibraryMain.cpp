#include <iostream> 
#include "MyString.h"
#include <cassert>
#include <stdlib.h>
#include <string.h>

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
int main()
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


}
/*
    int a = 3;
    std::cout << &a << std::endl; //die Speicheradresse der variable 

    int* b = &a;  // ich lege einen Pointer an der eine speicheradresse beinhaltet
    std::cout << &b << std::endl; //die Peicheradresse des Pointers
    std::cout << b << std::endl;  //der Inhalt des Pointers (die Speicheradresse der variable a) 

*/
