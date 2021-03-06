#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace observer
    {
        class Observer
        {
        public:
            virtual ~Observer(){};
            virtual void update(const std::string &message) = 0;
        };

        class Subject
        {
        public:
            virtual ~Subject(){};
            virtual void attach_observer(std::shared_ptr<Observer> observer) = 0;
            virtual void detach_observer(std::shared_ptr<Observer> observer) = 0;
            virtual void notify() = 0;
        };

        class ConcreteSubject : public Subject
        {
        public:
            virtual ~ConcreteSubject()
            {
                std::cout << "Disposing ConcreteSubject.\n";
            }

            void attach_observer(std::shared_ptr<Observer> observer) override
            {
                _observers.push_back(observer);
            }

            void detach_observer(std::shared_ptr<Observer> observer) override
            {
                _observers.remove(observer);
            }

            void notify() override
            {
                std::list<std::shared_ptr<Observer>>::iterator iterator = _observers.begin();
                get_observers_count();
                while (iterator != _observers.end())
                {
                    (*iterator)->update(message_);
                    ++iterator;
                }
            }

            void set_message(std::string message = "Empty")
            {
                this->message_ = message;
                notify();
            }
            void get_observers_count()
            {
                std::cout << "There are " << _observers.size() << " observers in the list.\n";
            }

            void business_logic()
            {
                this->message_ = "change message message";
                notify();
            }

        private:
            std::list<std::shared_ptr<Observer>> _observers;
            std::string message_;
        };

        class ConcreteObserver : public Observer, public std::enable_shared_from_this<ConcreteObserver>
        {
        public:
            ConcreteObserver()
            {
                std::cout << "Creating Observer \"" << ++ConcreteObserver::_static_number << "\".\n";
            }

            virtual ~ConcreteObserver()
            {
                std::cout << "Disposing Observer \"" << this->_number << "\".\n";
            }

            void update(const std::string &message) override
            {
                _message = message;
                show_status();
            }

            void add(std::shared_ptr<Subject> subject)
            {
                this->_subject = subject;
                this->_subject->attach_observer(shared_from_this());
                this->_number = ConcreteObserver::_static_number;
            }

            void remove()
            {
                this->_subject->detach_observer(shared_from_this());
                std::cout << "Observer \"" << _number << "\" removed from the list.\n";
            }

            void show_status()
            {
                std::cout << "Observer \"" << this->_number << "\": new message is available --> " << this->_message << "\n";
            }

        private:
            std::string _message;
            std::shared_ptr<Subject> _subject;
            static int _static_number;
            int _number;
        };

        int ConcreteObserver::_static_number = 0;

        class Client
        {
        public:
            void execute()
            {
                std::shared_ptr<ConcreteSubject> subject = std::make_shared<ConcreteSubject>();
                std::shared_ptr<ConcreteObserver> observer1 = std::make_shared<ConcreteObserver>();
                observer1->add(subject);
                std::shared_ptr<ConcreteObserver> observer2 = std::make_shared<ConcreteObserver>();
                observer2->add(subject);
                std::shared_ptr<ConcreteObserver> observer3 = std::make_shared<ConcreteObserver>();
                observer3->add(subject);
                std::shared_ptr<ConcreteObserver> observer4 = std::make_shared<ConcreteObserver>();
                std::shared_ptr<ConcreteObserver> observer5 = std::make_shared<ConcreteObserver>();

                subject->set_message("Message 1");
                observer3->remove();

                subject->set_message("Message 2");
                observer4->add(subject);

                observer2->remove();
                observer5->add(subject);

                subject->set_message("Message 3");
                observer5->remove();

                observer4->remove();
                observer1->remove();
            }
        };

    } // namespace observer

} // namespace behavioral

int main()
{
    behavioral::observer::Client client;

    client.execute();
    return 0;
}