
    #include <iostream>
    // #include <vector>
    
    using namespace std;


// Generated from Exp.g4 by ANTLR 4.9.1



#include "ExpParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExpParser::ExpParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExpParser::~ExpParser() {
  delete _interpreter;
}

std::string ExpParser::getGrammarFileName() const {
  return "Exp.g4";
}

const std::vector<std::string>& ExpParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExpParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

ExpParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExpParser::MainContext* ExpParser::ProgramContext::main() {
  return getRuleContext<ExpParser::MainContext>(0);
}


size_t ExpParser::ProgramContext::getRuleIndex() const {
  return ExpParser::RuleProgram;
}


ExpParser::ProgramContext* ExpParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ExpParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            cout << ".source Test.src\n";
            cout << ".class  public Test\n";
            cout << ".super  java/lang/Object\n\n";
            cout << ".method public <init>()V\n";
            cout << "    aload_0\n";
            cout << "    invokenonvirtual java/lang/Object/<init>()V\n";
            cout << "    return\n";
            cout << ".end method\n\n";
        
    setState(11);
    main();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

ExpParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExpParser::ExpressionContext* ExpParser::MainContext::expression() {
  return getRuleContext<ExpParser::ExpressionContext>(0);
}


size_t ExpParser::MainContext::getRuleIndex() const {
  return ExpParser::RuleMain;
}


ExpParser::MainContext* ExpParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, ExpParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            cout << ".method public static main([Ljava/lang/String;)V\n\n";
            cout << "    getstatic java/lang/System/out Ljava/io/PrintStream;\n";
        
    setState(14);
    expression();

            cout << "    invokevirtual java/io/PrintStream/println(I)V\n\n";
            cout << "    return\n";
            cout << ".limit stack 10\n";
            cout << ".end method\n";
            // cout << "\n; symbol_table: ";
            // for (vector<string>::const_iterator i = symbol_table.begin(); i != symbol_table.end(); i++) {
            //     cout << *i << ' ';
            // }
            // cout << "\n";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ExpParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExpParser::TermContext *> ExpParser::ExpressionContext::term() {
  return getRuleContexts<ExpParser::TermContext>();
}

ExpParser::TermContext* ExpParser::ExpressionContext::term(size_t i) {
  return getRuleContext<ExpParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> ExpParser::ExpressionContext::PLUS() {
  return getTokens(ExpParser::PLUS);
}

tree::TerminalNode* ExpParser::ExpressionContext::PLUS(size_t i) {
  return getToken(ExpParser::PLUS, i);
}

std::vector<tree::TerminalNode *> ExpParser::ExpressionContext::MINUS() {
  return getTokens(ExpParser::MINUS);
}

tree::TerminalNode* ExpParser::ExpressionContext::MINUS(size_t i) {
  return getToken(ExpParser::MINUS, i);
}


size_t ExpParser::ExpressionContext::getRuleIndex() const {
  return ExpParser::RuleExpression;
}


ExpParser::ExpressionContext* ExpParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 4, ExpParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    term();
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExpParser::PLUS

    || _la == ExpParser::MINUS) {
      setState(18);
      dynamic_cast<ExpressionContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == ExpParser::PLUS

      || _la == ExpParser::MINUS)) {
        dynamic_cast<ExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(19);
      term();

              if ((dynamic_cast<ExpressionContext *>(_localctx)->op != nullptr ? dynamic_cast<ExpressionContext *>(_localctx)->op->getType() : 0) == PLUS) cout << "    iadd\n";
              if ((dynamic_cast<ExpressionContext *>(_localctx)->op != nullptr ? dynamic_cast<ExpressionContext *>(_localctx)->op->getType() : 0) == MINUS) cout << "    isub\n";
          
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ExpParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExpParser::FactorContext *> ExpParser::TermContext::factor() {
  return getRuleContexts<ExpParser::FactorContext>();
}

ExpParser::FactorContext* ExpParser::TermContext::factor(size_t i) {
  return getRuleContext<ExpParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> ExpParser::TermContext::TIMES() {
  return getTokens(ExpParser::TIMES);
}

tree::TerminalNode* ExpParser::TermContext::TIMES(size_t i) {
  return getToken(ExpParser::TIMES, i);
}

std::vector<tree::TerminalNode *> ExpParser::TermContext::OVER() {
  return getTokens(ExpParser::OVER);
}

tree::TerminalNode* ExpParser::TermContext::OVER(size_t i) {
  return getToken(ExpParser::OVER, i);
}

std::vector<tree::TerminalNode *> ExpParser::TermContext::REM() {
  return getTokens(ExpParser::REM);
}

tree::TerminalNode* ExpParser::TermContext::REM(size_t i) {
  return getToken(ExpParser::REM, i);
}


size_t ExpParser::TermContext::getRuleIndex() const {
  return ExpParser::RuleTerm;
}


ExpParser::TermContext* ExpParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 6, ExpParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    factor();
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExpParser::TIMES)
      | (1ULL << ExpParser::OVER)
      | (1ULL << ExpParser::REM))) != 0)) {
      setState(28);
      dynamic_cast<TermContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExpParser::TIMES)
        | (1ULL << ExpParser::OVER)
        | (1ULL << ExpParser::REM))) != 0))) {
        dynamic_cast<TermContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(29);
      factor();

              if ((dynamic_cast<TermContext *>(_localctx)->op != nullptr ? dynamic_cast<TermContext *>(_localctx)->op->getType() : 0) == TIMES) cout << "    imul\n";
              if ((dynamic_cast<TermContext *>(_localctx)->op != nullptr ? dynamic_cast<TermContext *>(_localctx)->op->getType() : 0) == OVER) cout << "    idiv\n";
              if ((dynamic_cast<TermContext *>(_localctx)->op != nullptr ? dynamic_cast<TermContext *>(_localctx)->op->getType() : 0) == REM) cout << "    irem\n";
          
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

ExpParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::FactorContext::NUMBER() {
  return getToken(ExpParser::NUMBER, 0);
}

tree::TerminalNode* ExpParser::FactorContext::OP_PAR() {
  return getToken(ExpParser::OP_PAR, 0);
}

ExpParser::ExpressionContext* ExpParser::FactorContext::expression() {
  return getRuleContext<ExpParser::ExpressionContext>(0);
}

tree::TerminalNode* ExpParser::FactorContext::CL_PAR() {
  return getToken(ExpParser::CL_PAR, 0);
}


size_t ExpParser::FactorContext::getRuleIndex() const {
  return ExpParser::RuleFactor;
}


ExpParser::FactorContext* ExpParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 8, ExpParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExpParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(37);
        dynamic_cast<FactorContext *>(_localctx)->numberToken = match(ExpParser::NUMBER);

                cout << "    ldc " << (dynamic_cast<FactorContext *>(_localctx)->numberToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->numberToken->getText() : "") << "\n";
                // symbol_table.push_back((dynamic_cast<FactorContext *>(_localctx)->numberToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->numberToken->getText() : ""));
            
        break;
      }

      case ExpParser::OP_PAR: {
        enterOuterAlt(_localctx, 2);
        setState(39);
        match(ExpParser::OP_PAR);
        setState(40);
        expression();
        setState(41);
        match(ExpParser::CL_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExpParser::_decisionToDFA;
atn::PredictionContextCache ExpParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExpParser::_atn;
std::vector<uint16_t> ExpParser::_serializedATN;

std::vector<std::string> ExpParser::_ruleNames = {
  "program", "main", "expression", "term", "factor"
};

std::vector<std::string> ExpParser::_literalNames = {
  "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'"
};

std::vector<std::string> ExpParser::_symbolicNames = {
  "", "COMMENT", "SPACE", "PLUS", "MINUS", "TIMES", "OVER", "REM", "OP_PAR", 
  "CL_PAR", "NUMBER"
};

dfa::Vocabulary ExpParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExpParser::_tokenNames;

ExpParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xc, 0x30, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x19, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x1c, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x23, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x26, 0xb, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x2e, 0xa, 0x6, 
    0x3, 0x6, 0x2, 0x2, 0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x4, 0x3, 0x2, 
    0x5, 0x6, 0x3, 0x2, 0x7, 0x9, 0x2, 0x2d, 0x2, 0xc, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x8, 0x2, 
    0x1, 0x2, 0xd, 0xe, 0x5, 0x4, 0x3, 0x2, 0xe, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x10, 0x8, 0x3, 0x1, 0x2, 0x10, 0x11, 0x5, 0x6, 0x4, 0x2, 0x11, 
    0x12, 0x8, 0x3, 0x1, 0x2, 0x12, 0x5, 0x3, 0x2, 0x2, 0x2, 0x13, 0x1a, 
    0x5, 0x8, 0x5, 0x2, 0x14, 0x15, 0x9, 0x2, 0x2, 0x2, 0x15, 0x16, 0x5, 
    0x8, 0x5, 0x2, 0x16, 0x17, 0x8, 0x4, 0x1, 0x2, 0x17, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x14, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x1b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1d, 
    0x24, 0x5, 0xa, 0x6, 0x2, 0x1e, 0x1f, 0x9, 0x3, 0x2, 0x2, 0x1f, 0x20, 
    0x5, 0xa, 0x6, 0x2, 0x20, 0x21, 0x8, 0x5, 0x1, 0x2, 0x21, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x23, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x9, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x28, 0x7, 0xc, 0x2, 0x2, 0x28, 0x2e, 0x8, 0x6, 0x1, 0x2, 0x29, 
    0x2a, 0x7, 0xa, 0x2, 0x2, 0x2a, 0x2b, 0x5, 0x6, 0x4, 0x2, 0x2b, 0x2c, 
    0x7, 0xb, 0x2, 0x2, 0x2c, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x2d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x5, 0x1a, 0x24, 0x2d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExpParser::Initializer ExpParser::_init;
