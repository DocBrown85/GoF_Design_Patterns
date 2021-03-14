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
            virtual void accept(const std::unique_ptr<Visitor> &visitor) const = 0;
        };

        class ConcreteComponentA : public Component
        {
        public:
            void accept(const std::unique_ptr<Visitor> &visitor) const override
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
            void accept(const std::unique_ptr<Visitor> &visitor) const override
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
                std::array<std::unique_ptr<Component>, 2> components = {
                    std::make_unique<ConcreteComponentA>(),
                    std::make_unique<ConcreteComponentB>()};

                std::unique_ptr<Visitor> visitor1 = std::make_unique<ConcreteVisitor1>();
                apply_visitor(components, visitor1);

                std::unique_ptr<Visitor> visitor2 = std::make_unique<ConcreteVisitor2>();
                apply_visitor(components, visitor2);
            }

            void apply_visitor(const std::array<std::unique_ptr<Component>, 2> &components,
                               const std::unique_ptr<Visitor> &visitor)
            {
                for (const std::unique_ptr<Component> &comp : components)
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