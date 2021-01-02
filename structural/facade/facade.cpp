#include <cstring>
#include <iostream>
#include <memory>

namespace structural
{
    namespace facade
    {
        class SubsystemA
        {
        public:
            std::string operation1() const
            {
                return "SubsystemA - operation1()\n";
            }

            std::string operationN() const
            {
                return "SubsystemA - operationN()\n";
            }
        };

        class SubsystemB
        {
        public:
            std::string operation1() const
            {
                return "SubsystemB - operation1()\n";
            }

            std::string operationK() const
            {
                return "SubsystemB - operationK()\n";
            }
        };

        class Facade
        {
        public:
            Facade()
            {
                _subsystemA = std::make_unique<SubsystemA>();
                _subsystemB = std::make_unique<SubsystemB>();
            }

            std::string operation() const
            {
                std::string result = "Facade - operation() calling:\n";
                result += _subsystemA->operation1();
                result += _subsystemB->operationK();
                result += _subsystemA->operationN();
                result += _subsystemB->operation1();
                return result;
            }

        private:
            std::unique_ptr<SubsystemA> _subsystemA;
            std::unique_ptr<SubsystemB> _subsystemB;
        };

        class Client
        {
        public:
            Client(std::unique_ptr<Facade> facade) : _facade(std::move(facade)) {}

            std::string execute() const
            {
                return _facade->operation();
            }

        private:
            std::unique_ptr<Facade> _facade;
        };

    } // namespace facade

} // namespace structural

int main()
{
    std::unique_ptr<structural::facade::Facade> facade = std::make_unique<structural::facade::Facade>();
    structural::facade::Client client(std::move(facade));
    std::cout << client.execute();
    return 0;
}