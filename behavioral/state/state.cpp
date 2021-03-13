#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace state
    {

        class Client
        {
        public:
            void execute()
            {
            }
        };

    } // namespace state

} // namespace behavioral

int main()
{
    behavioral::observer::Client client;

    client.execute();
    return 0;
}