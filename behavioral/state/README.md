# State

Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

## Partcipants

* __Context__:
  
  * defines the interface of interest to clients.
  
  * maintains an instance of a ConcreteState subclass that defines the current state.

* __State__:
  
  * defines an interface for encapsulating the behavior associated with a particular state of Context.

* __ConcreteState subclasses__:

  * each subclass implements a behavior associated with a state of the Context.

## Structure

![State](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/state.png)
