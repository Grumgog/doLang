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
  vector<lex::Token> res = analizator.process("33+52 - 43 * 25 / 5");
  res = lex::Token::delToken("SPACE", res);
  for(lex::Token i : res){
    cout << i.getType() << " === " << "\"" << i.getValue() << "\"" << endl;
  }

  syntax::Tree* forest = new syntax::Tree();
  forest->setNode(res[0]);
  forest->addLeft(new syntax::Tree(res[1]));
  forest->addRight(new syntax::Tree(res[2]));

  cout << forest->toString() << endl;
  
  return 0;
}
