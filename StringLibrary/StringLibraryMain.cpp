#include <iostream> 
#include "MyString.h"
#include <cassert>
#include <stdlib.h>
#include <string.h>
#include "StringLibraryMain.h"

using namespace thebetterstring;
using Iterator = thebetterstring::MyString::MyStringIterator<char>; //um mir schreibarbeit zu sparren

void CreateMyStringWithString()
{
    std::cout << "| Test Name:    CreateMyStringWithString"<<std::endl;
    MyString myString("Hello World!");
    assert(myString.ToString() == "Hello World!");  
    assert(myString.GetLength() == 12);
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void CreateMyStringWithOtherMyString()
{
    std::cout << "| Test Name:    CreateMyStringWithOtherMyString" << std::endl;
    MyString myString("Hello World!");
    MyString myString2(myString);
    assert(myString.ToString() == "Hello World!");
    assert(myString2.GetLength() == 12);
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void ConcatenateMyStringWithString()
{
    std::cout << "| Test Name:    ConcatenateMyStringWithString" << std::endl;
    MyString myString("Hello");
    myString.Concatenate(" World!");
    assert(myString.ToString() == "Hello World!");
    assert(myString.GetLength() == 12);
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void ConcatenateMyStringWithAnotherMyString()
{
    std::cout << "| Test Name:    ConcatenateMyStringWithAnotherMyString" << std::endl;
    MyString myString("Hello");
    MyString myString2(" World!");
    myString.Concatenate(myString2);
    assert(myString.ToString() == "Hello World!");
    assert(myString.GetLength() == 12);
    assert(myString2.ToString() == " World!");
    assert(myString2.GetLength() == 7);
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void MyStringEqualsAnotherMyString()
{
    std::cout << "| Test Name:    MyStringEqualsAnotherMyString" << std::endl;
    MyString myString("Hello World!");
    MyString myString2("This should change into - Hello World! -");
    myString2 = myString;
    assert(myString.ToString() == "Hello World!");
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void CreatingConstMyStringAndExtendedAdditions()
{
    std::cout << "| Test Name:    CreatingConstMyStringAndExtendedAdditions" << std::endl;
    MyString myString("Hello");
    MyString myString2(" World");
    myString += myString2;
    MyString myString3 = myString + myString2;
    assert(myString3.ToString() == "Hello World World");
    myString3 += " Hello";
    const MyString myString4 = myString3 + " World";
    assert(myString4.ToString() == "Hello World World Hello World");
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void TestingCopyConstructorWhenDeletedOneOfBoth()
{
    std::cout << "| Test Name:    TestingCopyConstructorWhenDeletedOneOfBoth" << std::endl;
    MyString myString("Hello World!");
    MyString myString2(myString);
    myString.~MyString();
    std::string testString = "Hello World!";
    const char* cstr = myString2.c_str();
    for (int i = 0; testString[i] != '\0'; i++)
    {
        assert(cstr[i] == testString[i]);
    }
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void TestingMoveConstructor()
{
    std::cout << "| Test Name:    TestingMoveConstructor" << std::endl;
    MyString myString("Hello World!");
    MyString myString2 = std::move(myString);
    std::string testString = "Hello World";
    const char* cstr = myString2.c_str();
    for (int i = 0; testString[i] != '\0'; i++)
    {
        assert(cstr[i] == testString[i]);
    }
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void TestingIterator()
{
    std::cout << "| Test Name:    TestingIterator" << std::endl;
    int i = 0;
    const MyString test("Hello World");
    Iterator it= test.begin();
    for (Iterator it = test.begin(); it != test.end(); ++it)
    { 
        i++;
    }
    assert(i == test.GetLength());
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void TestingReverseIterator()
{
    std::cout << "| Test Name:    TestingReverseIterator" << std::endl;
    const MyString test("Hello World");
    int i = test.GetLength();
    for (Iterator it = test.r_begin(); it != test.r_end(); --it)
    {
        --i;
    }
    assert(i == 0);
    std::cout << "| Test Status:  Passed\n" << std::endl;
}

void TestMoveAssigmentOperator()
{
    std::cout << "| Test Name:    TestMoveAssigmentOperator" << std::endl;
    MyString test("Hello World");
    MyString test2("Hello World22!");
    test2 = std::move(test);


    assert(test2.ToString() == "Hello World");
}

void RunTests()
{
    std::cout << "Running Tests ...\n" << std::endl;

    CreateMyStringWithString();
    CreateMyStringWithOtherMyString();
    ConcatenateMyStringWithString();
    ConcatenateMyStringWithAnotherMyString();
    MyStringEqualsAnotherMyString();
    CreatingConstMyStringAndExtendedAdditions();
    TestingCopyConstructorWhenDeletedOneOfBoth();
    TestingMoveConstructor();
    TestingIterator();
    TestingReverseIterator();
    TestMoveAssigmentOperator();
    std::cout << "11 out of 11 Tests passed" << std::endl;
}


int main()
{
    
   
    RunTests();

}

