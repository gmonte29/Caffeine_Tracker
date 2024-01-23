#include "substance_class.cpp"
using namespace std;

class user{
    status<coffee> coffee_status;
    status<alcohol> alcohol_status;

    public:
    void consume(string type, int amount){
        if(type == "coffee"){
            coffee_status.consume(amount);

        }
        else if(type=="alcohol"){
            alcohol_status.consume(amount);

        }
    }

    void status(string type){
        if(type == "coffee"){
            coffee_status.amount();

        }
        else if(type=="alcohol"){
            alcohol_status.amount();
        }
    }
};

int main(){
    user U;
    
    U.consume("coffee", 50);
    U.consume("alcohol", 3);

    U.status("coffee"); // Print remaining caffeine amount
    U.status("alcohol"); // Print remaining alcohol amount

    return 0;
}

