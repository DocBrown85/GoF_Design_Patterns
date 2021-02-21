# Mediator

Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.

## Partcipants

* __Mediator__:
  
  * defines an interface for communicating with Collegue objects.

* __ConcreteMediator__:

  * implements cooperative behavior by coordinating Collegue objects.
  
  * knows and maintains its collegues.

* __Collegue classes__:

  * each Collegue class knows its Mediator object.
  
  * each collegue communicates with its mediator whenever it would have otherwise communicated with another collegue.

## Structure

![Mediator](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/mediator.png)
