#include <unordered_map>
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

struct consumption {
    friend class caffeine;
    chrono::system_clock::time_point time_stamp;
    int caffeine_mg{0};
    consumption(int input) : time_stamp(chrono::system_clock::now()), caffeine_mg(input) {}
};

class caffeine {
    vector<consumption> coffee_list;

public:
    void consume(int caffeine_amount) {
        auto current = consumption(caffeine_amount);
        coffee_list.push_back(current);
    }

    void caffeine_amount() {
        chrono::system_clock::time_point now = chrono::system_clock::now();

        float caffeine = 0;

        auto i = coffee_list.begin();

        while (i < coffee_list.end()) {
            auto time_since = chrono::duration_cast<chrono::minutes>(now - i->time_stamp);
            double minutesFloat = time_since.count();

            // half life is 5 hours(300 minutes)
            i->caffeine_mg *= pow(0.5, minutesFloat/300);

            if (i->caffeine_mg < 1) {
                i = coffee_list.erase(i);
            } else {
                i->time_stamp = chrono::system_clock::now();
                caffeine += i->caffeine_mg;
                ++i;
            }
        }
        cout << "Remaining caffeine: " << caffeine << " mg" << endl;
    }
};