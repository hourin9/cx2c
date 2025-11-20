#include <exprs.hh>
#include <codegen.hh>

int main(void)
{
        Expr expr(
                AssignExpr(
                        Identifier("hello"),
                        std::make_unique<Expr>(ConstLiteral(123.4))
                )
        );

        CCodeGenResult res = expr_codegen(expr);

        return 0;
}

