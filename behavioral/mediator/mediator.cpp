#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace mediator
    {
        class Colleague;

        class Mediator
        {
        public:
            virtual void notify(std::shared_ptr<Colleague> sender, std::string event) const = 0;
        };

        class Colleague
        {
        public:
            Colleague(std::shared_ptr<Mediator> mediator = nullptr) : _mediator(mediator)
            {
            }
            void set_mediator(std::shared_ptr<Mediator> mediator)
            {
                this->_mediator = mediator;
            }

        protected:
            std::shared_ptr<Mediator> _mediator;
        };

        class Colleague1 : public Colleague, public std::enable_shared_from_this<Colleague>
        {
        public:
            void do_a()
            {
                std::cout << "Colleague1.do_a()\n";
                this->_mediator->notify(shared_from_this(), "A");
            }
            void do_b()
            {
                std::cout << "Colleague1.do_b()\n";
                this->_mediator->notify(shared_from_this(), "B");
            }
        };

        class Colleague2 : public Colleague, public std::enable_shared_from_this<Colleague>
        {
        public:
            void do_c()
            {
                std::cout << "Colleague2.do_c()\n";
                this->_mediator->notify(shared_from_this(), "C");
            }
            void do_d()
            {
                std::cout << "Colleague2.do_d()\n";
                this->_mediator->notify(shared_from_this(), "D");
            }
        };

        class ConcreteMediator : public Mediator, public std::enable_shared_from_this<Mediator>
        {
        public:
            ConcreteMediator(std::shared_ptr<Colleague1> colleague1, std::shared_ptr<Colleague2> colleague2) : _colleague1(colleague1), _colleague2(colleague2)
            {
            }

            /*
             * This is needed because we cannot use shared_from_this() in constructors since there is no valid shared pointer
             * available while executing constructors.
             */
            void setup_collegues()
            {
                this->_colleague1->set_mediator(shared_from_this());
                this->_colleague2->set_mediator(shared_from_this());
            }

            void notify(std::shared_ptr<Colleague> sender, std::string event) const override
            {
                if (event == "A")
                {
                    std::cout << "Mediator receives A and triggers this interaction:\n";
                    this->_colleague2->do_c();
                }
                if (event == "D")
                {
                    std::cout << "Mediator receives D and triggers this interaction:\n";
                    this->_colleague1->do_b();
                    this->_colleague2->do_c();
                }
            }

        private:
            std::shared_ptr<Colleague1> _colleague1;
            std::shared_ptr<Colleague2> _colleague2;
        };

        class Client
        {
        public:
            void execute()
            {
                std::shared_ptr<Colleague1> colleague1 = std::make_shared<Colleague1>();
                std::shared_ptr<Colleague2> colleague2 = std::make_shared<Colleague2>();
                std::shared_ptr<ConcreteMediator> mediator = std::make_shared<ConcreteMediator>(colleague1, colleague2);
                mediator->setup_collegues();
                std::cout << "Client triggers operation A.\n";
                colleague1->do_a();
                std::cout << "\n";
                std::cout << "Client triggers operation D.\n";
                colleague2->do_d();
            }
        };

    } // namespace mediator

} // namespace behavioral

int main()
{
    behavioral::mediator::Client client;
    client.execute();
    return 0;
}