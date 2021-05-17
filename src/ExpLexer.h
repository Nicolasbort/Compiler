
// Generated from src/Exp.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  ExpLexer : public antlr4::Lexer {
public:
  enum {
    MLCOMMENT = 1, COMMENT = 2, SPACE = 3, PLUS = 4, MINUS = 5, TIMES = 6, 
    OVER = 7, REM = 8, OP_BRA = 9, CL_BRA = 10, OP_PAR = 11, CL_PAR = 12, 
    OP_CUR = 13, CL_CUR = 14, ATTRIB = 15, COMMA = 16, DOT = 17, EQ = 18, 
    NE = 19, GT = 20, GE = 21, LT = 22, LE = 23, NUMBER = 24, STRING = 25, 
    PRINT = 26, READ_INT = 27, READ_STR = 28, IF = 29, ELSE = 30, WHILE = 31, 
    BREAK = 32, CONTINUE = 33, PUSH = 34, LENGTH = 35, DEF = 36, NAME = 37
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

