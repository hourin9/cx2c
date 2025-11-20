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
        CCodeGenResult val = expr_codegen(*expr.expr);
        CExpr cexpr = unary_to_string(expr.op) + val.expr;
        return {cexpr, val.stmts};
}

CCodeGenResult CodeGen::operator()(const BinaryExpr &expr)
{
        CCodeGenResult lhs = expr_codegen(*expr.lhs);
        CCodeGenResult rhs = expr_codegen(*expr.rhs);
        CExpr cexpr = "(" + lhs.expr + binary_to_string(expr.op)
                + rhs.expr + ")";
        Vec<CStmt> stmts = lhs.stmts;
        stmts.insert(stmts.end(), rhs.stmts.begin(), rhs.stmts.end());
        return {cexpr, stmts};
}

CCodeGenResult expr_codegen(const Expr &expr)
{
        return std::visit(CodeGen{}, expr.v);
}

