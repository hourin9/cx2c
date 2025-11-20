#include <codegen.hh>

#include <variant>

#include <enums.hh>
#include <exprs.hh>
#include <ir.hh>
#include <shorthands.hh>

CCodeGenResult CodeGen::operator()(const None &_)
{
        return {};
}

CCodeGenResult CodeGen::operator()(const ConstLiteral &cl)
{
        return {literal_codegen(cl), {}};
}

CCodeGenResult CodeGen::operator()(const AssignExpr &expr)
{
        CCodeGenResult rhs = expr_codegen(*expr.expr);
        CStmt assign = CStmt::assign(expr.tgt.name, rhs.expr);
        CCodeGenResult code {"", rhs.stmts};
        code.stmts.emplace_back(assign);
        return code;
}

CCodeGenResult CodeGen::operator()(const UnaryExpr &expr)
{
        (void)expr;
        return {};
}

CCodeGenResult CodeGen::operator()(const BinaryExpr &expr)
{
        (void)expr;
        return {};
}

CCodeGenResult expr_codegen(const Expr &expr)
{
        return std::visit(CodeGen{}, expr.v);
}

