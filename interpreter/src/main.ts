import Parser from 'tree-sitter'
import language from 'tree-sitter-lox'

const main = async () => {
    await Parser.init()

    const parser = new Parser()
    parser.setLanguage(language)


}

main()

