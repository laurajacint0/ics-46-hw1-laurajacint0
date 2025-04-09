#include "String.h"
#include "Alloc.h"

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

ostream &operator<<(std::ostream &out, String s){
    s.print(out);
    return out;
}
istream &operator>>(std::istream &in, String &s){
    s.read(in);
    return in;
}