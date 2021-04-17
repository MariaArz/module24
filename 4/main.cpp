#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct character {
    std::string  name="uknown";
    int armor=0;
    int health=0;
    int damage=0;
    int x=0,y=0;
};
void map(std::ofstream& game, character person[6]){
    for (int i=0; i < 40; i++){
        for (int j=0; j < 40; j++){
            for (int k=0; k < 5; k++){
                if (i==person[k].x && j == person[k].y){
                    game<<"E";
                    j++;
                }
            }
            if (i==person[5].x && j == person[5].y){
                game<<"P";
            }
            else game<<".";
        }
        game<<std::endl;
    }
}
void game_now(std::ifstream& in_game){
    char buffer[5000];
    while (!in_game.eof()){
        in_game.read(buffer,sizeof(buffer));
        buffer[4999]='0';
        std::cout<<buffer;
    }
}
void gamers(character person[6]){
    for (int i=0; i < 6; i++){
        std::cout<<person[i].name<<" health: "<<person[i].health<<" armor: "<<person[i].armor<<" damage:"<<person[i].damage<<std::endl;
    }
}
bool death(character person[6]){
    bool health;
    for (int i=0; i < 5; i++){
        health=true;
        if (person[i].health==0) health=false;
    }
    if (person[5].health==0) health=false;
    return health;
}
int main() {
    std::string  command;
    std::ofstream game("..\\game.bin", std::ios::binary);
    std::ifstream  in_game;
    character person[6];
    for (int i=0; i < 5; i++){
        person[i].name="Enemy #"+std::to_string(i);
        person[i].health=(std::rand()%151)+50;
        person[i].damage=(std::rand()%31)+15;
        person[i].armor=std::rand()%51;
        person[i].x=std::rand()%41;
        person[i].y=std::rand()%41;
    }
    std::cout<<"Input your player"<<std::endl;
    std::cin>>person[5].name>>person[5].health>>person[5].armor>>person[5].damage;
    person[5].x=std::rand()%41;
    person[5].y=std::rand()%41;
    gamers(person);
    map(game,person);
    game.close();
    while (death(person)){
        std::cout<<"\nInput command"<<std::endl;
        std::cin>>command;
        if (command=="right"){
            person[5].y+=1;
        }
        else if (command=="left"){
            person[5].y-=1;
        }
        else if (command=="top"){
            person[5].x-=1;
        }
        else if (command=="bottom"){
            person[5].x+=1;
        }
        else if (command=="save"){
            map(game,person);
        }
        else if (command=="load"){
            in_game.open("..\\game.bin", std::ios::binary);
            if (in_game.is_open()){
                game_now(in_game);
                in_game.close();
            }
        }
        for (int i=0; i < 6; i++){
            if (person[i].x > 39 || person[i].x < 0
               || person[i].y > 39 || person[i].y < 0){
                if (person[i].x > 39) person[i].x-=1;
                else if (person[i].x < 0) person[i].x+=1;
                else if (person[i].y > 39) person[i].y-=1;
                else if (person[i].x < 0) person[i].y+=1;
                continue;
            }
        }
        for (int i=0; i < 5; i++){
            int a=std::rand()%3-1, b=std::rand()%3-1;
            if (a!=0) person[i].x+=a;
            else if (a == 0 && b!=0) person[i].y+=b;
            if (person[5].x==person[i].x && person[5].y==person[i].y){
                person[5].armor-=person[5].damage;
                if (person[5].armor==0){
                    person[5].health-=person[5].damage;
                }
                person[i].armor-=person[i].damage;
                if (person[i].armor==0){
                    person[i].health-=person[i].damage;
                }
            }
            if (person[i-1].x==person[i].x && person[i-1].y==person[i].y){
                if (a!=0) person[i].x-=a;
                else if (a==0 && b!=0) person[i].y-=b;
            }
        }
        game.open("..\\game.bin", std::ios::binary);
        map(game,person);
        game.close();
        gamers(person);
        in_game.open("..\\game.bin", std::ios::binary);
        if (in_game.is_open()){
            game_now(in_game);
            in_game.close();
        }
    }

    return 0;
}
