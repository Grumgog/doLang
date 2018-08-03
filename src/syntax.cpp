#include "syntax.h"

namespace syntax{
  Tree::init(){
    this->leftLeaf = nullptr;
    this->rightLeaf = nullptr;
  }
    
  Tree::Tree(){
    this->node = Token();
    init();
  }

  Tree::Tree(Token* begin){
    this->node = begin;
    init();
  }

  Tree* Tree::left(){
    return this->leftLeaf;
  }

  Tree* Tree::right(){
    return this->rightLeaf;
  }

  Token Tree::getNode(){
    return this->node;
  }

  void Tree::setNode(Token n){
    this->node = n;
  }

  Tree* Tree::addLeft(Tree* left){
    if(this->leftLeaf != nullptr)
      delete this->leftLeaf;
    this->leftLeaf = left;
    return this;
  }

  Tree* Tree::addLeft(Token* node){
    if(this->leftLeaf == nullptr)
      this->leftLeaf = new Tree(node);
    else
      this->leftLeaf->node = node;
  }

  Tree* Tree::addRight(Tree* right){
    if(this->rightLeaf != nullptr)
      delete this->rightLeaf;
    this->rightLeaf = right;
    return this->rightLeaf;
  }

  Tree* Tree::addRight(Token* node){
    if(this->rightLeaf == nullptr)
      this->rightLeaf = new Tree(node);
    else
      this->rightLeaf->node = node;
  }
}
