#ifndef SYNTAX_H
#define SYNTAX_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "lexer.h"
namespace syntax{

class Syntax;
/**
\brief Класс для представления бинарного дерева
\author Grumgog
\version 0.2

Класс предоставляет бинарное дерево с токеном в узле
 */
class Tree{
  lex::Token node;
  Tree* leftLeaf;
  Tree* rightLeaf;
  void init();
  void del(Tree *t);
  std::string inDeep(int level, Tree* n);
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
  std::string toString();
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
