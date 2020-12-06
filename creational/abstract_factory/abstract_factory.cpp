#include <cstring>
#include <iostream>

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
            virtual AbstractProductA *getProductA() const = 0;
            virtual AbstractProductB *getProductB() const = 0;
        };

        class ConcreteFactory1 : public AbstractFactory
        {
        public:
            AbstractProductA *getProductA() const override
            {
                return new ConcreteProductA1();
            }

            AbstractProductB *getProductB() const override
            {
                return new ConcreteProductB1();
            }
        };

        class ConcreteFactory2 : public AbstractFactory
        {
        public:
            AbstractProductA *getProductA() const override
            {
                return new ConcreteProductA2();
            }

            AbstractProductB *getProductB() const override
            {
                return new ConcreteProductB2();
            }
        };

        class Client
        {
        public:
            Client() {}

            void setFactory(AbstractFactory *factory)
            {
                _factory = factory;
            }

            void execute()
            {
                const AbstractProductA *product_a = _factory->getProductA();
                const AbstractProductB *product_b = _factory->getProductB();
                std::cout << product_a->usefulMethod() << "\n";
                std::cout << product_b->usefulMethod() << "\n";
                delete product_a;
                delete product_b;
            }

        private:
            AbstractFactory *_factory;
        };

    } // namespace abstract_factory

} // namespace creational

int main()
{
    creational::abstract_factory::Client client;

    std::cout << "Setting up Client with ConcreteFactory1:\n";
    creational::abstract_factory::ConcreteFactory1 *concreteFactory1 = new creational::abstract_factory::ConcreteFactory1();
    client.setFactory(concreteFactory1);
    client.execute();
    delete concreteFactory1;

    std::cout << std::endl;
    std::cout << "Setting up Client with ConcreteFactory2:\n";
    creational::abstract_factory::ConcreteFactory2 *concreteFactory2 = new creational::abstract_factory::ConcreteFactory2();
    client.setFactory(concreteFactory1);
    client.execute();
    delete concreteFactory2;

    return 0;
}