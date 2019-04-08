#include "syntax.h"

namespace syntax{
  void BinaryTree::init(){
    this->leftLeaf = nullptr;
    this->rightLeaf = nullptr;
  }
    
  BinaryTree::BinaryTree(){
    this->node = lex::Token();
    init();
  }

  BinaryTree::BinaryTree(lex::Token begin){
    this->node = begin;
    init();
  }

  BinaryTree* BinaryTree::left(){
    return this->leftLeaf;
  }

  BinaryTree* BinaryTree::right(){
    return this->rightLeaf;
  }

  lex::Token BinaryTree::getNode(){
    return this->node;
  }

  void BinaryTree::setNode(lex::Token n){
    this->node = n;
  }

  BinaryTree* BinaryTree::addLeft(BinaryTree* left){
    if(this->leftLeaf != nullptr)
      delete this->leftLeaf;
    this->leftLeaf = left;
    return this;
  }

  BinaryTree* BinaryTree::addLeft(lex::Token node){
    if(this->leftLeaf == nullptr)
      this->leftLeaf = new BinaryTree(node);
    else
      this->leftLeaf->node = node;
    return this;
  }

  BinaryTree* BinaryTree::addRight(BinaryTree* right){
    if(this->rightLeaf != nullptr)
      delete this->rightLeaf;
    this->rightLeaf = right;
    return this->rightLeaf;
  }

  BinaryTree* BinaryTree::addRight(lex::Token node){
    if(this->rightLeaf == nullptr)
      this->rightLeaf = new BinaryTree(node);
    else
      this->rightLeaf->node = node;
    return this;
  }

  void BinaryTree::del(BinaryTree* t){
    // recursivly go down on tree
    if(t->leftLeaf != nullptr)
      del(t->leftLeaf);
    if(t->rightLeaf != nullptr)
      del(t->rightLeaf);
    delete t;
  }

  std::string BinaryTree::toString(){
    return inDeep(0, this);
  }

  std::string BinaryTree::inDeep(int level, BinaryTree* n){
    std::stringstream ss;
    if(n != nullptr){
      ss << inDeep(level+1, n->left());
      for(int i = 0; i<level; i++)
	ss << " ";
      ss << "|-" << n->node.toString() << std::endl;
      ss << inDeep(level+1, n->right());
    }
    return ss.str();
	
  }
    
  BinaryTree::~BinaryTree(){
    del(this);
  }

  Tree::Tree(){}

  Tree::Tree(lex::Token begin){
    this->node = begin;
  }

  Tree* Tree::getLeaf(unsigned int inode){
    return this->leafs.at(inode);
  }

  void Tree::addLeaf(Tree* subTree){
    this->leafs.push_back(subTree);
  }

  void Tree::addLeaf(lex::Token t){
    this->leafs.push_back(new Tree(t));
  }

  unsigned int Tree::count(){
    return this->leafs.size();
  }

  lex::Token Tree::getNode(){
    return this->node;
  }

  void Tree::setNode(lex::Token n){
    this->node = n;
  }

  Tree::~Tree(){
    del(this);
  }

  void Tree::del(Tree* t){
    for(Tree* st : this->leafs)
      del(st);
    delete t;
  }
}
