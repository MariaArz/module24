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
double add(double x, double y){
    return (x+y);
}
double subtract(double x, double y){
    return (x-y);
}
double scale (double  n, double x){
    return n*x;
}
double normalize(double x, double y){
    return x/sqrt(x*x+y*y);
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
        std::cout<<"Vector ("<<add(vec.x,vec1.x)<<";"<<add(vec.y,vec1.y)<<")"<<std::endl;
    }
    else if (command=="subtract"){
        std::cout<<"Coordinate 1 vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Coordinate 2 vector"<<std::endl;
        std::cin>>vec1.x>>vec1.y;
        std::cout<<"Vector ("<<subtract(vec.x,vec1.x)<<" ;"<<subtract(vec.y,vec1.y)<<")"<<std::endl;
    }
    else if (command=="scale"){
        std::cout<<"Coordinate vector and number"<<std::endl;
        std::cin>>vec.x>>vec.y>>n;
        std::cout<<"Vector ("<<scale(n,vec.x)<<" ;"<<scale(n,vec.y)<<")"<<std::endl;
    }
    else if (command=="length"){
        std::cout<<"Coordinate vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Length = "<< length(vec.x,vec.y) <<std::endl;
    }
    else if (command=="normalize"){
        std::cout<<"Coordinate vector"<<std::endl;
        std::cin>>vec.x>>vec.y;
        std::cout<<"Vector ("<<normalize(vec.x,vec.y)<<" ;"<<normalize(vec.y,vec.x)<<")"<<std::endl;
    }
    else {
        std::cout<<"Wrong! This command is not"<<std::endl;
    }
    return 0;
}
