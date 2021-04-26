#include <iostream>
#include <fstream>
int main() {
    std::string input;
    std::fstream file("file.txt");
    int max = 0, min = 1000;
    long sum = 0;
    while(getline(file, input)){
        int min_row = 0, max_row = 127;
        for(int i = 0; i < 7; ++i){
            int mid = (min_row + max_row) / 2;
            switch (input.at(i)){
                case 'F':{
                    max_row = mid;
                    break;
                }
                case 'B':{
                    min_row = mid + 1;
                    break;
                }
            }
        }
        int min_column = 0, max_column = 7;
        for(int i = 7; i < 10; ++i){
            int mid = (min_column+max_column)/2;
            switch (input.at(i)){

                case 'L':{
                    max_column = mid;
                    break;
                }
                case 'R':{
                    min_column = mid + 1;
                    break;
                }
            }
        }
        int id = min_row * 8 + min_column;
        if(id > max) max = id;
        if(id < min) min = id;
        sum +=id;
    }
    long sum2 = 0;
    for(int i = min; i < max +1; ++i){
        sum2 += i;
    }
    std::cout<<max<<" "<<min<<" my id: "<<sum2 - sum;
    return 0;
}
int func(std::string input, int &min, int &max, char low, char top){
    int min_row = 0, max_row = 127;
    for(int i = 0; i < 7; ++i){
        int mid = (min_row + max_row) / 2;
        if(input.at(i) == low) max_row = mid;
        else if(input.at(i) == top) min_row = mid + 1;
    }
    return min_row;
}