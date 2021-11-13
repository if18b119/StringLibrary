/*
Hier wird die Deklarireung von meiner String Klasse implementiert
auch die deklarierung muss in dem von mir erstellten namespace sein
*/
#include <iostream>
#include <stdint.h> //to ensure the size of the variables

#ifndef MyStringH
#define MyStringH

namespace thebetterstring
{

	
	class MyString
	{

		public:
			template <class T>
			class MyStringIterator
			{
			public:
				using ValueType = T;
				using PointerType = T*;
				using ReferenceType = T&;

			public:
				MyStringIterator(PointerType ptr)
				{
					this->current_ptr = ptr;
				}
				MyStringIterator& operator++()//increment than assing
				{
					//incrementiert den Pointer um den richtigen anteil an bytes vom pointertyp in unserem fall char*
					current_ptr++;
					return *this;
				}
				//assign than increment (postfix increment)
				//returned eine kopie und dann increment
				MyStringIterator operator++(int)
				{
					MyStringIterator iterator = *this;
					//call back to operator++() function to increment the pointer
					++(*this);
					return iterator;
				}
				MyStringIterator& operator--()
				{
					//incrementiert den Pointer um den richtigen anteil an bytes vom pointertyp in unserem fall char*
					current_ptr++;
					return *this;
				}
				MyStringIterator operator--(int)
				{
					MyStringIterator iterator = *this;
					//call back to operator++() function to increment the pointer
					--(*this);
					return iterator;
				}
				ReferenceType operator[](int index)
				{
					return *(current_ptr + index);
				}
				PointerType operator->()
				{
					return current_ptr;
				}
				ReferenceType operator*()
				{
					return *current_ptr;
				}
				bool operator==(const MyStringIterator& other) const
				{
					return current_ptr == other.current_ptr;
				}
				bool operator!=(const MyStringIterator& other) const
				{
					return !(*this == other);
				}

			private:
				PointerType current_ptr;


			};
			MyString(const char* arr); //conversion function //Konstruktor.
			~MyString();
			MyString(const MyString& string);  //Copy Constructor
			MyString(MyString&& string); //move constructor
			
			char* c_str() const; //getter für den data pointer der klasse, const weil nur ausgelesen wird
			const int GetLength()const; // lieber size_t verwenden
			friend std::ostream& operator<<(std::ostream& os, const MyString& str); //Als reference weil hier eine kopie kein sinn ergibt und mein objekt als read only (const reference)
			MyString operator=(const MyString& string);
			MyString operator=(const char* string);
			MyString& operator+=(const MyString& string);
			MyString& operator+=(const char* string);
			friend void puts(const MyString& string);
			MyString operator+(const MyString& string2);
			MyString operator+(const char* string2);
			void Concatenate(const char* another_string);
			void Concatenate(const MyString& myString);
			std::string ToString() const;
			const MyStringIterator<char> begin()
			{
				return MyStringIterator<char>(data);
			}
			const MyStringIterator<char> end()
			{
				return MyStringIterator<char>(data + length);
			}

		private:
			char* data=nullptr;
			int length;
			//Hilf Funktionen für das String handeln
			//um nicht jedes mal die for schleife zu schreiben
			void StringKopie(const char* string);
			//Um die länge zu kopieren
			void LengthKopie(int length);
			//Um die länge eines char arrays zu berrechnen lieber size_t verwenden size_t??
			int CalcLength(const char* string) const;
			char* ZsmFuegen(const char* string1, const char* string2)const;
			


	};
}
#endif