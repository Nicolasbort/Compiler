
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <stdlib.h>
    
    #define RED 31
    #define YELLOW 33
    
    using namespace std;


// Generated from src/Exp.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  ExpParser : public antlr4::Parser {
public:
  enum {
    MLCOMMENT = 1, COMMENT = 2, SPACE = 3, PLUS = 4, MINUS = 5, TIMES = 6, 
    OVER = 7, REM = 8, OP_BRA = 9, CL_BRA = 10, OP_PAR = 11, CL_PAR = 12, 
    OP_CUR = 13, CL_CUR = 14, ATTRIB = 15, COMMA = 16, DOT = 17, EQ = 18, 
    NE = 19, GT = 20, GE = 21, LT = 22, LE = 23, NUMBER = 24, STRING = 25, 
    PRINT = 26, READ_INT = 27, READ_STR = 28, IF = 29, ELSE = 30, WHILE = 31, 
    BREAK = 32, CONTINUE = 33, PUSH = 34, LENGTH = 35, DEF = 36, NAME = 37
  };

  enum {
    RuleProgram = 0, RuleMain = 1, RuleStatement = 2, RuleSt_print = 3, 
    RuleSt_attrib = 4, RuleSt_if = 5, RuleSt_while = 6, RuleSt_break = 7, 
    RuleSt_continue = 8, RuleStr_array_create = 9, RuleSt_array_push = 10, 
    RuleSt_array_set = 11, RuleComparision = 12, RuleExpression = 13, RuleTerm = 14, 
    RuleFactor = 15
  };

  explicit ExpParser(antlr4::TokenStream *input);
  ~ExpParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


      vector<string> symbol_table = {"args"};
      vector<char>   type_table = {'s'};
      vector<bool>   used_vars = {true};
      vector<int>    list_while;

      int stackSize    = 0;
      int stackMax     = 0;

      int ifCounter    = 0;
      int whileCounter = 0;

      void calculateStack(string command, short value)
      {
          stackSize += value;

          if (stackSize > stackMax)
              stackMax = stackSize;
          
          cout << "   " << command << "\n";
      }

      void printFormat(string command)
      {
          cout << "   " << command;
      }


      void checkUnusedVars()
      {
          for (int i=0; i<used_vars.size(); i++)
          {
              if (!used_vars[i]) 
                  cerr << "Warning: Variable '" << symbol_table[i] << "' is not beeing used\n";
          }
      }

      bool strIsNumber(const string& s)
      {
          string::const_iterator it = s.begin();
          while (it != s.end() && isdigit(*it)) ++it;
          return !s.empty() && it == s.end();
      }



  class ProgramContext;
  class MainContext;
  class StatementContext;
  class St_printContext;
  class St_attribContext;
  class St_ifContext;
  class St_whileContext;
  class St_breakContext;
  class St_continueContext;
  class Str_array_createContext;
  class St_array_pushContext;
  class St_array_setContext;
  class ComparisionContext;
  class ExpressionContext;
  class TermContext;
  class FactorContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainContext *main();

   
  };

  ProgramContext* program();

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

   
  };

  MainContext* main();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    St_printContext *st_print();
    St_attribContext *st_attrib();
    St_ifContext *st_if();
    St_whileContext *st_while();
    St_breakContext *st_break();
    St_continueContext *st_continue();
    Str_array_createContext *str_array_create();
    St_array_pushContext *st_array_push();
    St_array_setContext *st_array_set();

   
  };

  StatementContext* statement();

  class  St_printContext : public antlr4::ParserRuleContext {
  public:
    ExpParser::ExpressionContext *expressionContext = nullptr;
    St_printContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    antlr4::tree::TerminalNode *OP_PAR();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *CL_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  St_printContext* st_print();

  class  St_attribContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nameToken = nullptr;
    ExpParser::ExpressionContext *ex = nullptr;
    St_attribContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ATTRIB();
    ExpressionContext *expression();

   
  };

  St_attribContext* st_attrib();

  class  St_ifContext : public antlr4::ParserRuleContext {
  public:
    ExpParser::ComparisionContext *comparisionContext = nullptr;
    St_ifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ComparisionContext *comparision();
    std::vector<antlr4::tree::TerminalNode *> OP_CUR();
    antlr4::tree::TerminalNode* OP_CUR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CL_CUR();
    antlr4::tree::TerminalNode* CL_CUR(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();

   
  };

  St_ifContext* st_if();

  class  St_whileContext : public antlr4::ParserRuleContext {
  public:
    ExpParser::ComparisionContext *comparisionContext = nullptr;
    St_whileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ComparisionContext *comparision();
    antlr4::tree::TerminalNode *OP_CUR();
    antlr4::tree::TerminalNode *CL_CUR();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

   
  };

  St_whileContext* st_while();

  class  St_breakContext : public antlr4::ParserRuleContext {
  public:
    St_breakContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();

   
  };

  St_breakContext* st_break();

  class  St_continueContext : public antlr4::ParserRuleContext {
  public:
    St_continueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();

   
  };

  St_continueContext* st_continue();

  class  Str_array_createContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nameToken = nullptr;
    Str_array_createContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ATTRIB();
    antlr4::tree::TerminalNode *OP_BRA();
    antlr4::tree::TerminalNode *CL_BRA();

   
  };

  Str_array_createContext* str_array_create();

  class  St_array_pushContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nameToken = nullptr;
    ExpParser::ExpressionContext *expressionContext = nullptr;
    St_array_pushContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *PUSH();
    antlr4::tree::TerminalNode *OP_PAR();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CL_PAR();

   
  };

  St_array_pushContext* st_array_push();

  class  St_array_setContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nameToken = nullptr;
    ExpParser::ExpressionContext *ex1 = nullptr;
    ExpParser::ExpressionContext *ex2 = nullptr;
    St_array_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *OP_BRA();
    antlr4::tree::TerminalNode *CL_BRA();
    antlr4::tree::TerminalNode *ATTRIB();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

   
  };

  St_array_setContext* st_array_set();

  class  ComparisionContext : public antlr4::ParserRuleContext {
  public:
    bool isValid;
    ExpParser::ExpressionContext *ex1 = nullptr;
    antlr4::Token *op = nullptr;
    ExpParser::ExpressionContext *ex2 = nullptr;
    ComparisionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();

   
  };

  ComparisionContext* comparision();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    char type;
    ExpParser::TermContext *t1 = nullptr;
    antlr4::Token *op = nullptr;
    ExpParser::TermContext *t2 = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

   
  };

  ExpressionContext* expression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    char type;
    ExpParser::FactorContext *f1 = nullptr;
    antlr4::Token *op = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TIMES();
    antlr4::tree::TerminalNode* TIMES(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OVER();
    antlr4::tree::TerminalNode* OVER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> REM();
    antlr4::tree::TerminalNode* REM(size_t i);

   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    char type;
    antlr4::Token *numberToken = nullptr;
    antlr4::Token *stringToken = nullptr;
    ExpParser::ExpressionContext *expressionContext = nullptr;
    antlr4::Token *nameToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *OP_PAR();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CL_PAR();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *OP_BRA();
    antlr4::tree::TerminalNode *CL_BRA();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LENGTH();
    antlr4::tree::TerminalNode *READ_INT();
    antlr4::tree::TerminalNode *READ_STR();

   
  };

  FactorContext* factor();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

