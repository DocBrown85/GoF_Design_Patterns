# Builder

Separate the construction of a complex object from its representation so that the same construction process can create different representation.

## Participants

* __Builder__: specifies an abstract interface for creating parts of a Product object.
* __ConcreteBuilder__: constructs and assembles parts of the product by implementing the Builder interface. Defines and keeps track of the representation it creates. Provide an interface for retrieving the product.
* __Director__: constructs an object using the Builder interface.
* __Product__: represent the complex object under construction. ConcreteBuilder builds the product's internal representation and defines the process by which it's assembled. Includes classes that define the constituent parts, including interfaces for assembling the parts into the final result.

## Structure

![Builder](https://raw.githubusercontent.com/DocBrown85/cpp_design_patterns/master/images/builder.svg)
