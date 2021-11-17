module.exports = grammar({
    name: 'lox',

    rules: {
        expression: $ =>
            choice(
                $.literal,
                $.unary_expression,
                $.binary_expression,
                $.grouping
            ),

        number: $ => /\d+(\.\d+)?/,
        string: $ => /"([^"\\]|\\.)*"/,
        literal: $ => choice($.number, $.string, 'true', 'false', 'nil'),

        grouping: $ => seq('(', $.expression, ')'),

        unary_expression: $ =>
            prec(3, choice(seq('-', $.expression), seq('!', $.expression))),

        binary_expression: $ =>
            choice(
                prec.left(2, seq($.expression, '*', $.expression)),
                prec.left(2, seq($.expression, '/', $.expression)),
                prec.left(1, seq($.expression, '+', $.expression)),
                prec.left(1, seq($.expression, '-', $.expression))
            )
    }
})
