









#include <iostream>
#include <vector>
#include <cmath>

class Reaction {
private:
    int numReactants;
    std::vector<float> reactantConcentrations;
    float reactionRateConstant;
    int reactionOrder;

public:
    Reaction(int numReactants, const std::vector<float>& concentrations, float constant, int order) 
        : numReactants(numReactants), reactantConcentrations(concentrations), reactionRateConstant(constant), reactionOrder(order) {}

    float calculateRate() const {
        float rate = reactionRateConstant;
        for(float concentration : reactantConcentrations) {
            rate *= std::pow(concentration, reactionOrder);
        }
        return rate;
    }
};

int main() {
    int numReactants;
    std::cin >> numReactants;

    std::vector<float> concentrations(numReactants);
    for(int i = 0; i < numReactants; i++) {
        std::cin >> concentrations[i];
    }

    float reactionRateConstant;
    std::cin >> reactionRateConstant;

    int reactionOrder;
    std::cin >> reactionOrder;

    float time;  
    std::cin >> time;

    Reaction reaction(numReactants, concentrations, reactionRateConstant, reactionOrder);
    std::cout << "The reaction rate at time " << time << " is: " << reaction.calculateRate() << std::endl;

    return 0;
}
