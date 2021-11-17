import Parser from 'tree-sitter'
// @ts-ignore
import language from 'tree-sitter-lox'
import { Command } from 'commander'
import fs from 'fs/promises'
import { translate } from './ast'

const program = new Command()
program.version('0.0.1')
program.option('-f, --file <file>', 'file to interpret')

program.parse(process.argv)

const options = program.opts()

const main = async () => {
    const sourceCode = await fs.readFile(options.file, 'utf8')

    const parser = new Parser()
    parser.setLanguage(language)

    const tree = parser.parse(sourceCode)
    const root = tree.rootNode

    console.log(root)

    console.log(translate(root))
}

main()
