#include <codegen.hh>

#include <cstdint>

#include <string>
#include <variant>

#include <enums.hh>
#include <exprs.hh>
#include <shorthands.hh>

String LiteralCodeGen::operator()(int64_t i64)
{
        return std::to_string(i64);
}

String LiteralCodeGen::operator()(double f64)
{
        return std::to_string(f64);
}

String LiteralCodeGen::operator()(const String &str)
{
        return "\"" + str + "\"";
}

String literal_codegen(const ConstLiteral &lit)
{
        return std::visit(LiteralCodeGen{}, lit);
}

String unary_to_string(UnaryOperations op)
{
        switch (op) {
        case UnaryOperations::Not:
                return "!";
        case UnaryOperations::Deref:
                return "*";
        case UnaryOperations::Ref:
                return "&";
        }
}

String binary_to_string(BinaryOperations op)
{
        switch (op) {
        case BinaryOperations::Add:
                return "+";
        case BinaryOperations::Sub:
                return "-";
        case BinaryOperations::Mul:
                return "*";
        case BinaryOperations::Div:
                return "/";

        case BinaryOperations::Eq:
                return "==";
        case BinaryOperations::Neq:
                return "!=";
        case BinaryOperations::Gr:
                return ">";
        case BinaryOperations::Gre:
                return ">=";
        case BinaryOperations::Le:
                return "<";
        case BinaryOperations::Lee:
                return "<=";
        }
}

