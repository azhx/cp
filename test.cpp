#include <bits/stdc++.h>
using namespace std;

int main() {
    // whatever shit I wANT TO Do here
    return 0;
}

class PotHead
{
    public:
    void givePot(int amount);
    int amountPot();
    private:
    int amount_pot;
};

void PotHead::givePot(int amount) {
    PotHead::amount_pot += amount;
}

int PotHead::amountPot() {
    return PotHead::amount_pot;
}

PotHead john_smith = PotHead();