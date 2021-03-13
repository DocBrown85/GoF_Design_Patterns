#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace template_method
    {
        class Client
        {
        public:
            void execute()
            {
            }
        };

    } // namespace template_method

} // namespace behavioral

int main()
{
    behavioral::template_method::Client client;

    client.execute();
    return 0;
}