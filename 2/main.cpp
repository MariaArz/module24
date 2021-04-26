#include <iostream>

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
    room some_room;
};
struct home{
    int space_house=0;
    int floor_count=0;
    floor some_floor;
    bool oven=false;
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
    int area_count;
    int buildings_count;
    int space_village, space_area = 0;
    std::cout << "Input village's space" << std::endl;
    std::cin >> space_village;
    buildings area;
    std::cout << "Input area's count" << std::endl;
    std::cin >> area_count;
    for (int i = 0; i < area_count; i++) {
        std::cout << "Input building's count on area "<< i+1 << std::endl;
        std::cin >> buildings_count;
        if (buildings_count > 1) {
            for (int j = 0; j < buildings_count - 1; j++) {
                std::cout << "Input building's " <<j+1<<"name" << std::endl;
                std::cin >> area.name;
                type_of_building(type_build,area.name);
                std::cout << "Input " << area.name << "'s space" << std::endl;
                std::cin >> area.space_buildings;
                space_area += area.space_buildings;
                if (area.name == "bath") {
                    std::cout << "Input oven's" << std::endl;
                    std::cin >> std::boolalpha >> area.oven_bath;
                }
            }
        }
        std::cout << "Input about house" << std::endl << "input house's space" << std::endl;
        std::cin >> area.house.space_house;
        space_area += area.house.space_house;
        std::cout << "input floor's count" << std::endl;
        std::cin >> area.house.floor_count;
        for (int k = 0; k < area.house.floor_count; k++) {
            std::cout << "input floor's high" << std::endl;
            std::cin >> area.house.some_floor.high;
            std::cout << "input floor's " <<k+1<<"room" <<std::endl;
            std::cin >> area.house.some_floor.room_count;
            for (int z = 0; z < area.house.some_floor.room_count; z++) {
                std::cout << "Input room's " <<z+1<<" name" << std::endl;
                std::cin >> area.house.some_floor.some_room.name;
                type_of_room(type_room,area.house.some_floor.some_room.name);
                std::cout << "Input room's space" << std::endl;
                std::cin >> area.house.some_floor.some_room.space;
            }
        }
        std::cout << "Input oven's" << std::endl;
        std::cin >> std::boolalpha >> area.house.oven;
    }
    std::cout<<space_area*100/space_village<<"%"<<std::endl;
    return 0;
}
