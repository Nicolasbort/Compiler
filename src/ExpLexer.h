
// Generated from src/Exp.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  ExpLexer : public antlr4::Lexer {
public:
  enum {
    COMMENT = 1, SPACE = 2, PLUS = 3, MINUS = 4, TIMES = 5, OVER = 6, REM = 7, 
    OP_PAR = 8, CL_PAR = 9, OP_CUR = 10, CL_CUR = 11, ATTRIB = 12, COMMA = 13, 
    EQ = 14, NE = 15, GT = 16, GE = 17, LT = 18, LE = 19, NUMBER = 20, STRING = 21, 
    PRINT = 22, READ_INT = 23, READ_STR = 24, IF = 25, ELSE = 26, WHILE = 27, 
    NAME = 28
  };

  explicit ExpLexer(antlr4::CharStream *input);
  ~ExpLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

