#include <cstring>
#include <iostream>
#include <list>
#include <memory>

namespace structural
{
    namespace composite
    {
        class Component : public std::enable_shared_from_this<Component>
        {
        public:
            ~Component() {}

            void set_parent(std::shared_ptr<Component> parent)
            {
                _parent = parent;
            }

            std::shared_ptr<Component> get_parent()
            {
                return _parent;
            }

            virtual void add(std::shared_ptr<Component> component) {}

            virtual void remove(std::shared_ptr<Component> component) {}

            virtual bool is_composite()
            {
                return false;
            }

            virtual std::string operation() const = 0;

        protected:
            std::shared_ptr<Component> _parent;
        };

        class Leaf : public Component
        {
        public:
            std::string operation() const override
            {
                return "Leaf";
            }
        };

        class Composite : public Component
        {
        public:
            void add(std::shared_ptr<Component> component) override
            {
                _children.push_back(component);
                component->set_parent(shared_from_this());
            }

            void remove(std::shared_ptr<Component> component) override
            {
                _children.remove(component);
                component->set_parent(nullptr);
            }

            bool is_composite() override
            {
                return true;
            }

            std::string operation() const override
            {
                std::string result;
                for (const std::shared_ptr<Component> child : _children)
                {
                    if (child == _children.back())
                    {
                        result += child->operation();
                    }
                    else
                    {
                        result += child->operation() + "+";
                    }
                }

                return "Branch(" + result + ")";
            }

        protected:
            std::list<std::shared_ptr<Component>> _children;
        };

        class Client
        {
        public:
            void execute(std::shared_ptr<Component> component1, std::shared_ptr<Component> component2)
            {
                if (component1->is_composite())
                {
                    component1->add(component2);
                }
                std::cout << "result:" << component1->operation();
            }
        };

    } // namespace composite

} // namespace structural

int main()
{
    std::shared_ptr<structural::composite::Component> tree = std::make_shared<structural::composite::Composite>();
    std::shared_ptr<structural::composite::Component> branch1 = std::make_shared<structural::composite::Composite>();

    std::shared_ptr<structural::composite::Component> leaf1 = std::make_shared<structural::composite::Leaf>();
    std::shared_ptr<structural::composite::Component> leaf2 = std::make_shared<structural::composite::Leaf>();
    std::shared_ptr<structural::composite::Component> leaf3 = std::make_shared<structural::composite::Leaf>();
    std::shared_ptr<structural::composite::Component> leaf4 = std::make_shared<structural::composite::Leaf>();
    branch1->add(leaf1);
    branch1->add(leaf2);

    std::shared_ptr<structural::composite::Component> branch2 = std::make_shared<structural::composite::Composite>();
    branch2->add(leaf3);
    tree->add(branch1);
    tree->add(branch2);

    std::cout << "Calling Client Code with the composite Tree:\n";
    structural::composite::Client client;
    client.execute(tree, leaf4);
    std::cout << "\n";

    return 0;
}