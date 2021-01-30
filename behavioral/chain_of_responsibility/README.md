# Chain of Responsibility

Avoid coupling the sender and of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

## Participants

* __Handler__:

  * defines and interface for handling requests.
  
  * implements the successor link (optional).
  
* __Concrete Handler__:

  * handles request it is responsible for.
  
  * can access its successor.
  
  * if the ConcreteHandler can handle the request, it does so, otherwise it forwards the request to its successor.
  
* __Client__:

  * initiates the request co a ConcreteHandler object on the chain.

## Structure

![Chain of Responsibility](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/chain_of_responsibility.png)
