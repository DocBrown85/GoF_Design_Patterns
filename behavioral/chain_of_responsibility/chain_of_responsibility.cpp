#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace chain_of_responsibility
    {

        class Handler
        {
        public:
            virtual std::shared_ptr<Handler> set_next(std::shared_ptr<Handler> handler) = 0;
            virtual std::string handle(std::string request) = 0;
        };

        /*
         * Base class for Concrete Handlers, implements default chaining behavior
         */
        class AbstractHandler : public Handler
        {
        public:
            AbstractHandler() : _next_handler(nullptr)
            {
            }

            std::shared_ptr<Handler> set_next(std::shared_ptr<Handler> next_handler) override
            {
                _next_handler = next_handler;
                return next_handler;
            }

            std::string handle(std::string request) override
            {
                if (_next_handler)
                {
                    return _next_handler->handle(request);
                }

                return {};
            }

        private:
            std::shared_ptr<Handler> _next_handler;
        };

        class ConcreteHandlerA : public AbstractHandler
        {
            std::string handle(std::string request) override
            {
                if (request == "REQUEST_A")
                {
                    return "ConcreteHandlerA - serving " + request;
                }
                else
                {
                    return AbstractHandler::handle(request);
                }
            }
        };

        class ConcreteHandlerB : public AbstractHandler
        {
            std::string handle(std::string request) override
            {
                if (request == "REQUEST_B")
                {
                    return "ConcreteHandlerB - serving " + request;
                }
                else
                {
                    return AbstractHandler::handle(request);
                }
            }
        };

        class ConcreteHandlerC : public AbstractHandler
        {
            std::string handle(std::string request) override
            {
                if (request == "REQUEST_C")
                {
                    return "ConcreteHandlerC - serving " + request;
                }
                else
                {
                    return AbstractHandler::handle(request);
                }
            }
        };

        class Client
        {
        public:
            void execute(std::shared_ptr<Handler> handler)
            {
                std::vector<std::string> requests = {"REQUEST_A", "REQUEST_B", "REQUEST_C", "REQUEST_D"};
                for (const std::string &request : requests)
                {
                    std::cout << "Client: sending " << request << " to the chain\n";
                    const std::string result = handler->handle(request);
                    if (!result.empty())
                    {
                        std::cout << "  " << result << "\n";
                    }
                    else
                    {
                        std::cout << "  " << request << " has been dropped.\n";
                    }
                }
            }
        };

    } // namespace chain_of_responsibility

} // namespace behavioral

int main()
{
    std::shared_ptr<behavioral::chain_of_responsibility::ConcreteHandlerA> concrete_handler_a = std::make_shared<behavioral::chain_of_responsibility::ConcreteHandlerA>();
    std::shared_ptr<behavioral::chain_of_responsibility::ConcreteHandlerB> concrete_handler_b = std::make_shared<behavioral::chain_of_responsibility::ConcreteHandlerB>();
    std::shared_ptr<behavioral::chain_of_responsibility::ConcreteHandlerC> concrete_handler_c = std::make_shared<behavioral::chain_of_responsibility::ConcreteHandlerC>();

    concrete_handler_a->set_next(concrete_handler_b)->set_next(concrete_handler_c);

    behavioral::chain_of_responsibility::Client client;

    client.execute(concrete_handler_a);

    return 0;
}