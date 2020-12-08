#include <cstring>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

namespace creational
{
    namespace builder
    {

        class Product
        {
        public:
            virtual ~Product() {}

            virtual void setComponentA(std::string component) = 0;
            virtual void setComponentB(std::string component) = 0;
            virtual void setComponentC(std::string component) = 0;
            virtual void enumerateComponents() const = 0;
        };

        class Product1 : public Product
        {
        public:
            void setComponentA(std::string component) override
            {
                _components.push_back(component);
            }

            void setComponentB(std::string component) override
            {
                _components.push_back(component);
            }

            void setComponentC(std::string component) override
            {
                _components.push_back(component);
            }

            void enumerateComponents() const override
            {
                for (size_t i = 0; i < _components.size(); i++)
                {
                    if (_components[i] == _components.back())
                    {
                        std::cout << _components[i];
                    }
                    else
                    {
                        std::cout << _components[i] << ", ";
                    }
                }
                std::cout << "\n\n";
            }

        private:
            std::vector<std::string> _components;
        };

        class Builder
        {
        public:
            virtual ~Builder() {}

            virtual void buildComponentA() const = 0;
            virtual void buildComponentB() const = 0;
            virtual void buildComponentC() const = 0;
        };

        class ConcreteBuilder1 : public Builder
        {
        public:
            ConcreteBuilder1()
            {
                Reset();
            }

            void buildComponentA() const override
            {
                _product->setComponentA("Component A1");
            }

            void buildComponentB() const override
            {
                _product->setComponentB("Component B1");
            }

            void buildComponentC() const override
            {
                _product->setComponentC("Component C1");
            }

            std::shared_ptr<Product> getProduct()
            {
                std::shared_ptr<Product> product = _product;
                Reset();
                return product;
            }

            void Reset()
            {
                _product = std::make_shared<Product1>();
            }

        private:
            std::shared_ptr<Product> _product;
        };

        class Director
        {
        public:
            void setBuilder(std::shared_ptr<Builder> builder)
            {
                _builder = builder;
            }

            void buildStandardProduct()
            {
                _builder->buildComponentA();
            }

            void buildPremiumProduct()
            {
                _builder->buildComponentA();
                _builder->buildComponentB();
                _builder->buildComponentC();
            }

        private:
            std::shared_ptr<Builder> _builder;
        };

        class Client
        {
        public:
            Client(std::shared_ptr<Director> director)
            {
                _director = director;
            }

            void execute()
            {
                std::shared_ptr<ConcreteBuilder1> builder = std::make_shared<ConcreteBuilder1>();
                _director->setBuilder(builder);

                std::cout << "Building Standard Product\n";
                std::cout << "Standard Product Components:\n";
                _director->buildStandardProduct();

                std::shared_ptr<Product> standardProduct = builder->getProduct();
                standardProduct->enumerateComponents();

                std::cout << "Building Premium Product\n";
                std::cout << "Premium Product Components:\n";
                _director->buildPremiumProduct();

                std::shared_ptr<Product> premiumProduct = builder->getProduct();
                premiumProduct->enumerateComponents();
            }

        private:
            std::shared_ptr<Director> _director;
        };

    } // namespace builder

} // namespace creational

int main()
{
    std::shared_ptr<creational::builder::Director> director = std::make_shared<creational::builder::Director>();
    creational::builder::Client client(director);
    client.execute();

    return 0;
}