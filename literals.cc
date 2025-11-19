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

