#include <iostream>
#include <vector>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */

    template<typename T>    
    class priority_queue {
        public :

            void push(T a) {
                this->vec.push_back(a);
                int len = vec.size() - 1;
                while (len >> 1 >= 1 && vec[len] < vec[len >> 1]) {
                    swap(vec[len], vec[len >> 1]);
                }
            }

            void maintain() {
                int ind = 1;
                while (ind << )
            }

        private:
            vector<T> vec;
    };

    MedianFinder() {

    }
    
    void addNum(int num) {

    }
    
    double findMedian() {

    }
};

int main()
{
    return 0;
}

