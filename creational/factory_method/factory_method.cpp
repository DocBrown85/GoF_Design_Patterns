#include <cstring>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

namespace creational
{
    namespace factory_method
    {
        class Product
        {
        public:
            virtual ~Product() {}
            virtual std::string operation() const = 0;
        };

        class ConcreteProductA : public Product
        {
        public:
            std::string operation() const override
            {
                return "<<ConcreteProductA>> operation";
            }
        };

        class ConcreteProductB : public Product
        {
        public:
            std::string operation() const override
            {
                return "<<ConcreteProductB>> operation";
            }
        };

        class Creator
        {
        public:
            virtual ~Creator() {}
            virtual std::shared_ptr<Product> factoryMethod() const = 0;

            std::string operation()
            {
                std::shared_ptr<Product> product = factoryMethod();
                return "<<Creator>> code used " + product->operation();
            }
        };

        class ConcreteCreatorA : public Creator
        {
            std::shared_ptr<Product> factoryMethod() const override
            {
                return std::make_shared<ConcreteProductA>();
            }
        };

        class ConcreteCreatorB : public Creator
        {
            std::shared_ptr<Product> factoryMethod() const override
            {
                return std::make_shared<ConcreteProductB>();
            }
        };

        class Client
        {
        public:
            Client(std::shared_ptr<Creator> creator)
            {
                _creator = creator;
            }

            void setCreator(std::shared_ptr<Creator> creator)
            {
                _creator = creator;
            }

            void execute()
            {
                std::cout << _creator->operation() << std::endl;
            }

        private:
            std::shared_ptr<Creator> _creator;
        };

    } // namespace factory_method

} // namespace creational

int main()
{
    std::cout << "Setting up <<Client>> with <<ConcreteCreatorA>>:\n";
    std::shared_ptr<creational::factory_method::Creator> creatorA = std::make_shared<creational::factory_method::ConcreteCreatorA>();
    creational::factory_method::Client client = creational::factory_method::Client(creatorA);
    client.execute();
    std::cout << std::endl;
    std::cout << "Setting up <<Client>> with <<ConcreteCreatorB>>:\n";
    std::shared_ptr<creational::factory_method::Creator> creatorB = std::make_shared<creational::factory_method::ConcreteCreatorB>();
    client.setCreator(creatorB);
    client.execute();

    return 0;
}