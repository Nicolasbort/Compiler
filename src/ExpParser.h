
    #include <iostream>
    // #include <vector>
    
    using namespace std;


// Generated from Exp.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  ExpParser : public antlr4::Parser {
public:
  enum {
    COMMENT = 1, SPACE = 2, PLUS = 3, MINUS = 4, TIMES = 5, OVER = 6, REM = 7, 
    OP_PAR = 8, CL_PAR = 9, NUMBER = 10
  };

  enum {
    RuleProgram = 0, RuleMain = 1, RuleExpression = 2, RuleTerm = 3, RuleFactor = 4
  };

  explicit ExpParser(antlr4::TokenStream *input);
  ~ExpParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


      // vector<string> symbol_table;


  class ProgramContext;
  class MainContext;
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
    ExpressionContext *expression();

   
  };

  MainContext* main();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
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
    antlr4::Token *numberToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *OP_PAR();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CL_PAR();

   
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

