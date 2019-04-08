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
class BinaryTree{
  lex::Token node;
  BinaryTree* leftLeaf;
  BinaryTree* rightLeaf;
  void init();
  void del(BinaryTree *t);
  std::string inDeep(int level, BinaryTree* n);
public:
  BinaryTree();
  BinaryTree(lex::Token begin);
  BinaryTree* left();
  BinaryTree* right();
  lex::Token getNode();
  void setNode(lex::Token n);
  BinaryTree* addLeft(BinaryTree* left);
  BinaryTree* addLeft(lex::Token node);
  BinaryTree* addRight(BinaryTree* right);
  BinaryTree* addRight(lex::Token node);
  std::string toString();
  ~BinaryTree();
};

 class Tree{
   lex::Token node;
   std::vector<Tree*> leafs;
   void init();
   void del(Tree* t);
 public:
   Tree();
   Tree(lex::Token begin);

   Tree* getLeaf(unsigned int inode);
   void addLeaf(Tree* subTree);
   void addLeaf(lex::Token);
   unsigned int count();
   lex::Token getNode();
   void setNode(lex::Token n);

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
