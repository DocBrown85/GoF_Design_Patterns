#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

namespace creational
{
    namespace abstract_factory
    {

        class AbstractProductA
        {
        public:
            virtual ~AbstractProductA(){};
            virtual std::string usefulMethod() const = 0;
        };

        class ConcreteProductA1 : public AbstractProductA
        {
            std::string usefulMethod() const override
            {
                return "Useful Method Implementation A1";
            }
        };

        class ConcreteProductA2 : public AbstractProductA
        {
            std::string usefulMethod() const override
            {
                return "Useful Method Implementation A2";
            }
        };

        class AbstractProductB
        {
        public:
            virtual ~AbstractProductB(){};
            virtual std::string usefulMethod() const = 0;
        };

        class ConcreteProductB1 : public AbstractProductB
        {
            std::string usefulMethod() const override
            {
                return "Useful Method Implementation B1";
            }
        };

        class ConcreteProductB2 : public AbstractProductB
        {
            std::string usefulMethod() const override
            {
                return "Useful Method Implementation B2";
            }
        };

        class AbstractFactory
        {
        public:
            virtual ~AbstractFactory() {}
            virtual std::shared_ptr<AbstractProductA> getProductA() const = 0;
            virtual std::shared_ptr<AbstractProductB> getProductB() const = 0;
        };

        class ConcreteFactory1 : public AbstractFactory
        {
        public:
            std::shared_ptr<AbstractProductA> getProductA() const override
            {
                return std::make_shared<ConcreteProductA1>();
            }

            std::shared_ptr<AbstractProductB> getProductB() const override
            {
                return std::make_shared<ConcreteProductB1>();
            }
        };

        class ConcreteFactory2 : public AbstractFactory
        {
        public:
            std::shared_ptr<AbstractProductA> getProductA() const override
            {
                return std::make_shared<ConcreteProductA2>();
            }

            std::shared_ptr<AbstractProductB> getProductB() const override
            {
                return std::make_shared<ConcreteProductB2>();
            }
        };

        class Client
        {
        public:
            Client() {}

            void setFactory(std::shared_ptr<AbstractFactory> factory)
            {
                _factory = factory;
            }

            void execute()
            {
                const std::shared_ptr<AbstractProductA> product_a = _factory->getProductA();
                const std::shared_ptr<AbstractProductB> product_b = _factory->getProductB();
                std::cout << product_a->usefulMethod() << "\n";
                std::cout << product_b->usefulMethod() << "\n";
            }

        private:
            std::shared_ptr<AbstractFactory> _factory;
        };

    } // namespace abstract_factory

} // namespace creational

int main()
{
    creational::abstract_factory::Client client;

    std::cout << "Setting up Client with ConcreteFactory1:\n";
    std::shared_ptr<creational::abstract_factory::ConcreteFactory1> concreteFactory1 = std::make_shared<creational::abstract_factory::ConcreteFactory1>();
    client.setFactory(concreteFactory1);
    client.execute();

    std::cout << std::endl;
    std::cout << "Setting up Client with ConcreteFactory2:\n";
    std::shared_ptr<creational::abstract_factory::ConcreteFactory2> concreteFactory2 = std::make_shared<creational::abstract_factory::ConcreteFactory2>();
    client.setFactory(concreteFactory2);
    client.execute();

    return 0;
}