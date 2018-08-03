#ifndef SYNTAX_H
#define SYNTAX_H

#include <vector>
#include <string>
#include "lexer.h"
namespace syntax{

class Syntax;

class Tree{
  Token node;
  Tree* leftLeaf;
  Tree* rightLeaf;
public:
  Tree();
  Tree(Token* begin);
  Tree* left();
  Tree* right();
  Token getNode();
  void setNode(Token n);
  Tree* addLeft(Tree* left);
  Tree* addLeft(Token node);
  Tree* addRight(Tree* right);
  Tree* addRight(Tree* left);
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
