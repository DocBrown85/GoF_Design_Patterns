#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace visitor
    {
        class Client
        {
        public:
            void execute()
            {
            }
        };

    } // namespace visitor

} // namespace behavioral

int main()
{
    behavioral::visitor::Client client;

    return 0;
}