//Сложение двух векторов — команда add.
//Вычитание двух векторов — команда subtract.
//Умножение вектора на скаляр — команда scale.
//Нахождение длины вектора — команда length.
//Нормализация вектора — команда normalize.


#include <iostream>
#include <cmath>

struct vector{
    double x=0, y=0;
};
void add(double x, double y, double x1, double y1){
    std::cout<<"Vector ("<<x+x1<<";"<<y+y1<<")"<<std::endl;
}
void subtract(double x, double y, double x1, double y1){
    std::cout<<"Vector ("<<x-x1<<";"<<y-y1<<")"<<std::endl;
}
void scale (double  n, double x, double  y){
    std::cout<<"Vector ("<<n*x<<" ;"<<n*y<<")"<<std::endl;
}
void normalize(double x, double y){
    std::cout<<"Vector: ("<< x/sqrt(x*x+y*y) <<"; "<<y/sqrt(x*x+y*y)<<")"<<std::endl;
}
double length(double x, double y){
    return sqrt(x*x+y*y);
}

int main() {
    double n;
    vector vec,vec1;
    std::string command;
    std::cout<<"input command"<<std::endl;
    std::cin>>command;
    if (command=="add"){
        std::cout<<"Coordinate 1 vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Coordinate 2 vector"<<std::endl;
        std::cin>>vec1.x>>vec1.y;
        add(vec.x,vec.y, vec1.x, vec1.y);
    }
    else if (command=="subtract"){
        std::cout<<"Coordinate 1 vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Coordinate 2 vector"<<std::endl;
        std::cin>>vec1.x>>vec1.y;
        subtract(vec.x,vec.y,vec1.x,vec1.y);
    }
    else if (command=="scale"){
        std::cout<<"Coordinate vector and number"<<std::endl;
        std::cin>>vec.x>>vec.y>>n;
        scale(n, vec.x, vec.y);
    }
    else if (command=="length"){
        std::cout<<"Coordinate vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Length = "<< length(vec.x,vec.y) <<std::endl;
    }
    else if (command=="normalize"){
        std::cout<<"Coordinate vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        normalize(vec.x,vec.y);
    }
    else {
        std::cout<<"Wrong! This command is not"<<std::endl;
    }
    return 0;
}
