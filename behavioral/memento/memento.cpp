#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace memento
    {
        class Memento
        {
        public:
            Memento()
            {
            }

        private:
            friend class Originator;

            void set_state(std::string state)
            {
                _state = state;
            }

            std::string get_state()
            {
                return _state;
            }

        private:
            std::string _state;
        };

        class Originator
        {
        public:
            Originator()
            {
                _state = generate_random_string();
                std::cout << "Originator - intial state: " << this->_state << "\n";
            }

            void operation()
            {
                _state = generate_random_string();
                std::cout << "Originator - operation changed state to: " << this->_state << "\n";
            }

            std::unique_ptr<Memento> get_memento()
            {

                std::unique_ptr<Memento> memento = std::make_unique<Memento>();
                memento->set_state(_state);

                return memento;
            }

            void set_memento(const std::unique_ptr<Memento> &memento)
            {
                _state = memento->get_state();
                std::cout << "Originator - restoring state to: " << this->_state << "\n";
            }

        private:
            std::string generate_random_string(int length = 10)
            {
                const char alphanum[] =
                    "0123456789"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";
                int string_length = sizeof(alphanum) - 1;

                std::string random_string;
                for (int i = 0; i < length; i++)
                {
                    random_string += alphanum[std::rand() % string_length];
                }
                return random_string;
            }

            std::string _state;
        };

        class Caretaker
        {
        public:
            Caretaker(std::shared_ptr<Originator> originator) : _originator(originator)
            {
            }
            void restore()
            {
                if (!this->_mementos.size())
                {
                    return;
                }
                std::unique_ptr<Memento> &memento = this->_mementos.back();
                this->_originator->set_memento(memento);
                this->_mementos.pop_back();
            }
            void backup()
            {
                _mementos.push_back(std::move(_originator->get_memento()));
            }

        private:
            std::vector<std::unique_ptr<Memento>> _mementos;
            std::shared_ptr<Originator> _originator;
        };

        class Client
        {
        public:
            void execute()
            {
                std::shared_ptr<Originator> originator = std::make_shared<Originator>();
                std::shared_ptr<Caretaker> caretaker = std::make_shared<Caretaker>(originator);

                caretaker->backup();
                originator->operation();
                caretaker->backup();
                originator->operation();
                caretaker->backup();
                originator->operation();
                caretaker->restore();
                caretaker->restore();
            }
        };

    } // namespace memento

} // namespace behavioral

int main()
{
    behavioral::memento::Client client;

    client.execute();
    return 0;
}