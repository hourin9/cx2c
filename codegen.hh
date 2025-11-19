#include <cstdint>

#include <exprs.hh>
#include <shorthands.hh>

struct LiteralCodeGen {
        String operator()(int64_t);
        String operator()(double);
        String operator()(const String&);
};

struct CodeGen {
        String operator()(const None&);
        String operator()(const ConstLiteral&);
        String operator()(const AssignExpr&);
        String operator()(const UnaryExpr&);
        String operator()(const BinaryExpr&);
};

