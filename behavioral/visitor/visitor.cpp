#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <array>

namespace behavioral
{
    namespace visitor
    {
        class ConcreteComponentA;
        class ConcreteComponentB;

        class Visitor
        {
        public:
            virtual void visit_concrete_component_a(const ConcreteComponentA *element) const = 0;
            virtual void visit_concrete_component_b(const ConcreteComponentB *element) const = 0;
        };

        class Component
        {
        public:
            virtual ~Component() {}
            virtual void accept(Visitor *visitor) const = 0;
        };

        class ConcreteComponentA : public Component
        {
        public:
            void accept(Visitor *visitor) const override
            {
                visitor->visit_concrete_component_a(this);
            }

            std::string special_method_of_concrete_component_a() const
            {
                return "ConcreteComponentA";
            }
        };

        class ConcreteComponentB : public Component
        {
        public:
            void accept(Visitor *visitor) const override
            {
                visitor->visit_concrete_component_b(this);
            }

            std::string special_method_of_concrete_component_b() const
            {
                return "ConcreteComponentB";
            }
        };

        class ConcreteVisitor1 : public Visitor
        {
        public:
            void visit_concrete_component_a(const ConcreteComponentA *element) const override
            {
                std::cout << "ConcreteVisitor1: " << element->special_method_of_concrete_component_a() << "\n";
            }

            void visit_concrete_component_b(const ConcreteComponentB *element) const override
            {
                std::cout << "ConcreteVisitor1: " << element->special_method_of_concrete_component_b() << "\n";
            }
        };

        class ConcreteVisitor2 : public Visitor
        {
        public:
            void visit_concrete_component_a(const ConcreteComponentA *element) const override
            {
                std::cout << "ConcreteVisitor2: " << element->special_method_of_concrete_component_a() << "\n";
            }
            void visit_concrete_component_b(const ConcreteComponentB *element) const override
            {
                std::cout << "ConcreteVisitor2: " << element->special_method_of_concrete_component_b() << "\n";
            }
        };

        class Client
        {
        public:
            void execute()
            {
                std::array<const Component *, 2> components = {new ConcreteComponentA, new ConcreteComponentB};

                ConcreteVisitor1 *visitor1 = new ConcreteVisitor1;
                apply_visitor(components, visitor1);

                ConcreteVisitor2 *visitor2 = new ConcreteVisitor2;
                apply_visitor(components, visitor2);

                for (const Component *comp : components)
                {
                    delete comp;
                }
                delete visitor1;
                delete visitor2;
            }

            void apply_visitor(std::array<const Component *, 2> components, Visitor *visitor)
            {
                for (const Component *comp : components)
                {
                    comp->accept(visitor);
                }
            }
        };

    } // namespace visitor

} // namespace behavioral

int main()
{
    behavioral::visitor::Client client;

    client.execute();

    return 0;
}