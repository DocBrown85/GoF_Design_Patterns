# Command

Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

## Participants

* __Command__:

  * declares an interface for executing an operation.

* __ConcreteCommand__:

  * defines a binding between a Receiver object and an action.
  
  * implements Execute by invoking the corresponding operations on Receiver.

* __Client__:

  * creates a ConcreteCommand object and sets its receiver.

* __Invoker__:

  * asks the command to carry out the request.

* __Receiver__:

  * knows how to perform the operations associated with carrying out a request. ANy class may serve as a Receiver.  

## Structure

![Command](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/command.png)
