#include <iostream>
#include <cstdlib>
#include <cmath>

unsigned int roll_dice();

int main() {
    enum class Status{CONTINUE, WON, LOST};
    srand(static_cast<unsigned int>(time(0)));
    
    unsigned int my_point{0};
    Status game_status;
    unsigned int sum_of_dice{roll_dice()};
    
    switch (sum_of_dice) {
        case 7:
        case 11:
            game_status = Status::WON;
            break;
        case 2:
        case 3:
        case 12:
            game_status = Status::LOST;
            break;
        default:
            game_status = Status::CONTINUE;
            my_point = sum_of_dice;
            std::cout << "Point is: " << my_point << std::endl;
            break;
    }
    
    while (Status::CONTINUE == game_status) {
        sum_of_dice = roll_dice();
        
        if (sum_of_dice == my_point) {
            game_status = Status::WON;
        } else if (sum_of_dice == 7) {
            game_status = Status::LOST;
        }
    }
    
    if (Status::WON == game_status) {
        std::cout << "Player won!" << std::endl;
    } else {
        std::cout << "Player lost!" << std::endl;
    }
    
    return 0;
}

unsigned int roll_dice() {
    unsigned int dice_1{rand()%6};
    unsigned int dice_2{rand()%6};
    
//     When the remainder is 0 add 1 to the dice
    if (0 == dice_1) {
//         std::cout << "dice_1 is 0" << std::endl;
        dice_1 = 1;
    }

    if (0 == dice_2) {
//         std::cout << "dice_2 is 0" << std::endl;
        dice_2 = 1;
    }

    unsigned int dice_sum{dice_1 + dice_2};
    std::cout << "Point is: " << dice_1 << " + " << dice_2 << " = " << dice_sum << std::endl;
    return dice_sum;
}
