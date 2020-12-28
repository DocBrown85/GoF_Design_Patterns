#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

namespace structural
{
    namespace bridge
    {
        class Implementor
        {
        public:
            virtual ~Implementor() {}
            virtual std::string operation_implementation() const = 0;
        };

        class ConcreteImplementorA : public Implementor
        {
        public:
            std::string operation_implementation() const override
            {
                return "ConcreteImplementorA operation implementation";
            }
        };

        class ConcreteImplementorB : public Implementor
        {
        public:
            std::string operation_implementation() const override
            {
                return "ConcreteImplementorB operation implementation";
            }
        };

        class Abstraction
        {
        protected:
            std::unique_ptr<Implementor> _implementor;

        public:
            Abstraction(std::unique_ptr<Implementor> implementor) : _implementor(std::move(implementor))
            {
            }

            virtual ~Abstraction() {}

            virtual std::string operation() const
            {
                return "Abstraction basic implementation using: " + _implementor->operation_implementation();
            }
        };

        class RefinedAbstraction : public Abstraction
        {
        public:
            RefinedAbstraction(std::unique_ptr<Implementor> implementor) : Abstraction(std::move(implementor)) {}

            std::string operation() const override
            {
                return "RefinedAbstraction implementation using: " + _implementor->operation_implementation();
            }
        };

        class Client
        {
        public:
            Client(std::unique_ptr<Abstraction> abstraction) : _abstraction(std::move(abstraction)) {}

            void set_abstraction(std::unique_ptr<Abstraction> abstraction)
            {
                _abstraction = std::move(abstraction);
            }

            void execute()
            {
                std::cout << _abstraction->operation() << "\n";
            }

        private:
            std::unique_ptr<Abstraction> _abstraction;
        };

    } // namespace bridge

} // namespace structural

int main()
{
    std::unique_ptr<structural::bridge::Implementor> concrete_implementor_a = std::make_unique<structural::bridge::ConcreteImplementorA>();
    std::unique_ptr<structural::bridge::Abstraction> abstraction = std::make_unique<structural::bridge::Abstraction>(std::move(concrete_implementor_a));
    structural::bridge::Client client(std::move(abstraction));
    client.execute();

    std::unique_ptr<structural::bridge::Implementor> concrete_implementor_b = std::make_unique<structural::bridge::ConcreteImplementorB>();
    std::unique_ptr<structural::bridge::Abstraction> refined_abstraction = std::make_unique<structural::bridge::RefinedAbstraction>(std::move(concrete_implementor_b));
    client.set_abstraction(std::move(refined_abstraction));
    client.execute();

    return 0;
}