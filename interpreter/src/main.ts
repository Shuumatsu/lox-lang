import Parser from 'tree-sitter'
import language from 'tree-sitter-lox'
import { Command } from 'commander'
import fs from 'fs/promises'
import getStdin from 'get-stdin'

const program = new Command()
program.version('0.0.1')
program.option('-f, --file [file]', 'file to interpret')

program.parse(process.argv)

const options = program.opts()

const main = async () => {
    const sourceCode = await (options.file ? fs.readFile(options.file, 'utf8') : getStdin())

    const parser = new Parser()
    parser.setLanguage(language)

    const tree = parser.parse(sourceCode)

    console.log(tree)
}

main()
