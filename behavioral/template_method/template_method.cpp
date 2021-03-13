#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace template_method
    {
        class AbstractClass
        {
        public:
            // the skeleton of an algorithm
            void template_method() const
            {
                this->base_operation_1();
                this->required_operation_1();
                this->base_operation_2();
                this->hook_1();
                this->required_operation_2();
                this->base_operation_3();
                this->hook_2();
            }

        protected:
            // parts of the algorithm implemented by base class, but overridable if needed
            void base_operation_1() const
            {
                std::cout << "AbstractClass: base_operation_1\n";
            }
            void base_operation_2() const
            {
                std::cout << "AbstractClass: base_operation_2\n";
            }
            void base_operation_3() const
            {
                std::cout << "AbstractClass: base_operation_3\n";
            }

            // steps of the algoritm that have to be implemented by subclasses
            virtual void required_operation_1() const = 0;
            virtual void required_operation_2() const = 0;

            // hooks overridable by subclasses if needed, not mandatory
            virtual void hook_1() const {}
            virtual void hook_2() const {}
        };

        class ConcreteClass1 : public AbstractClass
        {
        protected:
            void required_operation_1() const override
            {
                std::cout << "ConcreteClass1: required_operation_1\n";
            }
            void required_operation_2() const override
            {
                std::cout << "ConcreteClass1: required_operation_2\n";
            }
        };

        class ConcreteClass2 : public AbstractClass
        {
        protected:
            void required_operation_1() const override
            {
                std::cout << "ConcreteClass2: required_operation_1\n";
            }
            void required_operation_2() const override
            {
                std::cout << "ConcreteClass2: required_operation_2\n";
            }
            void hook_1() const override
            {
                std::cout << "ConcreteClass2: hook_1\n";
            }
        };

        class Client
        {
        public:
            void execute(const std::unique_ptr<AbstractClass> &abstract_class)
            {
                abstract_class->template_method();
            }
        };

    } // namespace template_method

} // namespace behavioral

int main()
{
    behavioral::template_method::Client client;

    std::unique_ptr<behavioral::template_method::AbstractClass> concrete_class_1 = std::make_unique<behavioral::template_method::ConcreteClass1>();
    client.execute(concrete_class_1);

    std::unique_ptr<behavioral::template_method::AbstractClass> concrete_class_2 = std::make_unique<behavioral::template_method::ConcreteClass2>();
    client.execute(concrete_class_2);

    return 0;
}