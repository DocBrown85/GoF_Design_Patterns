# Flyweight

Use sharing to support large numbers of fine-grained objects efficiently.

## Participants

* __Flyweight__: declare an interface through which flyweights can receive and act on extrinsic state.
* __ConcreteFlyweight__: implements the Flyweight interface and add storage for intrinsic state, if any. Any state it stores must be intrinsic; that is, it must be independent of the ConcreteFlyweight object's context.
* __UnsharedConcreteFlyweight__: not all Flyweight subclasses need to be shared. The Flyweight interface enables sharing; it doesn't enforce it. It's common for UnsharedConcreteFlyweight objects to have ConcreteFlyweight objects ad children at some level in the flyweight object structure.
* __FlyweightFactory__: creates and manage flyweight objects. Ensures that flyweights are shared properly. When a client requests a flyweight, the FlyweightFactory objects supplies an existing instance or creates one, if none exists.
* __Client__: maintains a reference to flyweight(s) and computes or stores the extrinsic state of flyweight(s).

## Structure

![Flyweight](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/flyweight.png)
