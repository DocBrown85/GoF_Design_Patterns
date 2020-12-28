# Bridge

Decouple an abstraction from its implementation so that the two can vary independently.

## Participants

* __Abstraction__: Defines the abstraction interface and maintains a reference to an object of type Implementor
* __RefinedAbstraction__: Extends the interface defined by Abstraction
* __Implementor__: Defines the interface for implementation classes. This interface doesn't have to correspond exactly to Abstraction's interface; in fact the two interfaces can be quite different. Typically the Implementor interface provides only primitive operations, and Abstraction defines higher-level operations based on this primitives
* __ConcreteImplementor__: implements the Implementor's interface and defines its concrete implementation

## Structure

![Bridge](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/bridge.svg)
