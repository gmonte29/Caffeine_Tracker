#include <unordered_map>
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

template<typename Substance>
struct substance {
    chrono::system_clock::time_point time_stamp;
    int amount{0};

    substance(int input) : time_stamp(chrono::system_clock::now()), amount(input) {}
};

struct coffee : public substance<coffee> {
    using substance::substance;
};

struct alcohol : public substance<alcohol> {
    using substance::substance;
};


template<typename Substance>
class status {
    vector<Substance> substance_list;

public:
    void consume(int amount) {
        auto current = Substance(amount);
        substance_list.push_back(current);
    }

    void amount() {
        auto now = chrono::system_clock::now();

        float total_amount = 0;

        auto i = substance_list.begin();
        while (i < substance_list.end()) {
            auto time_since = chrono::duration_cast<chrono::minutes>(now - i->time_stamp);
            double minutesFloat = time_since.count();

            // half life is 5 hours(300 minutes)
            i->amount *= pow(0.5, minutesFloat/300);

            if (i->amount < 1) {
                i = substance_list.erase(i);
            } else {
                i->time_stamp = chrono::system_clock::now();
                total_amount += i->amount;
                ++i;
            }
        }

        cout << "Remaining amount: " << total_amount << endl;
    }
};
