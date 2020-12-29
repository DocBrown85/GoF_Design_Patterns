# Composite

Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

## Participants

* __Component__: Declares the interface for objects in the composition. Implement default behavior for the interface common to all classes, as appropriate. Declares an interface for accessing and managing its child components. Optionally defines an interface for accessing a component's parent in the recursive structure, and implements it if that's appropriate.
* __Leaf__: Represent leaf objects in the composition. A leaf has no children. Also defines behavior for primitive objects in the composition.
* __Composite__: Defines behavior for components having children. Store child components. Implements child-related operations in the Component interface.
* __Client__: Manipulates objects in the composition through the Component interface.

## Structure

![Composite](https://raw.githubusercontent.com/DocBrown85/design_patterns/master/images/composite.svg)
