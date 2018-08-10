#include <iostream>
#include <vector>
#include "lexer.h"
#include "syntax.h"

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
  virtual std::string isToken(std::string str){
    if(std::string(" ").compare(str)==0)
      return "SPACE";
    else return "WORLD";
  } 
};

using namespace std;

int main()
{

  lex::Lexer analizator(new simpleDivider(), new WordTokenizer());
  vector<lex::Token> res = analizator.process("Hello world and over this!");
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
