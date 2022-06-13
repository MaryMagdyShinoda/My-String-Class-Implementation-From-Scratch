#include <iostream>
#include <cstring>
#include <ctype.h>
#include<iomanip>
#include<cstddef>
using namespace std;

class MyString
{
private:
    char* str;
public:
    // Default Constructor
    MyString() :str{ 0 }
    {
        str = new char[1];
        str[0] = '\0';
    }
    // Constructor with 1 arguments
    MyString(char* Entered_Value)
    {
        if (Entered_Value == 0)
        {
            str = new char[1];
            str[0] = '\0';
        }
        else
        {
            cout<<endl;
            int length = strlen(Entered_Value) + 1;
            str = new char[length];
            str = strcopy(str, Entered_Value);  // Copy character of Entered_Value[] using strcpy
            cout << "The string you entered is: " << str << endl;
            cout<<endl;
        }
    }
    // Copy Constructor
    MyString(const MyString& Source_String)
    {
        int length = strlen(Source_String.str) + 1;
        if (Source_String.str)
        {
            str = new char(length);
            str = strcopy(str, Source_String.str);
            str[length + 1] = '\0';
        }
        else
            str = 0;
    }
    //get str
    char* getter()
    {
        return str;
    }
    // remove last item
    void Remove()
    {
        this->getter();
        int length = this->getlength();
        char* buff = new char[length];
        // Copy character from str to buff[]
        for (int i = 0; i <length-1; i++)
            buff[i] = str[i];

        buff[length] = '\0';
        // Assign the new string with char a to str
        *this = MyString{ buff };
        // Deallocate memory from the temp buff []
        delete[] buff;
    }
    //add item
    void AddI(char item)
    {
        // Find length of string
        int length = strlen(str);
        char* buff;
        buff = new char[length + 2];
        // Copy character from STR
        // to buff[]
        for (int i = 0; i < length; i++) {
            buff[i] = str[i];
        }
        buff[length] = item;
        buff[length + 1] = '\0';
        // Assign the new string with
        // char a to string str
        *this = MyString{ buff };
        // Deallocate memory from the temp buff []
        delete[] buff;
    }
    //get length
    int getlength()
    {
        return strlen(str);
    }
    void cpy(char* source)
    {
        str = new char[strlen(source) + 1];
        int length = (strlen(source) + 1);
        for (int i = 0; i < length; i++)
        {
            str[i] = source[i];
        }
        str[length] = '\0';
    }
    //copy
    void copying()
    {
        int len, pos;
        cout << "Enter the length of the char you want to copy it:" << endl;
        cin >> len;
        cout << "Enter the position of the char you want to copy it:" << endl;
        cin >> pos;
        char* copied;
        copied = new char[len];
        for (int i = 0; i < len; i++)
        {
            copied[i] = str[pos + i];
        }
        copied[len] = '\0';
        cout << copied << endl;
        delete[]copied;
    }
    //swap
    void swapping(MyString& RHS)
    {
        MyString temp = RHS;
        RHS = *this;
        *this = temp;
        cout << " swapped " << endl;
        cout <<"first string: "<<*this<<endl;
        cout <<"second string: "<<RHS<<endl;
    }
    //comparison
    void Comparison(MyString& s1)
    {
        if (*this < s1)
            cout << "-1" << endl;
        if (*this == s1)
            cout << "0" << endl;
        if (*this > s1)
            cout << "1" << endl;
    }
    bool operator==(const MyString& m)
    {
        return strcmp(str, m.str) == 0;
    }
    bool operator<(const MyString& m)
    {
        return strcmp(str, m.str) < 0;
    }
    bool operator>(const MyString& m)
    {
        return strcmp(str, m.str) > 0;
    }
    //substring
    void Substring(const int StartIndex, const int EndIndex)
    {
        int x = (EndIndex-StartIndex)+1;
        char sub[x];
        for (int i=0; i<x; i++)
        {
            sub[i] = str[StartIndex+i];
        }
        cout << sub << endl;
    }
    //string without spaces
    MyString Trim()
    {
        this -> getter();
        int count=0,i=0;
        while (str[i] != ' ')
        {
            str[count] = str[i];
            i++;
            count++;
        }
        str[count] = '\0';
        return str;
    }
    //string LowerCase
    MyString LowerCase()
    {
        this->getter();
        int i = 0;
        while (str[i] != '\0')
        {
            str[i] = tolower((unsigned char)str[i]);
            i++;
        }
        return str;
    }
    //string UpperCase
    MyString UpperCase()
    {
        this->getter();
        int i = 0;
        while (str[i] != '\0')
        {
            str[i] = toupper((unsigned char)str[i]);
            i++;
        }
        return str;
    }
    // Index of item
    int IndexOf(char Wanted)
    {
        this->getter();
        for (int i=0; i<strlen(str); i++)
        {
            if (str[i] == Wanted){
                return i;
            }
        }
    }
    //Last Index of item
    int LastIndexOf(char Wanted)
    {
        this->getter();
        int length=strlen(str);
        for (int i=length+1; i>=0; --i)
        {
            if (str[i] == Wanted){
                return i+1;
            }
        }
    }
    //Replace
    MyString Replace(char oldChar, char newChar)
    {
        int length = strlen(str);
        for (int i = 0; i < length; ++i)
        {
            if (str[i] == oldChar) {
                str[i] = newChar;
            }
            continue;
        }
        return str;
    }
    char* strcopy(char* strcopied, const char* str)
    {
        for (int i = 0; str[i]; i++) {
             strcopied[i] = str[i];
        }
        return strcopied;
    }
    char*strconcat(char*Concatenated, const char* Basic)
    {
        int i, j;
        // move to the end of the Concatenated string
        for (i = 0; Concatenated[i] != '\0'; i++);
        // `i` now point to terminating null character in the Concatenated
        // Appends characters of the source to the Concatenated string
        for (j = 0; Basic[j] != '\0'; j++) {
            Concatenated[i + j] = Basic[j];
        }
        // null terminate Concatenated string
        Concatenated[i + j] = '\0';
        // the Concatenated is returned by standard `strcat()`
        return Concatenated;
    }
    friend MyString operator + (const MyString&lhs,const MyString&rhs);// Overloading the plus operator to concatenate
    friend ostream& operator<<(ostream& os, const MyString& obj); // Prototype for stream insertion
    friend istream& operator>>(istream& is, MyString& obj); // Prototype for stream extraction
    ~MyString() { delete str; }
};
// Overloading the plus operator to concatenate
MyString operator + (const MyString&lhs, const MyString&rhs)
{
    int length = strlen(lhs.str) + strlen(rhs.str);
    char* buff = new char[length+1];
    for(int i=0; i<strlen(lhs.str); i++)
    {
        buff[i]=lhs.str[i];
    }
    int c=0;
    for(int j=strlen(lhs.str); j<length; j++)
    {
        buff[j]=rhs.str[c];
        c++;
    }
    MyString temp(buff);
    return temp;
}
// Overloading the stream
// extraction operator
istream& operator>>(istream& is, MyString& obj)
{
    char* buff = new char[1000];
    is >> buff;
    obj = MyString{ buff };
    delete[] buff;
    return is;
}
// Overloading the stream
// insertion operator
ostream& operator<<(ostream& os, const MyString& obj)
{
    os << obj.str;
    return os;
}

int main()
{
    char* ptr = new char[25];
    cout << " Enter any string " << endl;
    cin.getline(ptr,25);
        MyString s1(ptr);
        int choose;
        cout << "choose" << endl;
        cout << "1-Removes the last element" << endl;
        cout << "2-Add element to the end" << endl;
        cout << "3-Returns the length" << endl;
        cout << "4-Copies the MyString object to a character array from a given position and a specific length" << endl;
        cout << "5-Swaps the two MyString objects" << endl;
        cout << "6-Concatenate two strings" << endl;
        cout << "7-Compare two strings" << endl;
        cout << "8-Returns a substring" << endl;
        cout << "9-Returns a copy of this string with leading and trailing white space removed" << endl;
        cout << "10-Returns a copy of this string converted to uppercase" << endl;
        cout << "11-Returns a copy of this string converted to lowercase" << endl;
        cout << "12-Returns index of the first occurrence of the specified character" << endl;
        cout << "13-Returns last index of the first occurrence of the specified character" << endl;
        cout << "14-Returns a new string resulting from replacing all occurrences of oldChar in this string with newChar" << endl;
        cout << endl;
        cin >> choose;

        if (choose == 1) {
            s1.Remove();
            cout << s1 << endl;
        }
        else if (choose == 2) {
            char item;
            cout << "enter item" << endl;
            cin >> item;
            s1.AddI(item);
            cout << s1 << endl;
        }
        else if (choose == 3) {
            cout << " the length of your string is : " << s1.getlength() << endl;
        }
        else if (choose == 4) {
            s1.copying();
        }
        else if (choose == 5) {
            char t[25];
            cout << " Enter your string " << endl;
            cin >> t;
            MyString s2(t);
            cout<<"first string : " <<s1 <<endl;
            cout<<"second string : " <<s2 <<endl;
            s1.swapping(s2);
        }
        else if (choose == 6) {
                char lhs[25];
                cout << " Enter your string " << endl;
                cin >> lhs;
                char rhs[25];
                cout << " Enter your string " << endl;
                cin >> rhs;
                MyString LHS(lhs);
                MyString RHS(rhs);
                cout << "the concatenated string is: " << LHS+RHS << endl;
        }
        else if (choose == 7) {
            char x[25];
            cout << " Enter your string " << endl;
            cin >> x;
            MyString s3(x);
            s1.Comparison(s3);
        }
        else if (choose == 8) {
            int SI, EI;
            cout << "Enter Start Index" << endl;
            cin >> SI;
            cout << "Enter End Index" << endl;
            cin >> EI;
            s1.Substring(SI, EI);
        }
        else if (choose == 9) {
            cout << "Your string without spaces : " <<s1.Trim()<< endl;
        }
        else if (choose == 10) {
            char x[25];
            cout << " Enter your string " << endl;
            cin >> x;
            s1.UpperCase();
        }
        else if (choose == 11) {
            char x[25];
            cout << " Enter your string " << endl;
            cin >> x;
            s1.LowerCase();
        }
        else if (choose == 12) {
            char item;
            cout << "enter item" << endl;
            cin >> item;
            cout <<"Index of item you entered is : " << s1.IndexOf(item) << endl;
        }
        else if (choose == 13) {
            char item;
            cout << "enter item" << endl;
            cin >> item;
            cout <<"Last Index of item you entered is : " << s1.LastIndexOf(item) << endl;
        }
        else if (choose == 14) {
            char Old;
            cout << "enter old char" << endl;
            cin >> Old;
            char New;
            cout << "enter new char" << endl;
            cin >> New;
            cout << s1.Replace(Old, New) << endl;
        }
    return 0;
}
