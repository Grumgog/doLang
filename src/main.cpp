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
  virtual lex::TokenType isToken(std::string str){
    if(std::string(" ").compare(str)==0)
      return lex::TokenType::SPACE;
    else return lex::TokenType::WORD;
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

  cout << forest->getNode().getValue() << " " << forest->left()->getNode().getValue() << " "
       << forest->right()->getNode().getValue() << endl;
  
  return 0;
}
