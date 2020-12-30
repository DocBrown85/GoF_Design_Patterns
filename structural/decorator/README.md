# Decorator

Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

## Participants

* __Component__: Defines the interface for objects that can have responsibilities added to them dynamically.
* __ConcreteComponent__: Defines an object to which additional responsibilities can be added.
* __Decorator__: maintains a reference to a Component object and defines an interface that conforms to Component's interface.
* __ConcreteDecorator__: adds responsibilities to the component.

## Structure

![Decorator](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/decorator.svg)
