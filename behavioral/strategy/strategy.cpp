#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace strategy
    {
        class Strategy
        {
        public:
            virtual ~Strategy() {}

            virtual std::string execute_algorithm(const std::vector<std::string> &data) const = 0;
        };

        class Context
        {
        public:
            Context(std::unique_ptr<Strategy> strategy = nullptr) : _strategy(std::move(strategy))
            {
            }

            void set_strategy(std::unique_ptr<Strategy> strategy)
            {
                this->_strategy = std::move(strategy);
            }

            void business_logic() const
            {
                std::cout << "Context: Sorting data using provided strategy\n";
                std::string result = this->_strategy->execute_algorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
                std::cout << result << "\n";
            }

        private:
            std::unique_ptr<Strategy> _strategy;
        };

        class ConcreteStrategyA : public Strategy
        {
        public:
            std::string execute_algorithm(const std::vector<std::string> &data) const override
            {
                std::string result;
                std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
                    result += letter;
                });
                std::sort(std::begin(result), std::end(result));

                return result;
            }
        };
        class ConcreteStrategyB : public Strategy
        {
            std::string execute_algorithm(const std::vector<std::string> &data) const override
            {
                std::string result;
                std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
                    result += letter;
                });
                std::sort(std::begin(result), std::end(result));
                for (int i = 0; i < result.size() / 2; i++)
                {
                    std::swap(result[i], result[result.size() - i - 1]);
                }

                return result;
            }
        };

        class Client
        {
        public:
            void execute()
            {
                std::unique_ptr<Context> context = std::make_unique<Context>(std::make_unique<ConcreteStrategyA>());
                std::cout << "Client: using normal sorting Strategy.\n";
                context->business_logic();
                std::cout << "\n";
                std::cout << "Client: using reverse sorting Strategy.\n";
                context->set_strategy(std::make_unique<ConcreteStrategyB>());
                context->business_logic();
            }
        };

    } // namespace strategy

} // namespace behavioral

int main()
{
    behavioral::strategy::Client client;

    client.execute();
    return 0;
}