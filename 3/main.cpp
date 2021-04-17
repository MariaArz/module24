//Сложение двух векторов — команда add.
//Вычитание двух векторов — команда subtract.
//Умножение вектора на скаляр — команда scale.
//Нахождение длины вектора — команда length.
//Нормализация вектора — команда normalize.


#include <iostream>
#include <cmath>

struct vector{
    double x=0, y=0;
    double x1=0, y1=0;
    double n=0;
    double length=0;
    double  normX=0, normY=0;
    double  nx=0, ny=0;
};
int main() {
    vector vec;
    std::string command;
    std::cout<<"input command"<<std::endl;
    std::cin>>command;
    if (command=="add"){
        std::cout<<"Coordinate 1 vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Coordinate 2 vector"<<std::endl;
        std::cin>>vec.x1>>vec.y1;
        std::cout<<"Vector ("<<vec.x+vec.x1<<";"<<vec.y+vec.y1<<")"<<std::endl;
    }
    else if (command=="subtract"){
        std::cout<<"Coordinate 1 vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Coordinate 2 vector"<<std::endl;
        std::cin>>vec.x1>>vec.y1;
        std::cout<<"Vector ("<<vec.x-vec.x1<<" ;"<<vec.y-vec.y1<<")"<<std::endl;
    }
    else if (command=="scale"){
        std::cout<<"Coordinate vector and number"<<std::endl;
        std::cin>>vec.x>>vec.y>>vec.n;
        vec.nx=vec.n*vec.x;
        vec.ny=vec.n*vec.y;
        std::cout<<"Vector ("<<vec.nx<<" ;"<<vec.ny<<")"<<std::endl;
    }
    else if (command=="length"){
        std::cout<<"Coordinate vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        vec.length=sqrt(vec.x*vec.x+vec.y*vec.y);
        std::cout<<"Length = "<< vec.length <<std::endl;
    }
    else if (command=="normalize"){
        std::cout<<"Coordinate vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        vec.normX=vec.x/sqrt(vec.x*vec.x+vec.y*vec.y);
        vec.normY=vec.y/sqrt(vec.x*vec.x+vec.y*vec.y);
        std::cout<<"Vector ("<<vec.normX<<" ;"<<vec.normY<<")"<<std::endl;
    }
    else {
        std::cout<<"Wrong! This command is not"<<std::endl;
    }
    return 0;
}
