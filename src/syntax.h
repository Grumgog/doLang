#ifndef SYNTAX_H
#define SYNTAX_H

#include <vector>
#include <string>
#include "lexer.h"
namespace syntax{

class Syntax;

class Tree{
  lex::Token node;
  Tree* leftLeaf;
  Tree* rightLeaf;
  void init();
  void del(Tree *t);
public:
  Tree();
  Tree(lex::Token begin);
  Tree* left();
  Tree* right();
  lex::Token getNode();
  void setNode(lex::Token n);
  Tree* addLeft(Tree* left);
  Tree* addLeft(lex::Token node);
  Tree* addRight(Tree* right);
  Tree* addRight(lex::Token node);
  ~Tree();
};
 
class Rule{
  Syntax* parent;
 public:
  
};
  
class Syntax{
  std::vector<std::string> TokenStream;
  std::vector<Rule> rules;
  
};
}
#endif
