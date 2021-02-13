# Interpreter

Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

## Participants

* __Iterator__:

  * defines an interface for accessing and traversing elements.

* __ConcreteIterator__:

  * implements the Iterator interface.
  
  * keeps track of the current position in the traversal of the aggregate.

* __Aggregate__:

  * defines an interface for creating an Iterator object.

* __ConcreteAggregate__:

  * implements the Iterator creation interface to return an instance of the proper ConcreteIterator.

## Structure

![Iterator](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/iterator.png)
