#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace state
    {
        class Context;

        class State
        {
        public:
            virtual ~State()
            {
            }

            void set_context(Context *context)
            {
                this->_context = context;
            }

            virtual void handle1() = 0;
            virtual void handle2() = 0;

        protected:
            Context *_context;
        };

        class Context
        {
        public:
            Context(std::unique_ptr<State> state) : _state(nullptr)
            {
                this->transition_to(std::move(state));
            }

            void transition_to(std::unique_ptr<State> state)
            {
                std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
                this->_state = std::move(state);
                this->_state->set_context(this);
            }

            void request1()
            {
                this->_state->handle1();
            }
            void request2()
            {
                this->_state->handle2();
            }

        private:
            std::unique_ptr<State> _state;
        };

        class ConcreteStateA : public State
        {
        public:
            void handle1() override;

            void handle2() override
            {
                std::cout << "ConcreteStateA handles request2.\n";
            }
        };

        class ConcreteStateB : public State
        {
        public:
            void handle1() override
            {
                std::cout << "ConcreteStateB handles request1.\n";
            }
            void handle2() override
            {
                std::cout << "ConcreteStateB handles request2.\n";
                std::cout << "ConcreteStateB wants to change the state of the context.\n";
                this->_context->transition_to(std::make_unique<ConcreteStateA>());
            }
        };

        void ConcreteStateA::handle1()
        {
            {
                std::cout << "ConcreteStateA handles request1.\n";
                std::cout << "ConcreteStateA wants to change the state of the context.\n";

                this->_context->transition_to(std::make_unique<ConcreteStateB>());
            }
        }

        class Client
        {
        public:
            void execute()
            {
                std::unique_ptr<Context> context = std::make_unique<Context>(std::make_unique<ConcreteStateA>());
                context->request1();
                context->request2();
            }
        };

    } // namespace state

} // namespace behavioral

int main()
{
    behavioral::state::Client client;

    client.execute();
    return 0;
}