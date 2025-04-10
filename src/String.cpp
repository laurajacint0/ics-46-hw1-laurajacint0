#include "String.h"
#include "Alloc.h"
using namespace std;

String::String(const char *s){
    buf = strdup(s);
}

//constructs this string as a copy of string s
String::String(const String & s){
        buf = strdup(s.buf);
    }

//construct this string by moving from string s
String::String(String && s){
    buf = s.buf;
    s.buf = nullptr;
}

 //assignment to this string by moving from string s
    String &String::operator = (String &&s){
        if (this != &s) {
            Alloc::delete_char_array(buf);
            buf = s.buf;
            s.buf = nullptr;
        }
        return *this;
    }

    //assignment operator from one string, s, to this string
    String &String::operator = (const String & s){
        if (this != &s) {
            Alloc::delete_char_array(buf);
            buf = strdup(s.buf);
        }
        return *this;
    }

    //allow indexing this string with notation s[i]
    char &String::operator[] (int index){
        if (!in_bounds(index)) {
            cerr << "ERROR: Index Out Of Bounds" << endl;
            return buf[0];
        }
        return buf[index];
    }

    //returns the logical length of this string(# of chars up to '\0')
    size_t String::size(){
        return strlen(buf);
    }

    //returns a reversal of this string, does not modify this string
    String String::reverse(){
        size_t len = size();
        char *reversed = Alloc::new_char_array(len + 1);
        reverse_cpy(reversed, buf);
        return String(reversed);
    }

    //returns index into this string for the fist occurance of c
    int String::indexOf(const char c){
        for (int i = 0; i < len; i++) {
        if (data[i] == c) {
            return i;
            }
        }
    return -1;
    }

    //returns index into this string for first occurance of s
    int String::indexOf(const String s){
        if (char *pos = strstr(buf, s.buf))
            return pos - buf;
        return -1;
    }

    //relational operators for comparing this strings to another string
    bool String::operator == (const String &s){
        return strcmp(buf, s.buf) == 0;
    }

    bool String::operator != (const String &s){
        return strcmp(buf, s.buf) != 0;
    }
    bool String::operator > (const String &s){
        return strcmp(buf, s.buf) > 0;
    }
    bool String::operator < (const String &s){
        return strcmp(buf, s.buf) < 0;
    }
    bool String::operator <= (const String &s){
        return strcmp(buf, s.buf) <= 0;
    }
    bool String::operator >= (const String &s){
        return strcmp(buf, s.buf) >= 0;
    }

    //concatenate this and s to form a return string
    String String::operator+(const String &s){
        size_t len = size() + s.size();
        char *concatenated = Alloc::new_char_array(len + 1);
        strcpy(concatenated, buf);
        strcat(concatenated, s.buf);
        return String(concatenated);
    }

    //concatenate s onto the end of this string
    String &String::operator+= (const String s){
        *this = *this + s;
        return *this;
    };

    //print this string, hint: use operator << to send buf to out
    void String::print(ostream &out){
        out << buf;
    }

    //read next word into this string
    //hint: use operator >> to read from in into buf
    void String::read(istream &in){
        char temp[1024];
        in >> temp;
        *this = String(temp);
    }

    //destructor for a this string
    String::~String(){
        Alloc::delete_char_array(buf);
    }

//private: //leave public for autograder testing
bool String::in_bounds(int i) {
        return i >= 0 && i < this->size();
    }

size_t String::strlen(const char *s){
    size_t len = 0;
    while(s[len] != '\0'){
        len++;
    }
    return len;
}

char *String::strdup(const char *s){
    size_t len = strlen(s) + 1;
    char *dest = Alloc::new_char_array(len);
    strcpy(dest,s);
    return dest;
}

char *String::strcpy(char *dest, const char *src){
    char *d = dest; 
    while(*src){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return d;
}

char *String::strncpy(char *dest, const char *src, int n){
    char *d = dest;
    int i = 0;
    while((i < n) && *src){
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    while(i < n){
    *dest = '\0';
    dest++;
    i++;
    }
    return d;
}

char *String::strcat(char *dest, const char *src){
    char *d = dest;
    while (*d != '\0'){
        d++;
    }
    while ( *src != '\0'){
        *d = *src;
        d++;
        src++;
    }
    *d = '\0';
    return dest;

}
char *String::strncat(char *dest, const char *src, int n){
    char *d = dest;

    while(*d != '\0'){
        d++;
    }

    int i = 0;
    while((i<n) && *src != '\0'){
        *d = *src;
        d++;
        src++;
        i++;
    }

    *d = '\0';
    return dest;
}
int String::strcmp(const char *left, const char *right){
    while(*left != '\0' && *right != '\0'){
        if(*left != *right){
            return *left - *right;
        }
        left++;
        right++;
    }
    return *left - *right;
}

int String::strncmp(const char *left, const char *right, int n){
    for(int i = 0; i < n; i++){
        if(*left != *right){
            return *left - *right;
        }
        if (*left == '\0' || *right == '\0') {
        return *left - *right;
        }
        left++;
        right++;
    }
    return 0;
}

void String::reverse_cpy(char *dest, const char *src){
    const char *s = src;
    while (*s != '\0') {
        ++s;
    }
    while (s != src) {
        --s;
        *dest = *s;
        ++dest;         
    }
    *dest = '\0';
}

char *String::strchr(char *str, char c){
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        ++str;
    }
    return nullptr;
}
char *String::strstr(char *haystack, const char *needle){
    if (*needle == '\0') {
        return haystack;
    }

    while (*haystack != '\0') {
        char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            ++h;
            ++n;
        }

        if (*n == '\0') {
            return haystack;
        }

        ++haystack;
    }
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle){
    if (*needle == '\0') {
        return haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            ++h;
            ++n;
        }

        if (*n == '\0') {
            return haystack;
        }

        ++haystack;
    }
    return nullptr;
}

ostream &operator<<(ostream &out, String s){
    s.print(out);
    return out;
}
istream &operator>>(istream &in, String &s){
    s.read(in);
    return in;
}