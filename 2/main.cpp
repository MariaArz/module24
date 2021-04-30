#include <iostream>
#include<vector>

enum rooms{
    BEDROOM,
    KITCHEN,
    BATHROOM,
    PLAYROOM,
    HALL

};
enum building{
    GARAGE,
    BARN,
    BATH,
};

struct room{
    std::string name="unknown";
    int space=0;
};

struct floor{
    int room_count=0;
    int high=0;
    room SR;
    std::vector<room> some_room;
};
struct home{
    int space_house=0;
    int floor_count=0;
    bool oven=false;
    floor SF;
    std::vector<floor> some_floor;

};
struct buildings{
    std::string name="unknown";
    int space_buildings=0;
    bool oven_bath=false;
    home house;
};


void type_of_room (int& type, std::string name){
    if (name == "bedroom") type = BEDROOM;
    else if (name == "kitchen")  type = KITCHEN;
    else if (name == "bathroom") type = BATHROOM;
    else if (name == "playroom") type = PLAYROOM;
    else if (name == "hall") type = HALL;
}
void type_of_building (int& type, std::string name){
    if (name == "garage") type = GARAGE;
    else if (name == "barn")  type = BARN;
    else if (name == "bath") type = BATH;
}
int main() {

    int type_room, type_build;
    int area_count=0;
    int buildings_count=0;
    int space_village, space_area = 0;
    std::vector<buildings> area;
    buildings B;
    std::cout << "Input village's space" << std::endl;
    std::cin >> space_village;
    std::cout << "Input area's count" << std::endl;
    std::cin >> area_count;
    for (int i = 0; i < area_count; i++) {
        std::cout << "Input building's count on area "<< i+1 << std::endl;
        std::cin >> buildings_count;
        if (buildings_count > 1) {
            for (int j = 0; j < buildings_count - 1; j++) {
                std::cout << "Input building's " <<j+1<<"name (not house)" << std::endl;
                std::cin >> B.name;
                type_of_building(type_build,B.name);
                std::cout << "Input " << B.name << "'s space" << std::endl;
                std::cin >> B.space_buildings;
                space_area += B.space_buildings;
                if (B.name == "bath") {
                    std::cout << "Input oven's" << std::endl;
                    std::cin >> std::boolalpha >> B.oven_bath;
                }
                area.push_back(B);
            }
        }
        std::cout << "Input about house" << std::endl << "input house's space" << std::endl;
        std::cin >> B.house.space_house;
        space_area += B.house.space_house;
        std::cout << "Input oven's" << std::endl;
        std::cin >> std::boolalpha >> B.house.oven;
        std::cout << "input floor's count" << std::endl;
        std::cin >> B.house.floor_count;
        area.push_back(B);
        for (int k = 0; k < area[buildings_count-1].house.floor_count; k++) {
            std::cout << "input floor's high" << std::endl;
            std::cin >> area[buildings_count-1].house.SF.high;
            std::cout << "input floor's " <<k+1<<"room" <<std::endl;
            std::cin >> area[buildings_count-1].house.SF.room_count;
            area[buildings_count-1].house.some_floor.push_back(area[buildings_count-1].house.SF);
            for (int z = 0; z < area[buildings_count-1].house.some_floor[k].room_count; z++) {
                std::cout << "Input room's " <<z+1<<" name" << std::endl;
                std::cin >> area[buildings_count-1].house.some_floor[k].SR.name;
                type_of_room(type_room,area[buildings_count-1].house.some_floor[k].SR.name);
                std::cout << "Input room's space" << std::endl;
                std::cin >> area[buildings_count-1].house.some_floor[k].SR.space;
                area[buildings_count-1].house.some_floor[k].some_room.push_back(area[buildings_count-1].house.some_floor[k].SR);
            }
        }
    }
    std::cout<<space_area*100/space_village<<"%"<<std::endl;
    return 0;
}
