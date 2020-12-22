# Adapter

Convert the interface of a class into another interface client expects. Adapter lets class work together that couldn't otherwise because of incompatible interfaces.

## Participants

* __Target__: defines the domain-specific interface that Client uses.
* __Client__: collaborates with objects conforming to the Target interface.
* __Adaptee__: defines an existing interface that needs adapting.
* __Adapter__: adapts the interface of Adaptee to the Target interface.

## Structure

![Adapter](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/adapter.jpg)
