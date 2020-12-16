#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

namespace creational
{
    namespace prototype
    {
        enum PrototypeType
        {
            PROTOTYPE_1 = 0,
            PROTOTYPE_2
        };
        class Prototype
        {
        public:
            Prototype() {}
            Prototype(std::string name) : _name(name) {}

            virtual ~Prototype() {}
            virtual std::unique_ptr<Prototype> clone() const = 0;
            virtual void operation(float field)
            {
                _field = field;
                std::cout << "executing operation from " << _name << " with field : " << _field << std::endl;
            }

        private:
            std::string _name;
            float _field;
        };

        class ConcretePrototype1 : public Prototype
        {
        private:
            float _field1;

        public:
            ConcretePrototype1(std::string name, float field1)
                : Prototype(name), _field1(field1)
            {
            }
            std::unique_ptr<Prototype> clone() const override
            {
                return std::make_unique<ConcretePrototype1>(*this);
            }
        };

        class ConcretePrototype2 : public Prototype
        {
        private:
            float _field2;

        public:
            ConcretePrototype2(std::string name, float field2)
                : Prototype(name), _field2(field2)
            {
            }
            std::unique_ptr<Prototype> clone() const override
            {
                return std::make_unique<ConcretePrototype2>(*this);
            }
        };

        class PrototypeFactory
        {
        private:
            std::map<PrototypeType, std::unique_ptr<Prototype>> _prototypes;

        public:
            PrototypeFactory()
            {
                _prototypes[PrototypeType::PROTOTYPE_1] = std::make_unique<ConcretePrototype1>("PROTOTYPE_1 ", 50.f);
                _prototypes[PrototypeType::PROTOTYPE_2] = std::make_unique<ConcretePrototype2>("PROTOTYPE_2 ", 60.f);
            }

            std::unique_ptr<Prototype> create(PrototypeType type)
            {
                return _prototypes[type]->clone();
            }
        };

        class Client
        {
        public:
            Client(std::unique_ptr<PrototypeFactory> prototype_factory) : _prototype_factory(std::move(prototype_factory))
            {
            }

            void execute()
            {
                std::cout << "Creating Prototype 1\n";

                std::unique_ptr<Prototype> prototype1 = _prototype_factory->create(PrototypeType::PROTOTYPE_1);
                prototype1->operation(90);

                std::cout << "\n";

                std::cout << "Creating Prototype 2\n";

                std::unique_ptr<Prototype> prototype2 = _prototype_factory->create(PrototypeType::PROTOTYPE_2);
                prototype2->operation(10);
            }

        private:
            std::unique_ptr<PrototypeFactory> _prototype_factory;
        };

    } // namespace prototype

} // namespace creational

int main()
{
    creational::prototype::Client client(std::make_unique<creational::prototype::PrototypeFactory>());
    client.execute();

    return 0;
}