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
            virtual void notify(Colleague *sender, std::string event) const = 0;
        };

        class Colleague
        {
        public:
            Colleague(Mediator *mediator = nullptr) : _mediator(mediator)
            {
            }
            void set_mediator(Mediator *mediator)
            {
                this->_mediator = mediator;
            }

        protected:
            Mediator *_mediator;
        };

        class Colleague1 : public Colleague
        {
        public:
            void do_a()
            {
                std::cout << "Colleague1.do_a()\n";
                this->_mediator->notify(this, "A");
            }
            void do_b()
            {
                std::cout << "Colleague1.do_b()\n";
                this->_mediator->notify(this, "B");
            }
        };

        class Colleague2 : public Colleague
        {
        public:
            void do_c()
            {
                std::cout << "Colleague2.do_c()\n";
                this->_mediator->notify(this, "C");
            }
            void do_d()
            {
                std::cout << "Colleague2.do_d()\n";
                this->_mediator->notify(this, "D");
            }
        };

        class ConcreteMediator : public Mediator
        {
        private:
            Colleague1 *_colleague1;
            Colleague2 *_colleague2;

        public:
            ConcreteMediator(Colleague1 *colleague1, Colleague2 *colleague2) : _colleague1(colleague1), _colleague2(colleague2)
            {
                this->_colleague1->set_mediator(this);
                this->_colleague2->set_mediator(this);
            }
            void notify(Colleague *sender, std::string event) const override
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
        };

        class Client
        {
        public:
            void execute()
            {
                Colleague1 *colleague1 = new Colleague1;
                Colleague2 *colleague2 = new Colleague2;
                ConcreteMediator *mediator = new ConcreteMediator(colleague1, colleague2);
                std::cout << "Client triggers operation A.\n";
                colleague1->do_a();
                std::cout << "\n";
                std::cout << "Client triggers operation D.\n";
                colleague2->do_d();

                delete colleague1;
                delete colleague2;
                delete mediator;
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