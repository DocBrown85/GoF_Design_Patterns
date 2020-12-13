# Factory Method

Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

## Participants

* __Product__: defines the interface of the objects the factory method creates
* __ConcreteProduct__: implements the Product interface
* __Creator__: declares the factory method, which returns an object of type Product. Creator may also define a default implementation of the factory method that returns a default ConcreteProduct object. May call the factory method to create a Product object
* __ConcreteCreator__: overrides the factory method to return an instance of a ConcreteProduct

## Structure

![Factory Method](https://raw.githubusercontent.com/DocBrown85/cpp_design_patterns/master/images/factory_method.svg)
