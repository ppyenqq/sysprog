//
// Created by Tobias Kerst on 19.06.17.
//
//TODO(Toby): Rename methods according to other conventions

#include "SemanticAnalyzer.h"
#include "../../colors.h"
#include "../../Scanner/Token/IntegerToken.h"
#include <iostream>

using namespace std;

SemanticAnalyzer::SemanticAnalyzer() {
    //NOP
}

SemanticAnalyzer::~SemanticAnalyzer() {
    //NOP
}

Node *SemanticAnalyzer::run(ParseTree *tree) {
    return typeCheckProg(tree->getTree());
}

//PROG ::= DECLS STATEMENTS
Node *SemanticAnalyzer::typeCheckProg(Node *root) {
    Node *decls = root->getChild(0);
    Node *statements = root->getChild(1);

    analyze(decls);
    analyze(statements);

    root->setType(NO_TYPE);

    return root;
}

//DECLS ::= DECL ; DECLS
void SemanticAnalyzer::typeCheckDecls(Node *node) {
    Node *decl = node->getChild(0);
    Node *decls = node->getChild(1);

    analyze(decl);
    analyze(decls);

    node->setType(NO_TYPE);
}

//DECLS ::= e
void SemanticAnalyzer::typeCheckDecls_Empty(Node *node) {
    node->setType(NO_TYPE);
}

//DECL::= int ARRAY identifier
void SemanticAnalyzer::typeCheckDecl(Node *node) {
    Node *array = node->getChild(0);
    Node *identifier = node->getChild(1);

    analyze(array);

    if (identifier->getType() != NO_TYPE) {
        printError("Identifier is already defined!", identifier);
        node->setType(ERROR_TYPE);

    } else if (array->getType() == ERROR_TYPE) {
        node->setType(ERROR_TYPE);

    } else {
        node->setType(NO_TYPE);

        if (array->getType() == ARRAY_TYPE) {
            identifier->setType(INT_ARRAY_TYPE);
        } else {
            identifier->setType(INT_TYPE);
        }
    }
}

//ARRAY::=[integer]
void SemanticAnalyzer::typeCheckArray(Node *node) {
    Node *integer = node->getChild(0);

    if (integer->getToken()->getType() == INTEGER && static_cast<IntegerToken *>(integer->getToken())->getValue() >
                                                                 0) {
        node->setType(ARRAY_TYPE);
    } else {
        printError("No valid integer", 0L);
        node->setType(ERROR_TYPE);
    }
}

//ARRAY ::= e
void SemanticAnalyzer::typeCheckArray_Empty(Node *node) {
    node->setType(NO_TYPE);
}

//STATEMENTS ::= STATEMENT ; STATEMENTS)
void SemanticAnalyzer::typeCheckStatements(Node *node) {
    Node *statement = node->getChild(0);
    Node *statements = node->getChild(1);

    analyze(statement);

    if (statement != 0L) {
        analyze(statements);
    }

    node->setType(NO_TYPE);
}

//STATEMENTS ::= e
void SemanticAnalyzer::typeCheckStatements_Empty(Node *node) {
    node->setType(NO_TYPE);
}

//STATEMENT ::= identifier INDEX := EXP
void SemanticAnalyzer::typeCheckStatement_Identifier(Node *node) {

    Node *exp = node->getChild(2);
    Node *index = node->getChild(1);
    Node *identifier = node->getChild(0);

    analyze(exp);
    analyze(index);

    if (identifier->getType() == NO_TYPE) {
        printError("Identifier not defined", identifier);
        node->setType(ERROR_TYPE);

    } else if (exp->getType() == INT_TYPE && (
            (identifier->getType() == INT_TYPE && index->getType() == NO_TYPE)
            || (identifier->getType() == INT_ARRAY_TYPE && index->getType() == ARRAY_TYPE))) {
        node->setType(NO_TYPE);

    } else {
        printError("Incompatible types", identifier);
        node->setType(ERROR_TYPE);
    }
}

//STATEMENT ::= write( EXP )
void SemanticAnalyzer::typeCheckStatement_Write(Node *node) {
    Node *exp = node->getChild(0);
    analyze(exp);
    node->setType(NO_TYPE);
}

//STATEMENT ::= read( identifier INDEX)
void SemanticAnalyzer::typeCheckStatement_Read(Node *node) {
    Node *identifier = node->getChild(0);
    Node *index = node->getChild(1);

    analyze(index);

    if (identifier->getType() == NO_TYPE) {
        printError("Identifier not defined", identifier);
        node->setType(ERROR_TYPE);

    } else if (((identifier->getType() == INT_TYPE) && (index->getType() == NO_TYPE))
               || ((identifier->getType() == INT_ARRAY_TYPE) && (index->getType() == ARRAY_TYPE))) {
        node->setType(NO_TYPE);

    } else {
        printError("Incompatible types in statement_3", identifier);
        node->setType(ERROR_TYPE);
    }
}

//STATEMENT ::= { STATEMENTS }
void SemanticAnalyzer::typeCheckStatement_Block(Node *node) {
    Node *statements = node->getChild(0);
    analyze(statements);
    node->setType(NO_TYPE);
}

//STATEMENT ::= if ( EXP ) STATEMENT else STATEMENT
void SemanticAnalyzer::typeCheckStatement_If(Node *node) {
    Node *exp = node->getChild(0);
    Node *statement1 = node->getChild(1);
    Node *statement2 = node->getChild(2);

    analyze(exp);
    analyze(statement1);
    analyze(statement2);

    if (exp->getType() == ERROR_TYPE) {
        node->setType(ERROR_TYPE);
    } else {
        node->setType(NO_TYPE);
    }
}

//STATEMENT ::= while ( EXP ) STATEMENT)
void SemanticAnalyzer::typeCheckStatement_While(Node *node) {
    Node *exp = node->getChild(0);
    Node *statement = node->getChild(1);

    analyze(exp);
    analyze(statement);

    if (exp->getType() == ERROR_TYPE) {
        node->setType(ERROR_TYPE);
    } else {
        node->setType(NO_TYPE);
    }
}

//EXP ::= EXP2 OP_EXP
void SemanticAnalyzer::typeCheckExp(Node *node) {
    Node *exp2 = node->getChild(0);
    Node *op_exp = node->getChild(1);

    analyze(exp2);
    analyze(op_exp);

    if (op_exp->getType() == NO_TYPE) {
        node->setType(exp2->getType());

    } else if (exp2->getType() != op_exp->getType()) {
        node->setType(ERROR_TYPE);

    } else {
        node->setType(exp2->getType());
    }
}

//INDEX ::= [ EXP ]
void SemanticAnalyzer::typeCheckExp2(Node *node) {
    Node *exp = node->getChild(0);
    analyze(exp);
    node->setType(exp->getType());
}

//EXP2 ::= identifier INDEX
void SemanticAnalyzer::typeCheckExp2_2(Node *node) {
    Node *identifier = node->getChild(0);
    Node *index = node->getChild(1);

    analyze(index);

    if (identifier->getType() == NO_TYPE) {
        printError("Identifier not defined", identifier);
        node->setType(ERROR_TYPE);
    } else if (identifier->getType() == INT_TYPE
               && index->getType() == NO_TYPE) {
        node->setType(identifier->getType());
    } else if (identifier->getType() == INT_ARRAY_TYPE
               && index->getType() == ARRAY_TYPE) {
        node->setType(INT_TYPE);
    } else {
        printError("No primitive Type", 0L);
        node->setType(ERROR_TYPE);
    }
}

//EXP2 ::= integer
void SemanticAnalyzer::typeCheckExp2_3(Node *node) {
    node->setType(INT_TYPE);
}

//EXP2 ::= - EXP2
void SemanticAnalyzer::typeCheckExp2_4(Node *node) {
    Node *exp2 = node->getChild(0);
    analyze(exp2);
    node->setType(exp2->getType());
}

//EXP2 ::= ! EXP2
void SemanticAnalyzer::typeCheckExp2_5(Node *node) {
    Node *exp2 = node->getChild(0);

    analyze(exp2);

    if (exp2->getType() != INT_TYPE) {
        node->setType(ERROR_TYPE);
    } else {
        node->setType(INT_TYPE);
    }
}

//INDEX ::= [ EXP ]
void SemanticAnalyzer::typeCheckIndex(Node *node) {
    Node *exp = node->getChild(0);

    analyze(exp);

    if (exp->getType() == ERROR_TYPE) {
        node->setType(ERROR_TYPE);
    } else {
        node->setType(ARRAY_TYPE);
    }
}

//INDEX ::= e
void SemanticAnalyzer::typeCheckIndex_Empty(Node *node) {
    node->setType(NO_TYPE);
}

//OP_EXP ::= OP EXP
void SemanticAnalyzer::typeCheckOp_Exp(Node *node) {
    Node *op = node->getChild(0);
    Node *exp = node->getChild(1);

    analyze(op);
    analyze(exp);

    node->setType(exp->getType());
}

//OP_EXP ::= e
void SemanticAnalyzer::typeCheckOp_Exp_Empty(Node *node) {
    node->setType(NO_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Plus(Node *node) {
    node->setType(OP_PLUS_TYPE);
}


void SemanticAnalyzer::typeCheckOp_Minus(Node *node) {
    node->setType(OP_MINUS_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Mul(Node *node) {
    node->setType(OP_MULT_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Div(Node *node) {
    node->setType(OP_DIV_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Less(Node *node) {
    node->setType(OP_LESS_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Greater(Node *node) {
    node->setType(OP_GREATER_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Equal(Node *node) {
    node->setType(OP_EQUAL_TYPE);
}

void SemanticAnalyzer::typeCheckOp_Special(Node *node) {
    node->setType(OP_UN_EQUAL_TYPE);
}

void SemanticAnalyzer::typeCheckOp_And(Node *node) {
    node->setType(OP_AND_TYPE);
}

void SemanticAnalyzer::printError(string msg, Node *node = 0L) {
    if (node != 0L) {
        Token *token = node->getToken();
        cerr << RED << "Semantic ERROR: " << msg << " in line: "
             << token->getRow() << " column: " << token->getCol() << COLOR_RESET << endl;
    } else {
        cerr << RED << "Semantic ERROR: " << msg << COLOR_RESET << endl;
    }
}

void SemanticAnalyzer::analyze(Node *node) {
    switch (node->getRuleType()) {
        case PROG:
            typeCheckProg(node);
            break;
        case DECLS:
            typeCheckDecls(node);
            break;
        case DECLS_EMPTY:
            typeCheckDecls_Empty(node);
            break;
        case DECL:
            typeCheckDecl(node);
            break;
        case ARRAY:
            typeCheckArray(node);
            break;
        case ARRAY_EMPTY:
            typeCheckArray_Empty(node);
            break;
        case STATEMENTS:
            typeCheckStatements(node);
            break;
        case STATEMENTS_EMPTY:
            typeCheckStatements_Empty(node);
            break;
        case STATEMENT_IDENTIFIER:
            typeCheckStatement_Identifier(node);
            break;
        case STATEMENT_WRITE:
            typeCheckStatement_Write(node);
            break;
        case STATEMENT_READ:
            typeCheckStatement_Read(node);
            break;
        case STATEMENT_BLOCK:
            typeCheckStatement_Block(node);
            break;
        case STATEMENT_IF:
            typeCheckStatement_If(node);
            break;
        case STATEMENT_WHILE:
            typeCheckStatement_While(node);
            break;
        case EXP:
            typeCheckExp(node);
            break;
        case EXP2:
            typeCheckExp2(node);
            break;
        case EXP2_INBRACKETS:
            typeCheckExp2_2(node);
            break;
        case EXP2_IDENTIFIER:
            typeCheckExp2_3(node);
            break;
        case EXP2_INTEGER:
            typeCheckExp2_4(node);
            break;
        case EXP2_MINUS:
            typeCheckExp2_5(node);
            break;
        case INDEX:
            typeCheckIndex(node);
            break;
        case INDEX_EMPTY:
            typeCheckIndex_Empty(node);
            break;
        case OP_EXP:
            typeCheckOp_Exp(node);
            break;
        case OP_EXP_EMPTY:
            typeCheckOp_Exp_Empty(node);
            break;
        case OP_PLUS:
            typeCheckOp_Plus(node);
            break;
        case OP_MINUS:
            typeCheckOp_Minus(node);
            break;
        case OP_MUL:
            typeCheckOp_Mul(node);
            break;
        case OP_DIV:
            typeCheckOp_Div(node);
            break;
        case OP_LESS:
            typeCheckOp_Less(node);
            break;
        case OP_GREATER:
            typeCheckOp_Greater(node);
            break;
        case OP_EQUAL:
            typeCheckOp_Equal(node);
            break;
        case OP_SPECIAL:
            typeCheckOp_Special(node);
            break;
        case OP_AND:
            typeCheckOp_And(node);
            break;
        default:
            cerr << "node is empty" << endl;
    }
}
