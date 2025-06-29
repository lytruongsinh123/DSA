#include <iostream>
#include <string>
using namespace std;
class MyString
{
  private:
    char *data;
    size_t length;

  public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    MyString &operator=(const char *other);
    MyString operator+(const MyString &other);
    MyString operator+(const char *other);
    char &operator[](size_t index);
    const char operator[](size_t index) const;
    ~MyString();
    size_t size() const;
    const char *c_str() const;
};
MyString::MyString() 
{
  this->data = nullptr;
  this->length = 0;
}
MyString::~MyString() {
  delete[] this->data;
}
MyString::MyString(const char *str)
{
  this->data = new char[strlen(str) + 1];
  this->length = strlen(str);
  for(size_t i = 0; i < strlen(str); i++)
  {
    this->data[i] = str[i];
  }
  this->data[strlen(str)] = '\0';
}
MyString::MyString(const MyString &other)
{
  this->data = new char[other.length + 1];
  this->length = other.length;
  for(size_t i = 0; i < other.length; i++)
  {
    this->data[i] = other.data[i];
  }
  this->data[other.length] = '\0';
}
MyString& MyString::operator=(const MyString &other)
{
  if(this->data != nullptr) delete[] this->data;
  this->length = other.length;
  this->data = new char[other.length + 1];
  for(size_t i = 0; i < other.length; i++)
  {
    this->data[i] = other.data[i];
  }
  this->data[other.length] = '\0';
  return *this;
}
MyString &MyString::operator=(const char *other)
{
  if(this->data != nullptr) delete[] this->data;
  this->length = strlen(other);
  this->data = new char[strlen(other) + 1];
  for(unsigned int i = 0; i < strlen(other); i++)
  {
    this->data[i] = other[i];
  }
  this->data[strlen(other)] = '\0';
  return *this;
}
MyString MyString::operator+(const MyString &other)
{
  MyString result;
  char * newstr = new char[this->length + other.length + 1];
  for(size_t i = 0; i < this->length;i++)
  {
    newstr[i] = this->data[i];
  }
  for(size_t i = 0; i < other.length; i++)
  {
    newstr[i + this->length] = other[i];
  }
  newstr[this->length + other.length] = '\0';
  result.data = newstr;
  result.length = this->length + other.length;
  return result;
}
MyString MyString::operator+(const char *other)
{
  MyString result;
  result.data = new char[strlen(other) + this->length + 1];
  result.length = strlen(other) + this->length;
  for(size_t i = 0; i < this->length; i++)
  {
    result.data[i] = this->data[i];
  }
  for(unsigned int i = 0; i < strlen(other); i++)
  {
    result.data[i + this->length] = other[i];
  }
  result.data[strlen(other) + this->length] = '\0';
  return result;
}
char &MyString::operator[](size_t index) 
{
  return this->data[index];
}
const char MyString::operator[](size_t index) const
{
  return this->data[index];
}
size_t MyString::size() const
{
  return this->length;
}
const char *MyString::c_str() const
{
  return this->data;
}