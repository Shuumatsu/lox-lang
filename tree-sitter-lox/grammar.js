module.exports = grammar({
    name: 'lox',

    rules: {
        expression: ($) => choice($.identifier, $.literal, $.unary_expression, $.binary_expression, $.grouping),

        identifier: ($) => /[a-z_]+/,

        literal: ($) => choice($.number, $.string, 'true', 'false', 'nil'),
        number: ($) => /\d+(\.\d+)?/,
        string: ($) => /"([^"\\]|\\.)*"/,

        grouping: ($) => seq('(', $.expression, ')'),

        unary_expression: ($) => prec(3, choice(seq('-', $.expression), seq('!', $.expression))),

        binary_expression: ($) =>
            choice(
                prec.left(2, seq($.expression, '*', $.expression)),
                prec.left(2, seq($.expression, '/', $.expression)),
                prec.left(1, seq($.expression, '+', $.expression)),
                prec.left(1, seq($.expression, '-', $.expression))
            ),
    },
})
