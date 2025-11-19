#include <codegen.hh>

#include <variant>

#include <enums.hh>
#include <exprs.hh>
#include <shorthands.hh>

String CodeGen::operator()(const None &_)
{
        return "";
}

String CodeGen::operator()(const ConstLiteral &cl)
{
        return std::visit(LiteralCodeGen{}, cl);
}

String CodeGen::operator()(const AssignExpr &expr)
{
        String code = expr.tgt.name + " = ";
        code += expr_codegen(*expr.expr) + ";";
        return code;
}

String CodeGen::operator()(const UnaryExpr &expr)
{
        (void)expr;
        return "TODO";
}

String CodeGen::operator()(const BinaryExpr &expr)
{
        (void)expr;
        return "TODO";
}

String expr_codegen(const Expr &expr)
{
        return std::visit(CodeGen{}, expr.v);
}

