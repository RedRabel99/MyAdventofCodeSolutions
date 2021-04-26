#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
struct Pair{
    std::string name;
    int value, id;
    bool visited;
    Pair(std::string name, int value){
        this->name = name;
        this->value = value;
        visited = false;
    }
    Pair(std::string name, int value, int id){
        this->name = name;
        this->value = value;
        visited = false;
    }
};

int main() {
    std::fstream file("file.txt");
    std::string input;
    std::stringstream ss;
    std::vector<Pair> my_vector;
    int acc = 0;
    while (getline(file, input)) {
        ss << input;
        std::string name;
        int value;
        ss >> name >> value;
        my_vector.emplace_back(name, value);
        ss.clear();
    }
    int i = 0;
    std::vector<int> j;
    while (i < my_vector.size()) {
        std::string name = my_vector.at(i).name;
        int value = my_vector.at(i).value;
        bool visited = my_vector.at(i).visited;
        if (!my_vector.at(i).visited) {
            if (my_vector.at(i).name == "acc") {
                j.push_back(i);
                acc += my_vector.at(i).value;
                my_vector.at(i).visited = true;
            } else if (my_vector.at(i).name == "jmp") {
                j.push_back(i);
                my_vector.at(i).visited = true;
                i += my_vector.at(i).value;
                continue;
            } else {
                j.push_back(i);
                my_vector.at(i).visited = true;
            }
            i++;
        } else break;
    }
    std::cout << "Part 1: " << acc << "\n" << my_vector.at(j.at(j.size()-3)).name;

    int x = 1;
    int size = j.size();
    while( 0 < j.size() - x){

        if(my_vector.at(j.at(size -x)).name == "jmp"){
            my_vector.at(j.at(size -x)).name = "nop";
        } else if(my_vector.at(j.at(size -x)).name == "nop"){
            my_vector.at(j.at(size -x)).name = "jmp";
        }

        i = 0;
        acc =0;
        for(auto &n : my_vector){
        n.visited = false;
        }
        bool works = true;
        while (i < my_vector.size()) {
            if (!my_vector.at(i).visited) {
                if (my_vector.at(i).name == "acc") {
                    acc += my_vector.at(i).value;
                    my_vector.at(i).visited = true;
                } else if (my_vector.at(i).name == "jmp") {
                    my_vector.at(i).visited = true;
                    i += my_vector.at(i).value;
                    continue;
                } else {
                    my_vector.at(i).visited = true;
                }
                i++;
            } else{
                works = false;
                break;
            }

        }
        if(works){
            break;
        }
        if(my_vector.at(j.at(size -x)).name == "jmp"){
            my_vector.at(j.at(size -x)).name = "nop";
        } else if(my_vector.at(j.at(size -x)).name == "nop"){
            my_vector.at(j.at(size -x)).name = "jmp";
        }
        x++;
    }
    for(auto &w : j) {
        std::cout << w << "\n";
    }

    std::cout<<"Part 2: "<<acc<<"\n"<<size<<" "<<x;
    return 0;
}
