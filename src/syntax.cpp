#include "syntax.h"

namespace syntax{
  void Tree::init(){
    this->leftLeaf = nullptr;
    this->rightLeaf = nullptr;
  }
    
  Tree::Tree(){
    this->node = lex::Token();
    init();
  }

  Tree::Tree(lex::Token begin){
    this->node = begin;
    init();
  }

  Tree* Tree::left(){
    return this->leftLeaf;
  }

  Tree* Tree::right(){
    return this->rightLeaf;
  }

  lex::Token Tree::getNode(){
    return this->node;
  }

  void Tree::setNode(lex::Token n){
    this->node = n;
  }

  Tree* Tree::addLeft(Tree* left){
    if(this->leftLeaf != nullptr)
      delete this->leftLeaf;
    this->leftLeaf = left;
    return this;
  }

  Tree* Tree::addLeft(lex::Token node){
    if(this->leftLeaf == nullptr)
      this->leftLeaf = new Tree(node);
    else
      this->leftLeaf->node = node;
    return this;
  }

  Tree* Tree::addRight(Tree* right){
    if(this->rightLeaf != nullptr)
      delete this->rightLeaf;
    this->rightLeaf = right;
    return this->rightLeaf;
  }

  Tree* Tree::addRight(lex::Token node){
    if(this->rightLeaf == nullptr)
      this->rightLeaf = new Tree(node);
    else
      this->rightLeaf->node = node;
    return this;
  }

  void Tree::del(Tree* t){
    // recursivly go down on tree
    if(t->leftLeaf != nullptr)
      del(t->leftLeaf);
    if(t->rightLeaf != nullptr)
      del(t->rightLeaf);
    delete this;
  }
    

  Tree::~Tree(){
    del(this);
  }
}
