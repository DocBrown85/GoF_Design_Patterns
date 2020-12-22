#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

namespace structural
{
    namespace adapter
    {
        class Target
        {
        public:
            virtual ~Target(){};
            virtual std::string operation() = 0;
        };

        class Adaptee
        {
        public:
            virtual std::string method()
            {
                return "Adaptee Method";
            }
        };

        class Adapter : public Target
        {
        public:
            Adapter(std::unique_ptr<Adaptee> adaptee) : _adaptee(std::move(adaptee)) {}

            std::string operation() override
            {
                return "Adapted " + _adaptee->method();
            }

        private:
            std::unique_ptr<Adaptee> _adaptee;
        };

        class Client
        {
        public:
            Client(std::unique_ptr<Target> target) : _target(std::move(target)) {}

            void execute()
            {
                std::cout << _target->operation() << "\n";
            }

        private:
            std::unique_ptr<Target> _target;
        };

    } // namespace adapter

} // namespace structural

int main()
{

    std::unique_ptr<structural::adapter::Adaptee> adaptee = std::make_unique<structural::adapter::Adaptee>();
    std::unique_ptr<structural::adapter::Adapter> adapter = std::make_unique<structural::adapter::Adapter>(std::move(adaptee));
    structural::adapter::Client client(std::move(adapter));
    client.execute();

    return 0;
}