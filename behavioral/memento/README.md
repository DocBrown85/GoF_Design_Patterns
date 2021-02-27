# Memento

Without breaking encapsulation, capture and externalize an object's internal state so that the object can be restored to this state later.

## Partcipants

* __Memento__:
  
  * store internal state of the Originator object. The memento may store as much or as little of the originator's internal state as necessary at its originator's discretion.
  
  * protects against access by objects other than the originator. Mementos have effectively two interfaces. Caretaker sees a **narrow** interface to the Memento - it can only pass the memento to othe objects. Originator, in contrast, see a **wide** interface, one that lets it access all the data necessary to restore itself to its previous state. Ideally, only the originator that produced the memento would be permitted to access the memento's internal state.

* __Originator__:

  * creates a memento containing a snapshot of its current internal state.
  
  * uses the memento to restore its internal state.

* __Caretaker__:

  * is responsible for the memento's safekeeping.
  
  * never operates on or examines the contents of the memento.

## Structure

![Memento](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/memento.png)
