#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

namespace lex{
  /**
  \brief Виртуальный класс для создания разделителей
  \author grumgog
  \date 27.06.2018
  \version 0.2

  Разделитель - специальный класс содержащий метод isDivide
  для разделения строки на лексемы.
  */
  class Divider{
  public:
      /// Метод для разделения строк на лексемы
      virtual bool isDivide(char letter)=0;
      virtual ~Divider(){};
  };

  enum TokenType{
    NONE = -1,
    WORD,
    IF,
    ELSE,
    WHILE
  };
  
  /**
   \brief Класс для представления токенов
   \author grumgog
   \date 27.06.2018
   \version 0.2
   Токен - пара значений <тип, значение>
  */
  class Token{
    TokenType type;
    std::string value;
    void init(TokenType t, std::string v);
  public:
    // constructors
    Token(TokenType t = TokenType::NONE, std::string v ="");
    Token(const Token& t);
    Token operator=(const Token& t);

    void setType(TokenType t);
    void setValue(std::string v);
    TokenType getType() const;
    std::string getValue() const;
    // destructor
    virtual ~Token();
  };
  
  class Tokenizer{
  public:
    virtual ~Tokenizer(){};
    virtual TokenType isToken(const std::string str) = 0;
  };
  
  /**
  \brief Класс лексического анализатора
   \author grumgog
   \date 27.06.2018
   \version 0.2
   
    Лексический анализатор - модуль занимающийся разбором строки на лексемы -
    самостоятельные "слова" языка. Для определения токенов, нужно добавить типы токенов - 
    объекты классов унаследованных от TokenType. Для правильного определения типа токена, рекомендуеться
    добавлять типы токенов от более конкретного к более общему случаю. Например 
    целые_числа <- вещественные_числа.
    Класс сам очищяет память под выделенные данные, в своем деструкторе, поэтому
    дополнительных действий по очистке памяти не нужно.
   */
  class Lexer{
    std::vector<Tokenizer*> tokenizers;
    Divider* divider;
    public:
      Lexer(Divider* divObj, std::vector<Tokenizer*> t = std::vector<Tokenizer*>());
      Lexer(Divider* divObj, Tokenizer* one);
      void addTokenizer(Tokenizer* t);
      void setDivider(Divider* d);
      std::vector<std::string> divideLex(std::string str);
      std::vector<Token> tokenize(std::vector<std::string> lexs);
      
      std::vector<Token> process(std::string input); // <- main processing function of Lexic analysis
      
      virtual ~Lexer();


  };
}
#endif
