#include <iostream>

class stringcl {
  char* str;
  int len;
public:
  stringcl(char c, int n);
  stringcl(const char *s);
  stringcl(const stringcl &s);
  ~stringcl();

  void add_string(const stringcl &s);
  void copy_string(const stringcl &s);
  int strlen();
};

stringcl::stringcl(char c, int n){
  str = new char[n+1];
  len = n;

  for(int i = 0; i<n; i++) {
    str[i] = c;
  }
  str[len] = '\0';
}


stringcl::stringcl(const char *s){
  len = 0;
  while(s[len] != '\0') {
    len ++;
  }
  str = new char[len+1];
  for(int i = 0; i<len; i++){
    str[i] = s[i];
  }
  str[len] = '\0';
}

stringcl::stringcl(const stringcl &s){
  len = s.len;
  str = new char[len+1];
  for(int i = 0; i<len; i++){
    str[i] = s.str[i];
  }
  str[len] = '\0';
}

stringcl::~stringcl(){
  delete[] str;
}

void stringcl::add_string(const stringcl &s){
  int tmplen = len;
  len += s.len;

  char* tmpstr = new char[len + 1];

  for(int i = 0; i<tmplen; i++){
    tmpstr[i] = str[i];
  }

  for(int i = 0; i<s.len; i++){
    tmpstr[i+tmplen] = s.str[i];
  }

  tmpstr[len] = '\0';
  delete[] str;
  str = tmpstr;
}

void stringcl::copy_string(const stringcl &s){
  len = s.len;
  str = new char[len +1];
  for(int i = 0; i<len; i++){
    str[i] = s.str[i];
  }
  str[len] = '\0';
}


int stringcl::strlen(){
  return len;
}