#include <cstring>
#include <iostream>
#include <list>
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
            Decorator(std::shared_ptr<Component> component) : _component(component)
            {
            }

            std::string operation() const override
            {
                return _component->operation();
            }

        protected:
            std::shared_ptr<Component> _component;
        };

        class ConcreteDecoratorA : public Decorator
        {
        public:
            ConcreteDecoratorA(std::shared_ptr<Component> component) : Decorator(component)
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
            ConcreteDecoratorB(std::shared_ptr<Component> component) : Decorator(component)
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
            void execute(std::shared_ptr<Component> component)
            {
                std::cout << component->operation() << "\n";
            }
        };

    } // namespace decorator

} // namespace structural

int main()
{
    structural::decorator::Client client;

    std::shared_ptr<structural::decorator::Component> simple_component = std::make_shared<structural::decorator::ConcreteComponent>();
    std::cout << "Calling Client with a not decorated component:\n";
    client.execute(simple_component);
    std::cout << "\n\n";

    std::shared_ptr<structural::decorator::Component> decorator1 = std::make_shared<structural::decorator::ConcreteDecoratorA>(simple_component);
    std::shared_ptr<structural::decorator::Component> decorator2 = std::make_shared<structural::decorator::ConcreteDecoratorB>(decorator1);
    std::cout << "Calling Client with a decorated component:\n";
    client.execute(decorator2);
    std::cout << "\n";

    return 0;
}