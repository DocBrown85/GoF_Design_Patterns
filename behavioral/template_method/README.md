# Template Method

Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without chaning the algorithm's structure.

## Partcipants

* __AbstractClass__:  
  
  * defines abstract __primitive operations__ that concrete subclasses define to implement steps of an algorithm.
  
  * implements a template method defining the skeleton of an algorithm. The template method calls primitive operations as well as operations defined in AbstractClass or those of other objects.

* __ConcreteClass__:
  
  * implements the primitive operations co carry out subclass-specific steps of the algorithm.

## Structure

![Template Method](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/template_method.png)
