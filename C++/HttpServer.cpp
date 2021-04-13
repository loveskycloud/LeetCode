#include <iostream>

using namespace std;

class HttpServer {
public :
    
    static HttpServer *getInstance() {
        if (instance == nullptr) {
            instance = new HttpServer();
        }
        return instance;
    }


private :
    static HttpServer *instance;
    HttpServer() {}
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {}

};

HttpServer *HttpServer::instance = nullptr;

int main()
{
    HttpServer *t1 = HttpServer::getInstance();
    delete t1;
    HttpServer *t2 = HttpServer::getInstance();
    cout << t1 << endl;
    cout << t2 << endl;
    return 0;
}

