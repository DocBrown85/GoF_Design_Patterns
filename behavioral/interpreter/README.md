# Interpreter

Given a language, define a representation for its grammar along with an interpreter that uses the reèresentation to interpret sentences in the language.

## Participants

* __AbstractExpression__:
  
  * declares an abstract Interpret operation that is common to all nodes in the abstract syntax tree.
  
* __TerminalExpression__:

  * implements an Interpret operation associated with terminal symbols in the grammar.
  
  * an instance is required for every terminal symbol in a sentence.

* __NonterminalExpression__:

  * one such class in required for every rule in the grammar R::= R_1 R_2 ... R_n.
  
  * maintains instance variables of type AbstractExpression for each of the symbols R_1 through R_n.

  * implements an Interpret operation for nonterminal symbols in the grammar. Interpret typically calls itself recursively on the variables representing R_1 through R_n.

* __Context__:

  * contains information that's global to the interpreter.

* __Client__:
  
  * builds (or is given) an abstract syntax tree representing a particular sentence in the language that the grammar defines. The abstract syntax tree is assembled from instances of NonterminalExpression and TerminalExpression classes.
  
  * invokes the Interpret operation.

## Structure

![Interpreter](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/interpreter.png)
