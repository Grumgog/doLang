#include <iostream>
#include <vector>
#include "lexer.h"
#include "syntax.h"

bool isDigit(char c){
  return (c >= 48) && (c <= 57);
}

bool isOperator(char c){
  return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

class simpleDivider : public lex::Divider{
  
  char prevChar; 
public:
  simpleDivider(){}
  virtual bool isDivide(char letter){
    bool res = (isDigit(prevChar) && isOperator(letter)) ||
      (isOperator(prevChar) && isDigit(letter)) || (letter == ' ')
      || (prevChar == ' ');
    prevChar = letter;
    return res;
  }  
};

class iniDivider : public lex::Divider{
  char prevChar;
public:
  iniDivider(){}
  virtual bool isDivide(char letter){
    switch(letter){
    case '+':
    case '-':
      return true;
    default:
      if(prevChar == '=')
	return true;
      else return false;
    }
  }
};
class WordTokenizer : public lex::Tokenizer{
public:
  WordTokenizer(){}
  virtual std::string isToken(std::string str){
    if(std::string(" ").compare(str) == 0)
      return "SPACE";
    else if(isDigit(str[0]))
      return "NUMBER";
    else if(isOperator(str[0]))
      return "OP";
  } 
};

using namespace std;

int main()
{

  lex::Lexer analizator(new simpleDivider(), new WordTokenizer());
  vector<lex::Token> res = analizator.process("28  + 4");
  res = lex::Token::delToken("SPACE", res);
  for(lex::Token i : res){
    cout << i.toString() << endl;
  }
  
  return 0;
}
