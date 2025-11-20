#include <cstdint>

#include <exprs.hh>
#include <ir.hh>
#include <shorthands.hh>

struct LiteralCodeGen {
        String operator()(int64_t);
        String operator()(double);
        String operator()(const String&);
};

String literal_codegen(const ConstLiteral&);

struct CodeGen {
        CCodeGenResult operator()(const None&);
        CCodeGenResult operator()(const ConstLiteral&);
        CCodeGenResult operator()(const AssignExpr&);
        CCodeGenResult operator()(const UnaryExpr&);
        CCodeGenResult operator()(const BinaryExpr&);
};

CCodeGenResult expr_codegen(const Expr&);

