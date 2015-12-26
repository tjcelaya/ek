#include "mpc/mpc.h"

#define P(R, r) mpc_parser_t *R = mpc_new(r);
#define mpcP(R, r) mpc_parser_t *R = r();

int main(int argc, char **argv) {

#define PARSERS NL, SPACE, Ident, Expr, Pair, List, Fn, Tag, Sym, Rule, Prog

  P(NL, "NL")
  P(SPACE, "SPACE")
  P(Ident, "ident")
  P(Expr, "expr")
  P(Pair, "pair")
  P(List, "list")
  P(Fn, "fn")
  P(Tag, "tag")
  P(Sym, "sym")
  P(Rule, "rule")
  P(Prog, "prog")

  mpca_lang_contents(MPCA_LANG_WHITESPACE_SENSITIVE, "ek.grammar",
    PARSERS, NULL);

  mpc_result_t r;
  if (argc > 1) {
    if (mpc_parse_contents(argv[1], Prog, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }
  }

  mpc_cleanup(11,
    PARSERS, NULL);

  return 0;
}
