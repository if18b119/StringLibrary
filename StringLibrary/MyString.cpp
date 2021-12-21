#include "MyString.h"

namespace thebetterstring
{

	MyString::MyString(const char* arr) //const weil das char array nicht ver�ndert wird, als pointer weil wenn man einen array einer funktion �bergibt nicht die gr��e des arrays mitgegeben wird
	{
		this->length = 0; //beim erstellen des Objekts die l�nge am anfang auf 0 setzen
		if (arr != nullptr)
		{			
			this->length = CalcLength(arr);
			//hier wird kopiert weil ich nicht weiß ob arr am stack oder heap ist
			CopyString(arr);
		}
		else {
			this->data = new char[0];
		}
	}

	MyString::~MyString()
	{
		if (this->data != nullptr)
		{
			delete[]data;
			data = nullptr;
		}
			
		
	}

	//Copy Constructor
	MyString::MyString(const MyString& string)
	{
		CopyLength(string.length);
		CopyString(string.data);
	}

	//Move constructor
	MyString::MyString(MyString&& string)
	{
		if (this != &string)
		{
			// Move constructor
			// It will simply shift the resources,
			// without creating a copy.
			CopyLength(string.length);

			if (data != nullptr)
				delete[] data;
			data = string.data;
			string.data = nullptr;
		}
		
	}

	void MyString::CopyString(const char* string)
	{

		delete[] this->data;
		data = nullptr;
		this->data = new char[this->length + 1]; //hier wird speicher f�r die l�nge des �bergegebenen arrays allokiert / +1 um den null-terminator dazu zu tun
		for (int i = 0; i < this->length; i++)
		{
			this->data[i] = string[i];
		}
		//null terminator dazu tun
		this->data[length] = '\0';
	}

	void MyString::CopyLength(int length)
	{
		this->length = length;
	}

	int MyString::CalcLength(const char* string) const
	{
		int length = 0;
		for (int i = 0; string[i] != '\0';i++)
		{
			length++;
		}
		return length;
	}

	char* MyString::link(const char* string1, const char* string2)const
	{
		

		//Hier ein Objekt angelegt damit der Garbage kollektor die berreinigung übernimmt
		//Wenn mit new einen neuen char* angelegt wurde hier um die 2 zusammen zu fügen gäbe es einen memory leak
		MyString tmpString(string1);
		tmpString.Concatenate(string2);
		char * tmp = (char *)tmpString.c_str();
		//delete[] tmpString.data;
		tmpString.data = nullptr;
		return tmp;
		
	}

	MyString:: operator const char* ()const
	{
		return c_str();
	}

	const char* MyString::c_str() const
	{
		return this->data;

	}

	const int MyString::GetLength()const
	{
		return this->length;
	}

	std::ostream& operator<<(std::ostream& os, const MyString& str)
	{
		int i = 0;
		while (str.data[i]!='\0')
		{
			os << str.data[i];
			i++;
		}
		return os;
	}
	char MyString::operator[](int index)
	{
		return *(data + index);
	}

	MyString MyString :: operator+(const MyString& string2)
	{
		char* tmp = this->link(this->data, string2.c_str());
		MyString result(tmp);

		delete[] tmp;
		return result;
	}

	MyString MyString:: operator+(const char* string2)
	{
		char* tmp = this->link(this->data, string2);
		MyString result(tmp);
		delete[] tmp;
		return result;
	}

	std::string MyString::ToString() const
	{
		std::string tmp = "";
		for (int i = 0; this->data[i] != '\0'; i++)
		{
			tmp += this->data[i];
		}
		return tmp;
	}


	// Zuweisungsoperator (copy assigment operator)
	MyString MyString::operator=(const MyString& string)
	{
		if (this != &string) // wenn es keine Zuweisung an sich selbst ist
		{
			//delete data; // l�sche bisherige Daten
			int len = CalcLength(string.data); // Gr��e?
			CopyLength(len); // neue größe setzen
			CopyString(string.c_str()); // Daten �bernehmen
			
		}

		return *this; // zur�ck mit dem aktuellen Objekt
	}

	// Move assigment operator
	MyString MyString::operator=(MyString&& string) 
	{
		if (this != &string)
		{
			CopyLength(string.length);

			if (data != nullptr)
				delete[] data;
			data = string.data;
			string.data = nullptr;
		}
		return *this;
	}

	MyString MyString::operator=(const char* string)
	{
		if (string) // wenn es keine Zuweisung an sich selbst ist
		{
			//delete data; // l�sche bisherige Daten
			int len = CalcLength(string); // Gr��e?
			CopyLength(len); // neue größe setzen
			CopyString(string); // Daten �bernehmen

		}

		return *this; // zur�ck mit dem aktuellen Objekt
	}

	MyString& MyString::operator+=(const MyString& string)
	{
		this->Concatenate(string.c_str());
		return *this;
	}

	MyString& MyString::operator+=(const char* string)
	{
		this->Concatenate(string);
		return *this;
	}

	void MyString::Concatenate(const char* another_string) 
	{
		if (another_string)
		{
			int tmp_length = CalcLength(another_string);
			int new_length = tmp_length + this->length;
			char* newString = new char [new_length + 1];
			for (int i = 0; this->data[i] != '\0'; i++)
			{
				newString[i] = this->data[i];
			}

			for (int j = this->length, i = 0; another_string[i] != '\0', i < tmp_length; i++, j++)
			{
				newString[j] = another_string[i];
			}

			newString[new_length] = '\0';

			//char* new_string = ZsmFuegen(this->data, another_string);
			CopyLength(new_length);
			CopyString(newString);
			delete[] newString;
			newString = nullptr;
		}
	}

	void MyString::Concatenate(const MyString& myString) 
	{
		Concatenate(myString.c_str());
	}


	/*MyString& operator+(std::string data, const MyString& str)
	{

	}*/


}
