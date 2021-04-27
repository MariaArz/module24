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
void add(vector& vec, vector& vec1){
    std::cout<<"Coordinate 1 vector"<<std::endl;
    std::cin>>vec.x>>vec.y;
    std::cout<<"Coordinate 2 vector"<<std::endl;
    std::cin>>vec1.x>>vec1.y;
    std::cout<<"Vector ("<<vec.x+vec1.x<<";"<<vec.y+vec1.y<<")"<<std::endl;
}
void subtract(vector& vec, vector& vec1){
    std::cout<<"Coordinate 1 vector"<<std::endl;
    std::cin>>vec.x>>vec.y;
    std::cout<<"Coordinate 2 vector"<<std::endl;
    std::cin>>vec1.x>>vec1.y;
    std::cout<<"Vector ("<<vec.x-vec1.x<<";"<<vec.y-vec1.y<<")"<<std::endl;
}
void scale (vector& vec, double& n){
    std::cout<<"Coordinate vector and number"<<std::endl;
    std::cin>>vec.x>>vec.y>>n;
    std::cout<<"Vector ("<<n*vec.x<<" ;"<<n*vec.y<<")"<<std::endl;
}
void normalize(vector& vec){
    std::cout<<"Coordinate vector"<<std::endl;
    std::cin>>vec.x>>vec.y;
    std::cout<<"Vector: ("<< vec.x/sqrt(vec.x*vec.x+vec.y*vec.y) <<"; "<<vec.y/sqrt(vec.x*vec.x+vec.y*vec.y)<<")"<<std::endl;
}
void length(vector& vec){
    std::cout<<"Coordinate vector"<<std::endl;
    std::cin>>vec.x>>vec.y;
    std::cout<<"Length = "<<sqrt(vec.x*vec.x+vec.y*vec.y)<<std::endl;
}

int main() {
    double n;
    vector vec,vec1;
    std::string command;
    std::cout<<"input command"<<std::endl;
    std::cin>>command;
    if (command=="add"){
        add(vec, vec1);
    }
    else if (command=="subtract"){
        subtract(vec, vec1);
    }
    else if (command=="scale"){
        scale(vec,n);
    }
    else if (command=="length"){
         length(vec);
    }
    else if (command=="normalize"){
        normalize(vec);
    }
    else {
        std::cout<<"Wrong! This command is not"<<std::endl;
    }
    return 0;
}
