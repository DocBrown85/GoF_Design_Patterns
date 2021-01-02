# Facade

Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

## Participants

* __Facade__: Knows which subsystem classes are responsible for a request. Delegates client requests to appropriate subsystem objects.
* __subsystem classes__: Implement subsystem functionality. Handle work assigned to the Facade object. Have no knowledge of the facade by keeping no references to it.

## Structure

![Facade](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/facade.svg)
