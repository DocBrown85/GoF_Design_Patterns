# Observer

Define a one-to-many dependency between objects so that when one object chanhes state, all its dependents are notified and updted automatically.

## Partcipants

* __Subject__:
  
  * knows its observers. Any number of Observer objects may observe a subject.
  
  * provides an interface for attaching and detaching Observer objects.

* __Observer__:

  * defines an updating interface for objects that should be notified of changes in a Subject.
  
* __ConcreteSubject__:

  * stores a state of interest to ConcreteObserver objects.
  
  * sends notification to its observers when its state changes.

* __ConcreteObserver__:

  * maintains a reference to a ConcreteSubject object.
  
  * stores state that should stay consistent with the subject's.
  
  * implements the Observer updating interface to keep its state consistent with the subject's.

## Structure

![Observer](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/observer.png)
