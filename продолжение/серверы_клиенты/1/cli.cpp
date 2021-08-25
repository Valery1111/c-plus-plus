#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
 
using  boost::asio::ip::tcp;
 
int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"),1234);
        std::cout<<ep.address()<<std::endl;
 
        tcp::socket socket(io_service);
        socket.connect(ep);
        if(socket.is_open())
        {
            std::cout<<"connect!"<<std::endl;
            boost::asio::streambuf boost_stream;
            std::ostream stream(&boost_stream);
            stream<<"hello";
            boost::asio::write(socket,boost_stream);
        }
 
        return 0;
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
