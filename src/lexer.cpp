#include "lexer.h"

namespace lex{
  Lexer::Lexer(Divider* divObj, std::vector<Tokenizer*> t){
    this->divider = divObj;
    this->tokenizers = t;
  }
  
  Lexer::Lexer(Divider* divObj, Tokenizer* t){
    this->divider = divObj;
    this->tokenizers.push_back(t);
  }

  void Lexer::addTokenizer(Tokenizer* t){
    if(t != nullptr) this->tokenizers.push_back(t);
  }

  void Lexer::setDivider(Divider* d){
    if(this->divider == d) return; // if new divider is old
    if(this->divider != nullptr) delete this->divider; // save from memory leak
    this->divider = d;
  }

  Lexer::~Lexer(){
    if(this->divider != nullptr){
      delete this->divider;
      this->divider = nullptr;
    }
    
    for(Tokenizer* i : this->tokenizers){
      delete i;
      i = nullptr;
    }
  }
  
  std::vector<std::string> Lexer::divideLex(std::string str){
    bool res = false;
    std::string subLex;
    std::vector<std::string> result;
    unsigned int begin = 0;
    for(int i = 0; i < str.length(); i++)
    {
      if(this->divider->isDivide(str.at(i))){
        subLex = str.substr(begin, i-begin);
        begin = i;
	if(!subLex.empty()) result.push_back(subLex);
      }
    }
    std::string buf = str.substr(begin, str.length());
    if(!buf.empty()) result.push_back(buf);
    return result;
  }
  
  std::vector<Token> Lexer::tokenize(std::vector<std::string> lexs){
    std::vector<Token> result;
    std::string type = EmptyToken;
    for(std::string lex : lexs){
      bool errors = true;
      for(Tokenizer* t : this->tokenizers){
        type = t->isToken(lex);
        if(type.compare(EmptyToken) != 0){
          result.push_back(Token(type,lex));
	  errors = false;
          break;
        }
        if(errors) result.push_back(Token(EmptyToken, "ERROR"));
      }
    }
    return result;
  }
  
  std::vector<Token> Lexer::process(std::string input){
    std::vector<std::string> lexs = this->divideLex(input);
    return this->tokenize(lexs);
  }
  //class Token
  std::vector<Token> Token::delToken(std::string t, std::vector<Token> vt){
    for(std::vector<Token>::iterator i = vt.begin(); i!=vt.end(); i++){
      if(i->getType().compare(t) == 0)
	vt.erase(i);
    }
    return vt;
      
  }
  
  // init funtion
  void Token::init(std::string t, std::string v){
    this->type = t;
    this->value = v;
  }

  Token::Token(std::string t, std::string v){
    init(t, v);
  }

  Token::Token(const Token& t){
    init(t.type, t.value);
  }

  Token Token::operator=(const Token& t){
    if(this == &t) return *this;
    init(t.type, t.value);
    return *this;
  }

  std::string Token::getType()const{
    return this->type;
  }

  std::string Token::getValue()const{
    return this->value;
  }

  void Token::setType(std::string t){
    this->type = t;
  }

  void Token::setValue(std::string v){
    this->value = v;
  }

  std::string Token::toString(){
    std::stringstream ss;
    ss << "(" << this->type << ", " << this->value << ")";
    return ss.str();
  }
  
  Token::~Token(){}
}
