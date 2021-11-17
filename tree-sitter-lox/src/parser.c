#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 14
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 18
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_number = 1,
  sym_string = 2,
  anon_sym_true = 3,
  anon_sym_false = 4,
  anon_sym_nil = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  anon_sym_DASH = 8,
  anon_sym_BANG = 9,
  anon_sym_STAR = 10,
  anon_sym_SLASH = 11,
  anon_sym_PLUS = 12,
  sym_expression = 13,
  sym_literal = 14,
  sym_grouping = 15,
  sym_unary_expression = 16,
  sym_binary_expression = 17,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_number] = "number",
  [sym_string] = "string",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_nil] = "nil",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DASH] = "-",
  [anon_sym_BANG] = "!",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PLUS] = "+",
  [sym_expression] = "expression",
  [sym_literal] = "literal",
  [sym_grouping] = "grouping",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_number] = sym_number,
  [sym_string] = sym_string,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_nil] = anon_sym_nil,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [sym_expression] = sym_expression,
  [sym_literal] = sym_literal,
  [sym_grouping] = sym_grouping,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nil] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_grouping] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      if (lookahead == '!') ADVANCE(23);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '(') ADVANCE(20);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == '*') ADVANCE(24);
      if (lookahead == '+') ADVANCE(26);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '/') ADVANCE(25);
      if (lookahead == 'f') ADVANCE(2);
      if (lookahead == 'n') ADVANCE(5);
      if (lookahead == 't') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(16);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 5:
      if (lookahead == 'i') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'l') ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == 's') ADVANCE(4);
      END_STATE();
    case 10:
      if (lookahead == 'u') ADVANCE(3);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 12:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_nil);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_nil] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
  },
  [1] = {
    [sym_expression] = STATE(12),
    [sym_literal] = STATE(7),
    [sym_grouping] = STATE(7),
    [sym_unary_expression] = STATE(7),
    [sym_binary_expression] = STATE(7),
    [sym_number] = ACTIONS(3),
    [sym_string] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(3),
    [anon_sym_false] = ACTIONS(3),
    [anon_sym_nil] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(7),
  },
  [2] = {
    [sym_expression] = STATE(13),
    [sym_literal] = STATE(7),
    [sym_grouping] = STATE(7),
    [sym_unary_expression] = STATE(7),
    [sym_binary_expression] = STATE(7),
    [sym_number] = ACTIONS(3),
    [sym_string] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(3),
    [anon_sym_false] = ACTIONS(3),
    [anon_sym_nil] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(7),
  },
  [3] = {
    [sym_expression] = STATE(8),
    [sym_literal] = STATE(7),
    [sym_grouping] = STATE(7),
    [sym_unary_expression] = STATE(7),
    [sym_binary_expression] = STATE(7),
    [sym_number] = ACTIONS(3),
    [sym_string] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(3),
    [anon_sym_false] = ACTIONS(3),
    [anon_sym_nil] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(7),
  },
  [4] = {
    [sym_expression] = STATE(10),
    [sym_literal] = STATE(7),
    [sym_grouping] = STATE(7),
    [sym_unary_expression] = STATE(7),
    [sym_binary_expression] = STATE(7),
    [sym_number] = ACTIONS(3),
    [sym_string] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(3),
    [anon_sym_false] = ACTIONS(3),
    [anon_sym_nil] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(7),
  },
  [5] = {
    [sym_expression] = STATE(11),
    [sym_literal] = STATE(7),
    [sym_grouping] = STATE(7),
    [sym_unary_expression] = STATE(7),
    [sym_binary_expression] = STATE(7),
    [sym_number] = ACTIONS(3),
    [sym_string] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(3),
    [anon_sym_false] = ACTIONS(3),
    [anon_sym_nil] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(9), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [9] = 1,
    ACTIONS(11), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [18] = 1,
    ACTIONS(13), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [27] = 1,
    ACTIONS(15), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [36] = 2,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(17), 4,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
  [47] = 1,
    ACTIONS(17), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [56] = 3,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(23), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [68] = 3,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(23), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 9,
  [SMALL_STATE(8)] = 18,
  [SMALL_STATE(9)] = 27,
  [SMALL_STATE(10)] = 36,
  [SMALL_STATE(11)] = 47,
  [SMALL_STATE(12)] = 56,
  [SMALL_STATE(13)] = 68,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grouping, 3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [21] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_lox(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
