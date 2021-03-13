# Strategy

Define a family of algorithms, encapsulate each one and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

## Partcipants

* __Strategy__:
  
  * declares an interface common to all supported algorithms. Context uses this interface to call the algorithm defined by ConcreteStrategy.

* __ConcreteStrategy__:
  
  * implements the algorithm using Strategy interface.

* __Context__:

  * is configured with a ConcreteStrategy object.
  
  * maintains a reference to a Strategy object.
  
  * may define an interface that lets Strategy access its data.  

## Structure

![Strategy](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/strategy.png)
