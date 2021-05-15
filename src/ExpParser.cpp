
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <stdlib.h>
    
    
    using namespace std;


// Generated from src/Exp.g4 by ANTLR 4.9.1



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
        
    setState(33);
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

std::vector<ExpParser::StatementContext *> ExpParser::MainContext::statement() {
  return getRuleContexts<ExpParser::StatementContext>();
}

ExpParser::StatementContext* ExpParser::MainContext::statement(size_t i) {
  return getRuleContext<ExpParser::StatementContext>(i);
}


size_t ExpParser::MainContext::getRuleIndex() const {
  return ExpParser::RuleMain;
}


ExpParser::MainContext* ExpParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, ExpParser::RuleMain);
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

            cout << ".method public static main([Ljava/lang/String;)V\n\n";
        
    setState(37); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(36);
      statement();
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExpParser::PRINT)
      | (1ULL << ExpParser::IF)
      | (1ULL << ExpParser::WHILE)
      | (1ULL << ExpParser::BREAK)
      | (1ULL << ExpParser::CONTINUE)
      | (1ULL << ExpParser::NAME))) != 0));

            cout << " return\n";
            cout << ".limit stack " << stackMax << "\n";
            cout << ".limit locals " << symbol_table.size() << "\n";
            cout << ".end method\n";
            cout << "\n; symbol_table: ";
            for (string& symbol : symbol_table)
                cout << symbol << " ";
            cout << "\n";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ExpParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExpParser::St_printContext* ExpParser::StatementContext::st_print() {
  return getRuleContext<ExpParser::St_printContext>(0);
}

ExpParser::St_attribContext* ExpParser::StatementContext::st_attrib() {
  return getRuleContext<ExpParser::St_attribContext>(0);
}

ExpParser::St_ifContext* ExpParser::StatementContext::st_if() {
  return getRuleContext<ExpParser::St_ifContext>(0);
}

ExpParser::St_whileContext* ExpParser::StatementContext::st_while() {
  return getRuleContext<ExpParser::St_whileContext>(0);
}

ExpParser::St_breakContext* ExpParser::StatementContext::st_break() {
  return getRuleContext<ExpParser::St_breakContext>(0);
}

ExpParser::St_continueContext* ExpParser::StatementContext::st_continue() {
  return getRuleContext<ExpParser::St_continueContext>(0);
}

ExpParser::Str_array_createContext* ExpParser::StatementContext::str_array_create() {
  return getRuleContext<ExpParser::Str_array_createContext>(0);
}

ExpParser::St_array_pushContext* ExpParser::StatementContext::st_array_push() {
  return getRuleContext<ExpParser::St_array_pushContext>(0);
}

ExpParser::St_array_setContext* ExpParser::StatementContext::st_array_set() {
  return getRuleContext<ExpParser::St_array_setContext>(0);
}


size_t ExpParser::StatementContext::getRuleIndex() const {
  return ExpParser::RuleStatement;
}


ExpParser::StatementContext* ExpParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, ExpParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(52);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(43);
      st_print();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(44);
      st_attrib();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(45);
      st_if();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(46);
      st_while();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(47);
      st_break();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(48);
      st_continue();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(49);
      str_array_create();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(50);
      st_array_push();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(51);
      st_array_set();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_printContext ------------------------------------------------------------------

ExpParser::St_printContext::St_printContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_printContext::PRINT() {
  return getToken(ExpParser::PRINT, 0);
}

tree::TerminalNode* ExpParser::St_printContext::OP_PAR() {
  return getToken(ExpParser::OP_PAR, 0);
}

std::vector<ExpParser::ExpressionContext *> ExpParser::St_printContext::expression() {
  return getRuleContexts<ExpParser::ExpressionContext>();
}

ExpParser::ExpressionContext* ExpParser::St_printContext::expression(size_t i) {
  return getRuleContext<ExpParser::ExpressionContext>(i);
}

tree::TerminalNode* ExpParser::St_printContext::CL_PAR() {
  return getToken(ExpParser::CL_PAR, 0);
}

std::vector<tree::TerminalNode *> ExpParser::St_printContext::COMMA() {
  return getTokens(ExpParser::COMMA);
}

tree::TerminalNode* ExpParser::St_printContext::COMMA(size_t i) {
  return getToken(ExpParser::COMMA, i);
}


size_t ExpParser::St_printContext::getRuleIndex() const {
  return ExpParser::RuleSt_print;
}


ExpParser::St_printContext* ExpParser::st_print() {
  St_printContext *_localctx = _tracker.createInstance<St_printContext>(_ctx, getState());
  enterRule(_localctx, 6, ExpParser::RuleSt_print);
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
    setState(54);
    match(ExpParser::PRINT);
    setState(55);
    match(ExpParser::OP_PAR);

            calculateStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
        
    setState(57);
    dynamic_cast<St_printContext *>(_localctx)->expressionContext = expression();

            if (dynamic_cast<St_printContext *>(_localctx)->expressionContext->type == 'i') 
                calculateStack("invokevirtual java/io/PrintStream/print(I)V", -2);
            else if (dynamic_cast<St_printContext *>(_localctx)->expressionContext->type == 's') 
                calculateStack("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V", -2);
            else
                printFormat("\nExpression ST_PRINT type invalid\n\n");
        
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExpParser::COMMA) {
      setState(59);
      match(ExpParser::COMMA);

              calculateStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
          
      setState(61);
      dynamic_cast<St_printContext *>(_localctx)->expressionContext = expression();

              calculateStack("invokevirtual java/io/PrintStream/print(I)V", -2);
          
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(ExpParser::CL_PAR);

            calculateStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
            calculateStack("invokevirtual java/io/PrintStream/println()V", -1);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_attribContext ------------------------------------------------------------------

ExpParser::St_attribContext::St_attribContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_attribContext::NAME() {
  return getToken(ExpParser::NAME, 0);
}

tree::TerminalNode* ExpParser::St_attribContext::ATTRIB() {
  return getToken(ExpParser::ATTRIB, 0);
}

ExpParser::ExpressionContext* ExpParser::St_attribContext::expression() {
  return getRuleContext<ExpParser::ExpressionContext>(0);
}


size_t ExpParser::St_attribContext::getRuleIndex() const {
  return ExpParser::RuleSt_attrib;
}


ExpParser::St_attribContext* ExpParser::st_attrib() {
  St_attribContext *_localctx = _tracker.createInstance<St_attribContext>(_ctx, getState());
  enterRule(_localctx, 8, ExpParser::RuleSt_attrib);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    dynamic_cast<St_attribContext *>(_localctx)->nameToken = match(ExpParser::NAME);
    setState(73);
    match(ExpParser::ATTRIB);
    setState(74);
    dynamic_cast<St_attribContext *>(_localctx)->expressionContext = expression();

            auto it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<St_attribContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<St_attribContext *>(_localctx)->nameToken->getText() : ""));

            if (it == symbol_table.end())
            {
                symbol_table.push_back((dynamic_cast<St_attribContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<St_attribContext *>(_localctx)->nameToken->getText() : ""));
                type_table.push_back(dynamic_cast<St_attribContext *>(_localctx)->expressionContext->type);
            }

            it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<St_attribContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<St_attribContext *>(_localctx)->nameToken->getText() : ""));
            int index = distance(symbol_table.begin(), it);
            char type = type_table[index];

            if (type == 'i')
                calculateStack("istore " + to_string(index), -1);
            else if (type == 's')
                calculateStack("astore " + to_string(index), -1);
            else
                printFormat("\nExpression ST_ATTRIB type invalid\n\n");
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_ifContext ------------------------------------------------------------------

ExpParser::St_ifContext::St_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_ifContext::IF() {
  return getToken(ExpParser::IF, 0);
}

ExpParser::ComparisionContext* ExpParser::St_ifContext::comparision() {
  return getRuleContext<ExpParser::ComparisionContext>(0);
}

std::vector<tree::TerminalNode *> ExpParser::St_ifContext::OP_CUR() {
  return getTokens(ExpParser::OP_CUR);
}

tree::TerminalNode* ExpParser::St_ifContext::OP_CUR(size_t i) {
  return getToken(ExpParser::OP_CUR, i);
}

std::vector<tree::TerminalNode *> ExpParser::St_ifContext::CL_CUR() {
  return getTokens(ExpParser::CL_CUR);
}

tree::TerminalNode* ExpParser::St_ifContext::CL_CUR(size_t i) {
  return getToken(ExpParser::CL_CUR, i);
}

std::vector<ExpParser::StatementContext *> ExpParser::St_ifContext::statement() {
  return getRuleContexts<ExpParser::StatementContext>();
}

ExpParser::StatementContext* ExpParser::St_ifContext::statement(size_t i) {
  return getRuleContext<ExpParser::StatementContext>(i);
}

tree::TerminalNode* ExpParser::St_ifContext::ELSE() {
  return getToken(ExpParser::ELSE, 0);
}


size_t ExpParser::St_ifContext::getRuleIndex() const {
  return ExpParser::RuleSt_if;
}


ExpParser::St_ifContext* ExpParser::st_if() {
  St_ifContext *_localctx = _tracker.createInstance<St_ifContext>(_ctx, getState());
  enterRule(_localctx, 10, ExpParser::RuleSt_if);
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
    setState(77);
    match(ExpParser::IF);
    setState(78);
    comparision();

            int ifLocal   = ifCounter;
            ifCounter++;

            calculateStack("NOT_IF_" + to_string(ifLocal), -2);
        
    setState(80);
    match(ExpParser::OP_CUR);
    setState(82); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(81);
      statement();
      setState(84); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExpParser::PRINT)
      | (1ULL << ExpParser::IF)
      | (1ULL << ExpParser::WHILE)
      | (1ULL << ExpParser::BREAK)
      | (1ULL << ExpParser::CONTINUE)
      | (1ULL << ExpParser::NAME))) != 0));
    setState(86);
    match(ExpParser::CL_CUR);

            printFormat("goto END_ELSE_" + to_string(ifLocal) + "\n");
            printFormat("NOT_IF_" + to_string(ifLocal) + ":\n");
        
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExpParser::ELSE) {
      setState(88);
      match(ExpParser::ELSE);
      setState(89);
      match(ExpParser::OP_CUR);
      setState(91); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(90);
        statement();
        setState(93); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExpParser::PRINT)
        | (1ULL << ExpParser::IF)
        | (1ULL << ExpParser::WHILE)
        | (1ULL << ExpParser::BREAK)
        | (1ULL << ExpParser::CONTINUE)
        | (1ULL << ExpParser::NAME))) != 0));
      setState(95);
      match(ExpParser::CL_CUR);
    }

            printFormat("END_ELSE_" + to_string(ifLocal) + ":\n");
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_whileContext ------------------------------------------------------------------

ExpParser::St_whileContext::St_whileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_whileContext::WHILE() {
  return getToken(ExpParser::WHILE, 0);
}

ExpParser::ComparisionContext* ExpParser::St_whileContext::comparision() {
  return getRuleContext<ExpParser::ComparisionContext>(0);
}

tree::TerminalNode* ExpParser::St_whileContext::OP_CUR() {
  return getToken(ExpParser::OP_CUR, 0);
}

tree::TerminalNode* ExpParser::St_whileContext::CL_CUR() {
  return getToken(ExpParser::CL_CUR, 0);
}

std::vector<ExpParser::StatementContext *> ExpParser::St_whileContext::statement() {
  return getRuleContexts<ExpParser::StatementContext>();
}

ExpParser::StatementContext* ExpParser::St_whileContext::statement(size_t i) {
  return getRuleContext<ExpParser::StatementContext>(i);
}


size_t ExpParser::St_whileContext::getRuleIndex() const {
  return ExpParser::RuleSt_while;
}


ExpParser::St_whileContext* ExpParser::st_while() {
  St_whileContext *_localctx = _tracker.createInstance<St_whileContext>(_ctx, getState());
  enterRule(_localctx, 12, ExpParser::RuleSt_while);
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
    setState(101);
    match(ExpParser::WHILE);

            whileCounter++;
            int whileLocal = whileCounter;
            list_while.push_back(whileCounter);

            printFormat("BEGIN_WHILE_" + to_string(whileLocal) + ":\n");
        
    setState(103);
    comparision();

            calculateStack("END_WHILE_" + to_string(whileLocal), -2);
        
    setState(105);
    match(ExpParser::OP_CUR);
    setState(107); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(106);
      statement();
      setState(109); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExpParser::PRINT)
      | (1ULL << ExpParser::IF)
      | (1ULL << ExpParser::WHILE)
      | (1ULL << ExpParser::BREAK)
      | (1ULL << ExpParser::CONTINUE)
      | (1ULL << ExpParser::NAME))) != 0));
    setState(111);
    match(ExpParser::CL_CUR);

            printFormat("goto BEGIN_WHILE_" + to_string(whileLocal) + "\n");
            printFormat("END_WHILE_" + to_string(whileLocal) + ":\n");
            list_while.pop_back();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_breakContext ------------------------------------------------------------------

ExpParser::St_breakContext::St_breakContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_breakContext::BREAK() {
  return getToken(ExpParser::BREAK, 0);
}


size_t ExpParser::St_breakContext::getRuleIndex() const {
  return ExpParser::RuleSt_break;
}


ExpParser::St_breakContext* ExpParser::st_break() {
  St_breakContext *_localctx = _tracker.createInstance<St_breakContext>(_ctx, getState());
  enterRule(_localctx, 14, ExpParser::RuleSt_break);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(ExpParser::BREAK);

            if (!list_while.empty())
                printFormat("goto END_WHILE_" + to_string(list_while[list_while.size() - 1]) + "\n");
            else
                cerr << "Error: Line " << _localctx->getStart()->getLine() << " - Ignoring break. Break needs to be used inside a while\n";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_continueContext ------------------------------------------------------------------

ExpParser::St_continueContext::St_continueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_continueContext::CONTINUE() {
  return getToken(ExpParser::CONTINUE, 0);
}


size_t ExpParser::St_continueContext::getRuleIndex() const {
  return ExpParser::RuleSt_continue;
}


ExpParser::St_continueContext* ExpParser::st_continue() {
  St_continueContext *_localctx = _tracker.createInstance<St_continueContext>(_ctx, getState());
  enterRule(_localctx, 16, ExpParser::RuleSt_continue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(ExpParser::CONTINUE);

            if (!list_while.empty())
                printFormat("goto BEGIN_WHILE_" + to_string(list_while.size() - 1) + "\n");
            else {
                cerr << "Error: Line " << _localctx->getStart()->getLine() << " - Ignoring continue. Continue needs to be used inside a while\n";
            }
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Str_array_createContext ------------------------------------------------------------------

ExpParser::Str_array_createContext::Str_array_createContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::Str_array_createContext::NAME() {
  return getToken(ExpParser::NAME, 0);
}

tree::TerminalNode* ExpParser::Str_array_createContext::ATTRIB() {
  return getToken(ExpParser::ATTRIB, 0);
}

tree::TerminalNode* ExpParser::Str_array_createContext::OP_BRA() {
  return getToken(ExpParser::OP_BRA, 0);
}

tree::TerminalNode* ExpParser::Str_array_createContext::CL_BRA() {
  return getToken(ExpParser::CL_BRA, 0);
}


size_t ExpParser::Str_array_createContext::getRuleIndex() const {
  return ExpParser::RuleStr_array_create;
}


ExpParser::Str_array_createContext* ExpParser::str_array_create() {
  Str_array_createContext *_localctx = _tracker.createInstance<Str_array_createContext>(_ctx, getState());
  enterRule(_localctx, 18, ExpParser::RuleStr_array_create);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    dynamic_cast<Str_array_createContext *>(_localctx)->nameToken = match(ExpParser::NAME);
    setState(121);
    match(ExpParser::ATTRIB);
    setState(122);
    match(ExpParser::OP_BRA);
    setState(123);
    match(ExpParser::CL_BRA);

            symbol_table.push_back((dynamic_cast<Str_array_createContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<Str_array_createContext *>(_localctx)->nameToken->getText() : ""));
            type_table.push_back('a');
            int index = symbol_table.size() - 1;

            calculateStack("new Array", 1);
            calculateStack("dup", 1);
            calculateStack("invokespecial Array/<init>()V", -1);
            calculateStack("astore " + to_string(index), -1);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_array_pushContext ------------------------------------------------------------------

ExpParser::St_array_pushContext::St_array_pushContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_array_pushContext::NAME() {
  return getToken(ExpParser::NAME, 0);
}

tree::TerminalNode* ExpParser::St_array_pushContext::DOT() {
  return getToken(ExpParser::DOT, 0);
}

tree::TerminalNode* ExpParser::St_array_pushContext::PUSH() {
  return getToken(ExpParser::PUSH, 0);
}

tree::TerminalNode* ExpParser::St_array_pushContext::OP_PAR() {
  return getToken(ExpParser::OP_PAR, 0);
}

ExpParser::ExpressionContext* ExpParser::St_array_pushContext::expression() {
  return getRuleContext<ExpParser::ExpressionContext>(0);
}

tree::TerminalNode* ExpParser::St_array_pushContext::CL_PAR() {
  return getToken(ExpParser::CL_PAR, 0);
}


size_t ExpParser::St_array_pushContext::getRuleIndex() const {
  return ExpParser::RuleSt_array_push;
}


ExpParser::St_array_pushContext* ExpParser::st_array_push() {
  St_array_pushContext *_localctx = _tracker.createInstance<St_array_pushContext>(_ctx, getState());
  enterRule(_localctx, 20, ExpParser::RuleSt_array_push);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    dynamic_cast<St_array_pushContext *>(_localctx)->nameToken = match(ExpParser::NAME);
    setState(127);
    match(ExpParser::DOT);
    setState(128);
    match(ExpParser::PUSH);
    setState(129);
    match(ExpParser::OP_PAR);

            auto it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<St_array_pushContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<St_array_pushContext *>(_localctx)->nameToken->getText() : ""));
            int index = distance(symbol_table.begin(), it);
            char type = type_table[index];


            if (type == 'a') 
                calculateStack("aload " + to_string(index), 1);
            else {
                cerr << (dynamic_cast<St_array_pushContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<St_array_pushContext *>(_localctx)->nameToken->getText() : "") << " is not an array\n";
                // printFormat("invokevirtual Array/exit()V\n");
                // exit(0);
            }
        
    setState(131);
    dynamic_cast<St_array_pushContext *>(_localctx)->expressionContext = expression();
    setState(132);
    match(ExpParser::CL_PAR);

            if (dynamic_cast<St_array_pushContext *>(_localctx)->expressionContext->type == 'i')
                calculateStack("invokevirtual Array/push(I)V", -2);
            else
                printFormat("expression CL_PAR type not valid!\n");
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_array_setContext ------------------------------------------------------------------

ExpParser::St_array_setContext::St_array_setContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExpParser::St_array_setContext::NAME() {
  return getToken(ExpParser::NAME, 0);
}

tree::TerminalNode* ExpParser::St_array_setContext::OP_BRA() {
  return getToken(ExpParser::OP_BRA, 0);
}

tree::TerminalNode* ExpParser::St_array_setContext::CL_BRA() {
  return getToken(ExpParser::CL_BRA, 0);
}

tree::TerminalNode* ExpParser::St_array_setContext::ATTRIB() {
  return getToken(ExpParser::ATTRIB, 0);
}

std::vector<ExpParser::ExpressionContext *> ExpParser::St_array_setContext::expression() {
  return getRuleContexts<ExpParser::ExpressionContext>();
}

ExpParser::ExpressionContext* ExpParser::St_array_setContext::expression(size_t i) {
  return getRuleContext<ExpParser::ExpressionContext>(i);
}


size_t ExpParser::St_array_setContext::getRuleIndex() const {
  return ExpParser::RuleSt_array_set;
}


ExpParser::St_array_setContext* ExpParser::st_array_set() {
  St_array_setContext *_localctx = _tracker.createInstance<St_array_setContext>(_ctx, getState());
  enterRule(_localctx, 22, ExpParser::RuleSt_array_set);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    dynamic_cast<St_array_setContext *>(_localctx)->nameToken = match(ExpParser::NAME);
    setState(136);
    match(ExpParser::OP_BRA);

            auto it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<St_array_setContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<St_array_setContext *>(_localctx)->nameToken->getText() : ""));
            int index = distance(symbol_table.begin(), it);
            char type = type_table[index]; 

            calculateStack("aload " + to_string(index), 1);
        
    setState(138);
    dynamic_cast<St_array_setContext *>(_localctx)->ex1 = expression();
    setState(139);
    match(ExpParser::CL_BRA);
    setState(140);
    match(ExpParser::ATTRIB);
    setState(141);
    dynamic_cast<St_array_setContext *>(_localctx)->ex2 = expression();

            if (dynamic_cast<St_array_setContext *>(_localctx)->ex1->type == 'i' && dynamic_cast<St_array_setContext *>(_localctx)->ex2->type == 'i')
                calculateStack("invokevirtual Array/set(II)V", -3);
            else
                printFormat("\ninvalid st_array_set type\n");
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisionContext ------------------------------------------------------------------

ExpParser::ComparisionContext::ComparisionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExpParser::ExpressionContext *> ExpParser::ComparisionContext::expression() {
  return getRuleContexts<ExpParser::ExpressionContext>();
}

ExpParser::ExpressionContext* ExpParser::ComparisionContext::expression(size_t i) {
  return getRuleContext<ExpParser::ExpressionContext>(i);
}

tree::TerminalNode* ExpParser::ComparisionContext::EQ() {
  return getToken(ExpParser::EQ, 0);
}

tree::TerminalNode* ExpParser::ComparisionContext::NE() {
  return getToken(ExpParser::NE, 0);
}

tree::TerminalNode* ExpParser::ComparisionContext::GT() {
  return getToken(ExpParser::GT, 0);
}

tree::TerminalNode* ExpParser::ComparisionContext::GE() {
  return getToken(ExpParser::GE, 0);
}

tree::TerminalNode* ExpParser::ComparisionContext::LT() {
  return getToken(ExpParser::LT, 0);
}

tree::TerminalNode* ExpParser::ComparisionContext::LE() {
  return getToken(ExpParser::LE, 0);
}


size_t ExpParser::ComparisionContext::getRuleIndex() const {
  return ExpParser::RuleComparision;
}


ExpParser::ComparisionContext* ExpParser::comparision() {
  ComparisionContext *_localctx = _tracker.createInstance<ComparisionContext>(_ctx, getState());
  enterRule(_localctx, 24, ExpParser::RuleComparision);
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
    setState(144);
    expression();
    setState(145);
    dynamic_cast<ComparisionContext *>(_localctx)->op = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExpParser::EQ)
      | (1ULL << ExpParser::NE)
      | (1ULL << ExpParser::GT)
      | (1ULL << ExpParser::GE)
      | (1ULL << ExpParser::LT)
      | (1ULL << ExpParser::LE))) != 0))) {
      dynamic_cast<ComparisionContext *>(_localctx)->op = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(146);
    expression();

            if ((dynamic_cast<ComparisionContext *>(_localctx)->op != nullptr ? dynamic_cast<ComparisionContext *>(_localctx)->op->getType() : 0) == EQ) printFormat("if_icmpne");
            if ((dynamic_cast<ComparisionContext *>(_localctx)->op != nullptr ? dynamic_cast<ComparisionContext *>(_localctx)->op->getType() : 0) == NE) printFormat("if_icmpeq");
            if ((dynamic_cast<ComparisionContext *>(_localctx)->op != nullptr ? dynamic_cast<ComparisionContext *>(_localctx)->op->getType() : 0) == GT) printFormat("if_icmple");
            if ((dynamic_cast<ComparisionContext *>(_localctx)->op != nullptr ? dynamic_cast<ComparisionContext *>(_localctx)->op->getType() : 0) == GE) printFormat("if_icmplt");
            if ((dynamic_cast<ComparisionContext *>(_localctx)->op != nullptr ? dynamic_cast<ComparisionContext *>(_localctx)->op->getType() : 0) == LT) printFormat("if_icmpge");
            if ((dynamic_cast<ComparisionContext *>(_localctx)->op != nullptr ? dynamic_cast<ComparisionContext *>(_localctx)->op->getType() : 0) == LE) printFormat("if_icmpgt");
        
   
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
  enterRule(_localctx, 26, ExpParser::RuleExpression);
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
    setState(149);
    dynamic_cast<ExpressionContext *>(_localctx)->t1 = term();
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExpParser::PLUS

    || _la == ExpParser::MINUS) {
      setState(150);
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
      setState(151);
      term();

              if ((dynamic_cast<ExpressionContext *>(_localctx)->op != nullptr ? dynamic_cast<ExpressionContext *>(_localctx)->op->getType() : 0) == PLUS) calculateStack("iadd", -1);
              if ((dynamic_cast<ExpressionContext *>(_localctx)->op != nullptr ? dynamic_cast<ExpressionContext *>(_localctx)->op->getType() : 0) == MINUS) calculateStack("isub", -1);
          
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

            dynamic_cast<ExpressionContext *>(_localctx)->type =  dynamic_cast<ExpressionContext *>(_localctx)->t1->type;
        
   
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
  enterRule(_localctx, 28, ExpParser::RuleTerm);
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
    setState(161);
    dynamic_cast<TermContext *>(_localctx)->f1 = factor();
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExpParser::TIMES)
      | (1ULL << ExpParser::OVER)
      | (1ULL << ExpParser::REM))) != 0)) {
      setState(162);
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
      setState(163);
      factor();

              if ((dynamic_cast<TermContext *>(_localctx)->op != nullptr ? dynamic_cast<TermContext *>(_localctx)->op->getType() : 0) == TIMES) calculateStack("imul", -1);
              if ((dynamic_cast<TermContext *>(_localctx)->op != nullptr ? dynamic_cast<TermContext *>(_localctx)->op->getType() : 0) == OVER) calculateStack("idiv", -1);
              if ((dynamic_cast<TermContext *>(_localctx)->op != nullptr ? dynamic_cast<TermContext *>(_localctx)->op->getType() : 0) == REM) calculateStack("irem", -1);
          
      setState(170);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

            dynamic_cast<TermContext *>(_localctx)->type =  dynamic_cast<TermContext *>(_localctx)->f1->type;
        
   
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

tree::TerminalNode* ExpParser::FactorContext::STRING() {
  return getToken(ExpParser::STRING, 0);
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

tree::TerminalNode* ExpParser::FactorContext::NAME() {
  return getToken(ExpParser::NAME, 0);
}

tree::TerminalNode* ExpParser::FactorContext::OP_BRA() {
  return getToken(ExpParser::OP_BRA, 0);
}

tree::TerminalNode* ExpParser::FactorContext::CL_BRA() {
  return getToken(ExpParser::CL_BRA, 0);
}

tree::TerminalNode* ExpParser::FactorContext::DOT() {
  return getToken(ExpParser::DOT, 0);
}

tree::TerminalNode* ExpParser::FactorContext::LENGTH() {
  return getToken(ExpParser::LENGTH, 0);
}

tree::TerminalNode* ExpParser::FactorContext::READ_INT() {
  return getToken(ExpParser::READ_INT, 0);
}

tree::TerminalNode* ExpParser::FactorContext::READ_STR() {
  return getToken(ExpParser::READ_STR, 0);
}


size_t ExpParser::FactorContext::getRuleIndex() const {
  return ExpParser::RuleFactor;
}


ExpParser::FactorContext* ExpParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 30, ExpParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(173);
      dynamic_cast<FactorContext *>(_localctx)->numberToken = match(ExpParser::NUMBER);

              calculateStack("ldc " + (dynamic_cast<FactorContext *>(_localctx)->numberToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->numberToken->getText() : ""), +1);
              dynamic_cast<FactorContext *>(_localctx)->type =  'i';
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      dynamic_cast<FactorContext *>(_localctx)->stringToken = match(ExpParser::STRING);

              calculateStack("ldc " + (dynamic_cast<FactorContext *>(_localctx)->stringToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->stringToken->getText() : ""), +1);
              dynamic_cast<FactorContext *>(_localctx)->type =  's';
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(177);
      match(ExpParser::OP_PAR);
      setState(178);
      dynamic_cast<FactorContext *>(_localctx)->expressionContext = expression();
      setState(179);
      match(ExpParser::CL_PAR);

              dynamic_cast<FactorContext *>(_localctx)->type =  dynamic_cast<FactorContext *>(_localctx)->expressionContext->type;
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(182);
      dynamic_cast<FactorContext *>(_localctx)->nameToken = match(ExpParser::NAME);

              auto it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<FactorContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->nameToken->getText() : ""));
              int index = distance(symbol_table.begin(), it);
              char type = type_table[index];

              if (type == 'i')
                  calculateStack("iload " + to_string(index), +1);
              else if (type == 's')
                  calculateStack("aload " + to_string(index), +1);
              else if (type == 'a'){
                  calculateStack("aload " + to_string(index), +1);
                  printFormat("invokevirtual Array/string()Ljava/lang/String;\n");
                  type = 's';
              }else
                  printFormat("\nExpression NAME type invalid\n\n");
              
              dynamic_cast<FactorContext *>(_localctx)->type =  type;
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(184);
      dynamic_cast<FactorContext *>(_localctx)->nameToken = match(ExpParser::NAME);
      setState(185);
      match(ExpParser::OP_BRA);

              auto it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<FactorContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->nameToken->getText() : ""));
              int index = distance(symbol_table.begin(), it);
              char type = type_table[index];

              if (type == 'a') {
                  calculateStack("aload " + to_string(index), +1);
              } else {
                  printFormat("\nExpression NAME OP_BRA type invalid\n\n");
              }

          
      setState(187);
      expression();
      setState(188);
      match(ExpParser::CL_BRA);

              calculateStack("invokevirtual Array/get(I)I", -1);
              dynamic_cast<FactorContext *>(_localctx)->type =  'i';
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(191);
      dynamic_cast<FactorContext *>(_localctx)->nameToken = match(ExpParser::NAME);
      setState(192);
      match(ExpParser::DOT);
      setState(193);
      match(ExpParser::LENGTH);

              printFormat("ENTROU NO LENGTH\n");
              auto it = find(symbol_table.begin(), symbol_table.end(), (dynamic_cast<FactorContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->nameToken->getText() : ""));
              int index = distance(symbol_table.begin(), it);
              char type = type_table[index];

              if (type == 'a') {
                  calculateStack("aload " + to_string(index), 1);
                  printFormat("invokevirtual Array/length()I\n");
                  dynamic_cast<FactorContext *>(_localctx)->type =  'i';
              } else {
                  // printFormat("\nNAME DOT LENGTH invalid type\n");
                  cerr << (dynamic_cast<FactorContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<FactorContext *>(_localctx)->nameToken->getText() : "") << " is not an array";
              }
              
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(195);
      match(ExpParser::READ_INT);
      setState(196);
      match(ExpParser::OP_PAR);
      setState(197);
      match(ExpParser::CL_PAR);

              calculateStack("invokestatic Runtime/readInt()I", +1);
              dynamic_cast<FactorContext *>(_localctx)->type =  'i';
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(199);
      match(ExpParser::READ_STR);
      setState(200);
      match(ExpParser::OP_PAR);
      setState(201);
      match(ExpParser::CL_PAR);

              printFormat("invokestatic Runtime/readString()Ljava/lang/String;\n");
              dynamic_cast<FactorContext *>(_localctx)->type =  's';
          
      break;
    }

    default:
      break;
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
  "program", "main", "statement", "st_print", "st_attrib", "st_if", "st_while", 
  "st_break", "st_continue", "str_array_create", "st_array_push", "st_array_set", 
  "comparision", "expression", "term", "factor"
};

std::vector<std::string> ExpParser::_literalNames = {
  "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'['", "']'", "'('", 
  "')'", "'{'", "'}'", "'='", "','", "'.'", "'=='", "'!='", "'>'", "'>='", 
  "'<'", "'<='", "", "", "'print'", "'read_int'", "'read_str'", "'if'", 
  "'else'", "'while'", "'break'", "'continue'", "'push'", "'length'"
};

std::vector<std::string> ExpParser::_symbolicNames = {
  "", "MLCOMMENT", "COMMENT", "SPACE", "PLUS", "MINUS", "TIMES", "OVER", 
  "REM", "OP_BRA", "CL_BRA", "OP_PAR", "CL_PAR", "OP_CUR", "CL_CUR", "ATTRIB", 
  "COMMA", "DOT", "EQ", "NE", "GT", "GE", "LT", "LE", "NUMBER", "STRING", 
  "PRINT", "READ_INT", "READ_STR", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
  "PUSH", "LENGTH", "NAME"
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
    0x3, 0x26, 0xd0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x28, 0xa, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0x29, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x37, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x43, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x46, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x55, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 
    0x56, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x5e, 
    0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x5f, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x64, 
    0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x6e, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x6f, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0x9d, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xa0, 0xb, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0xa9, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xac, 0xb, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0xce, 0xa, 0x11, 0x3, 0x11, 0x2, 0x2, 0x12, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x2, 0x5, 0x3, 0x2, 0x14, 0x19, 0x3, 0x2, 0x6, 0x7, 0x3, 0x2, 0x8, 0xa, 
    0x2, 0xd6, 0x2, 0x22, 0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x36, 0x3, 0x2, 0x2, 0x2, 0x8, 0x38, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x74, 0x3, 0x2, 0x2, 0x2, 0x12, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x16, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x89, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x8, 0x2, 0x1, 0x2, 0x23, 
    0x24, 0x5, 0x4, 0x3, 0x2, 0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 0x27, 
    0x8, 0x3, 0x1, 0x2, 0x26, 0x28, 0x5, 0x6, 0x4, 0x2, 0x27, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x2c, 0x8, 0x3, 0x1, 0x2, 0x2c, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x37, 0x5, 0x8, 0x5, 0x2, 0x2e, 0x37, 0x5, 0xa, 0x6, 0x2, 0x2f, 
    0x37, 0x5, 0xc, 0x7, 0x2, 0x30, 0x37, 0x5, 0xe, 0x8, 0x2, 0x31, 0x37, 
    0x5, 0x10, 0x9, 0x2, 0x32, 0x37, 0x5, 0x12, 0xa, 0x2, 0x33, 0x37, 0x5, 
    0x14, 0xb, 0x2, 0x34, 0x37, 0x5, 0x16, 0xc, 0x2, 0x35, 0x37, 0x5, 0x18, 
    0xd, 0x2, 0x36, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x36, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x30, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x31, 0x3, 0x2, 0x2, 0x2, 0x36, 0x32, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x7, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 
    0x1c, 0x2, 0x2, 0x39, 0x3a, 0x7, 0xd, 0x2, 0x2, 0x3a, 0x3b, 0x8, 0x5, 
    0x1, 0x2, 0x3b, 0x3c, 0x5, 0x1c, 0xf, 0x2, 0x3c, 0x44, 0x8, 0x5, 0x1, 
    0x2, 0x3d, 0x3e, 0x7, 0x12, 0x2, 0x2, 0x3e, 0x3f, 0x8, 0x5, 0x1, 0x2, 
    0x3f, 0x40, 0x5, 0x1c, 0xf, 0x2, 0x40, 0x41, 0x8, 0x5, 0x1, 0x2, 0x41, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x7, 0xe, 0x2, 0x2, 0x48, 0x49, 0x8, 0x5, 0x1, 
    0x2, 0x49, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x26, 0x2, 0x2, 
    0x4b, 0x4c, 0x7, 0x11, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x1c, 0xf, 0x2, 0x4d, 
    0x4e, 0x8, 0x6, 0x1, 0x2, 0x4e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 
    0x7, 0x1f, 0x2, 0x2, 0x50, 0x51, 0x5, 0x1a, 0xe, 0x2, 0x51, 0x52, 0x8, 
    0x7, 0x1, 0x2, 0x52, 0x54, 0x7, 0xf, 0x2, 0x2, 0x53, 0x55, 0x5, 0x6, 
    0x4, 0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x10, 0x2, 0x2, 0x59, 
    0x63, 0x8, 0x7, 0x1, 0x2, 0x5a, 0x5b, 0x7, 0x20, 0x2, 0x2, 0x5b, 0x5d, 
    0x7, 0xf, 0x2, 0x2, 0x5c, 0x5e, 0x5, 0x6, 0x4, 0x2, 0x5d, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0x10, 0x2, 0x2, 0x62, 0x64, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x8, 0x7, 0x1, 0x2, 0x66, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x21, 0x2, 0x2, 0x68, 0x69, 0x8, 
    0x8, 0x1, 0x2, 0x69, 0x6a, 0x5, 0x1a, 0xe, 0x2, 0x6a, 0x6b, 0x8, 0x8, 
    0x1, 0x2, 0x6b, 0x6d, 0x7, 0xf, 0x2, 0x2, 0x6c, 0x6e, 0x5, 0x6, 0x4, 
    0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x10, 0x2, 0x2, 0x72, 0x73, 
    0x8, 0x8, 0x1, 0x2, 0x73, 0xf, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 
    0x22, 0x2, 0x2, 0x75, 0x76, 0x8, 0x9, 0x1, 0x2, 0x76, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x78, 0x7, 0x23, 0x2, 0x2, 0x78, 0x79, 0x8, 0xa, 0x1, 
    0x2, 0x79, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x26, 0x2, 0x2, 
    0x7b, 0x7c, 0x7, 0x11, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xb, 0x2, 0x2, 0x7d, 
    0x7e, 0x7, 0xc, 0x2, 0x2, 0x7e, 0x7f, 0x8, 0xb, 0x1, 0x2, 0x7f, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0x26, 0x2, 0x2, 0x81, 0x82, 0x7, 
    0x13, 0x2, 0x2, 0x82, 0x83, 0x7, 0x24, 0x2, 0x2, 0x83, 0x84, 0x7, 0xd, 
    0x2, 0x2, 0x84, 0x85, 0x8, 0xc, 0x1, 0x2, 0x85, 0x86, 0x5, 0x1c, 0xf, 
    0x2, 0x86, 0x87, 0x7, 0xe, 0x2, 0x2, 0x87, 0x88, 0x8, 0xc, 0x1, 0x2, 
    0x88, 0x17, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x26, 0x2, 0x2, 0x8a, 
    0x8b, 0x7, 0xb, 0x2, 0x2, 0x8b, 0x8c, 0x8, 0xd, 0x1, 0x2, 0x8c, 0x8d, 
    0x5, 0x1c, 0xf, 0x2, 0x8d, 0x8e, 0x7, 0xc, 0x2, 0x2, 0x8e, 0x8f, 0x7, 
    0x11, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x1c, 0xf, 0x2, 0x90, 0x91, 0x8, 0xd, 
    0x1, 0x2, 0x91, 0x19, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x5, 0x1c, 0xf, 
    0x2, 0x93, 0x94, 0x9, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 0x1c, 0xf, 0x2, 
    0x95, 0x96, 0x8, 0xe, 0x1, 0x2, 0x96, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x9e, 0x5, 0x1e, 0x10, 0x2, 0x98, 0x99, 0x9, 0x3, 0x2, 0x2, 0x99, 0x9a, 
    0x5, 0x1e, 0x10, 0x2, 0x9a, 0x9b, 0x8, 0xf, 0x1, 0x2, 0x9b, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0xa2, 0x8, 0xf, 0x1, 0x2, 0xa2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa3, 
    0xaa, 0x5, 0x20, 0x11, 0x2, 0xa4, 0xa5, 0x9, 0x4, 0x2, 0x2, 0xa5, 0xa6, 
    0x5, 0x20, 0x11, 0x2, 0xa6, 0xa7, 0x8, 0x10, 0x1, 0x2, 0xa7, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xad, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0xae, 0x8, 0x10, 0x1, 0x2, 0xae, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x7, 0x1a, 0x2, 0x2, 0xb0, 0xce, 0x8, 0x11, 0x1, 0x2, 0xb1, 0xb2, 
    0x7, 0x1b, 0x2, 0x2, 0xb2, 0xce, 0x8, 0x11, 0x1, 0x2, 0xb3, 0xb4, 0x7, 
    0xd, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x1c, 0xf, 0x2, 0xb5, 0xb6, 0x7, 0xe, 
    0x2, 0x2, 0xb6, 0xb7, 0x8, 0x11, 0x1, 0x2, 0xb7, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x7, 0x26, 0x2, 0x2, 0xb9, 0xce, 0x8, 0x11, 0x1, 0x2, 
    0xba, 0xbb, 0x7, 0x26, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0xb, 0x2, 0x2, 0xbc, 
    0xbd, 0x8, 0x11, 0x1, 0x2, 0xbd, 0xbe, 0x5, 0x1c, 0xf, 0x2, 0xbe, 0xbf, 
    0x7, 0xc, 0x2, 0x2, 0xbf, 0xc0, 0x8, 0x11, 0x1, 0x2, 0xc0, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x26, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x13, 
    0x2, 0x2, 0xc3, 0xc4, 0x7, 0x25, 0x2, 0x2, 0xc4, 0xce, 0x8, 0x11, 0x1, 
    0x2, 0xc5, 0xc6, 0x7, 0x1d, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0xd, 0x2, 0x2, 
    0xc7, 0xc8, 0x7, 0xe, 0x2, 0x2, 0xc8, 0xce, 0x8, 0x11, 0x1, 0x2, 0xc9, 
    0xca, 0x7, 0x1e, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xd, 0x2, 0x2, 0xcb, 0xcc, 
    0x7, 0xe, 0x2, 0x2, 0xcc, 0xce, 0x8, 0x11, 0x1, 0x2, 0xcd, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xce, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x29, 0x36, 0x44, 0x56, 0x5f, 0x63, 0x6f, 0x9e, 0xaa, 0xcd, 
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
