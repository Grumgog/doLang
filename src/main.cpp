#include <iostream>
#include <vector>
#include "lexer.h"

class simpleDivider : public lex::Divider{
  public:
    simpleDivider(){}
    virtual bool isDivide(char letter){
      return letter == ' ';
    }
    
};

class WordTokenizer : public lex::Tokenizer{
public:
  WordTokenizer(){}
  virtual lex::TokenType isToken(std::string str){
    if(str == std::string(" "))
      return lex::TokenType::NONE;
    else return lex::TokenType::WORD;
  } 
};

using namespace std;

int main()
{

  lex::Lexer analizator(new simpleDivider(), new WordTokenizer());
  vector<lex::Token> res = analizator.process("Hello world!");
  for(lex::Token i : res){
    cout << i.getType() << " === " << "\"" << i.getValue() << "\"" << endl;
  }
  return 0;
}
