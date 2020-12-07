# Abstract Factory

Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

## Participants

* __AbstractFactory__: declares an interface for operations that create abstract product objects.
* __ConcreteFactory__: implements the operations to create concrete objects.
* __AbstractProduct__: declares and interface for a type of product objects.
* __ConcreteProduct__: defines a product object to be created by the corrisponding concrete factory and implements the AbstractProduct interface.
* __Client__: uses only interfaces declared by AbstractFactory and AbstractProduct classes.

## Structure

![AbstractFactory](https://raw.githubusercontent.com/DocBrown85/cpp_design_patterns/master/images/abstract_factory.svg)
