#include <iostream>
#include <fstream>
#include <string>
struct pay_list {
    std::string name="uknown";
    std::string date="00.00.00";
    double  money=0;
};
bool check (pay_list& person){
    if ((std::stoi(person.date.substr(6)) < 0 || std::stoi(person.date.substr(6)) > 2021)
        || (std::stoi(person.date.substr(3,2)) < 0 || std::stoi(person.date.substr(3,2)) > 12)
        || (std::stoi(person.date.substr(0,2)) < 0 || std::stoi(person.date.substr(0,2)) > 32)
        || ((std::stoi(person.date.substr(3,2)) == 02
             && (std::stoi(person.date.substr(0,2)) < 0 || std::stoi(person.date.substr(0,2)) > 29)))) {
        return false;
    }
    return true;
}
void add (std::ofstream& add, pay_list& person){
    add<< std::endl <<person.name<< " " <<person.date << " " <<person.money;
}
void list (std::ifstream& list, pay_list& person){
    while (!list.eof()){
        list>>person.name;
        if (person.name.length()!=0){
            list>>person.date>>person.money;
            std::cout<<person.name<<" "<<person.date<<" "<<person.money<< std::endl;
        }

    }
}

int main() {
    pay_list person;
    std::string command;
    std::cout <<"Input command"<<std::endl;
    std::cin>>command;
    std::ofstream write("..\\pay_list.txt",std::ios::app);
    write.close();
    std::ifstream read;
    if (command == "add"){
        write.open("..\\pay_list.txt",std::ios::app);
        std::cout <<"Input person"<<std::endl;
        std::cin>>person.name;
        std::cin>>person.date;
        std::cin>>person.money;
        if (check(person)){
            add(write, person);
        }
        else {
            std::cout<<"Try again";
        }
        write.close();
    }
    else if (command == "list"){
        read.open("..\\pay_list.txt", std::ios::binary);
        list(read, person);
        read.close();
    }
    else {
        std::cout<<"Try again";
    }

    return 0;
}
