# Visitor

Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates

## Partcipants

* __Visitor__:
  
  * declares a Visit operation for each class of ConcreteElement in the object structure. The operation's name and signature identifies the class that sends the Visit request to the visitor. That lets the visitor determine the concrete class of the element being visited. Then the visitor can access the element directly through its particular interface.
  
* __ConcreteVisitor__:

  * implements each operation declared by Visitor. Each operation implements a fragment of the algorithm defined for the corresponding class of object in the structure. ConcreteVisitor provides the context for the algorithm and store its local state. This state often accumulates results during the traversal of the structure.

* __Element__:

  * defines an Accept operation that takes a visitor as an argument.

* __ConcreteElement__:

  * implements an Accept operation that takes a visitor as an argument.

* __ObjectStructure__:

  * can enumerate its elements.
  
  * may provide a high-level interface to allow the visitor to visit its elements.
  
  * may either be a composite or a collection such as a list or a set.

## Structure

![Visitor](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/visitor.png)
