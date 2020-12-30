#include <cstring>
#include <iostream>
#include <memory>

namespace structural
{
    namespace decorator
    {
        class Component
        {
        public:
            virtual ~Component() {}
            virtual std::string operation() const = 0;
        };

        class ConcreteComponent : public Component
        {
        public:
            std::string operation() const override
            {
                return "ConcreteComponent";
            }
        };

        class Decorator : public Component
        {
        public:
            Decorator(std::unique_ptr<Component> component) : _component(std::move(component))
            {
            }

            std::string operation() const override
            {
                return _component->operation();
            }

        protected:
            std::unique_ptr<Component> _component;
        };

        class ConcreteDecoratorA : public Decorator
        {
        public:
            ConcreteDecoratorA(std::unique_ptr<Component> component) : Decorator(std::move(component))
            {
            }
            std::string operation() const override
            {
                return "ConcreteDecoratorA(" + _component->operation() + ")";
            }
        };

        class ConcreteDecoratorB : public Decorator
        {
        public:
            ConcreteDecoratorB(std::unique_ptr<Component> component) : Decorator(std::move(component))
            {
            }
            std::string operation() const override
            {
                return "ConcreteDecoratorB(" + _component->operation() + ")";
            }
        };

        class Client
        {
        public:
            void execute(std::unique_ptr<Component> const &component)
            {
                std::cout << component->operation() << "\n";
            }
        };

    } // namespace decorator

} // namespace structural

int main()
{
    structural::decorator::Client client;

    std::unique_ptr<structural::decorator::Component> simple_component = std::make_unique<structural::decorator::ConcreteComponent>();
    std::cout << "Calling Client with a not decorated component:\n";
    client.execute(simple_component);
    std::cout << "\n\n";

    std::unique_ptr<structural::decorator::Component> decorator1 = std::make_unique<structural::decorator::ConcreteDecoratorA>(std::move(simple_component));
    std::unique_ptr<structural::decorator::Component> decorator2 = std::make_unique<structural::decorator::ConcreteDecoratorB>(std::move(decorator1));
    std::cout << "Calling Client with a decorated component:\n";
    client.execute(decorator2);
    std::cout << "\n";

    return 0;
}