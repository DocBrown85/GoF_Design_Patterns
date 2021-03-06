#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace observer
    {
        class Client
        {
        public:
            void execute()
            {
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