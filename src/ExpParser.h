
    #include <iostream>
    #include <iterator>
    #include <vector>
    
    using namespace std;


// Generated from src/Exp.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  ExpParser : public antlr4::Parser {
public:
  enum {
    COMMENT = 1, SPACE = 2, PLUS = 3, MINUS = 4, TIMES = 5, OVER = 6, REM = 7, 
    OP_PAR = 8, CL_PAR = 9, OP_CUR = 10, CL_CUR = 11, ATTRIB = 12, COMMA = 13, 
    EQ = 14, NE = 15, GT = 16, GE = 17, LT = 18, LE = 19, NUMBER = 20, STRING = 21, 
    PRINT = 22, READ_INT = 23, READ_STR = 24, IF = 25, ELSE = 26, WHILE = 27, 
    NAME = 28
  };

  enum {
    RuleProgram = 0, RuleMain = 1, RuleStatement = 2, RuleSt_print = 3, 
    RuleSt_attrib = 4, RuleSt_if = 5, RuleSt_while = 6, RuleComparision = 7, 
    RuleExpression = 8, RuleTerm = 9, RuleFactor = 10
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
      int stackSize    = 0;
      int stackMax     = 0;

      int ifCounter    = 0;
      int elseCounter  = 0;
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


  class ProgramContext;
  class MainContext;
  class StatementContext;
  class St_printContext;
  class St_attribContext;
  class St_ifContext;
  class St_whileContext;
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
    ExpParser::ExpressionContext *expressionContext = nullptr;
    St_attribContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ATTRIB();
    ExpressionContext *expression();

   
  };

  St_attribContext* st_attrib();

  class  St_ifContext : public antlr4::ParserRuleContext {
  public:
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

  class  ComparisionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;
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
    antlr4::tree::TerminalNode *READ_STR();
    antlr4::tree::TerminalNode *READ_INT();

   
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

