#pragma once

#include <shorthands.hh>

using CExpr = String;

struct CStmt {
        enum class Type {
                Expr,
                Assign,
                Declare,
                Return,
        };
        Type t;

        String lhs;
        CExpr rhs;
        String ret_type;

        static CStmt expr(CExpr e)
        {
                return { Type::Expr, "", e, "" };
        }

        static CStmt assign(String lhs, CExpr rhs)
        {
                return { Type::Assign, lhs, rhs, "" };
        }

        static CStmt declare(String lhs, CExpr rhs)
        {
                return { Type::Declare, lhs, rhs, "" };
        }

        static CStmt ret(CExpr e)
        {
                return { Type::Return, "", e, "" };
        }
};

struct CBlock {
        Vec<CStmt> sts;

        void add(CStmt st)
        {
                sts.emplace_back(std::move(st));
        }
};

struct CFunc {
        String name, ret_type;
        Vec<std::pair<String, String>> params;
        CBlock body;
};

struct CCodeGenResult {
        // This might grow, so I figure I should put this in
        // a struct for later.
        CExpr expr;     // For things like ConstLiteral
        Vec<CStmt> stmts;
};

