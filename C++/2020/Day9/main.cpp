#include <iostream>
#include <fstream>
#include <vector>

bool has_sum(std::vector<long long> my_vector,int start, int end, int sum);
void check_range(std::vector<long long> &list, std::vector<long long> my_vector, long long key, int index);
long long min_max_sum(const std::vector<long long>& list, long long key);

int main() {
    std::fstream file("file.txt");
    std::vector<long long> my_vector, list;
    std::string input;

    while(getline(file, input)){
        my_vector.push_back(stoll(input));
    }

    long long result = 0;
    int i;
    for( i = 25; i < my_vector.size(); ++i){
            if(!has_sum(my_vector, i - 25, i, my_vector.at(i))){
                std::cout<< "Part 1: " << my_vector.at(i) << "\n";
                result = my_vector.at(i);
                break;
            }
    }

    check_range(list, my_vector, result, i);
    std::cout<< "Part 2: " << min_max_sum(list, result);

    return 0;
}
bool has_sum(std::vector<long long> my_vector,int start, int end, int sum){
    for(int i = start; i < end - 1 ; ++i){
        for(int j = i + 1; j < end; ++j){
            if(my_vector.at(i) + my_vector.at(j) == sum) return true;
        }
    }
    return false;
}

void check_range(std::vector<long long> &list, std::vector<long long> my_vector, long long key, int index){
    for(int i = 0; i < index -1; ++i){
        long long sum = my_vector.at(i);
        for(int j = i + 1; j < index; ++j){
            sum += my_vector.at(j);
            if(sum == key){
                for(int n = i; n <= j;++n){
                    list.push_back(my_vector.at(n));
                }
                return;
            } else if(sum> key) break;
        }
    }
}

long long min_max_sum(const std::vector<long long>& list, long long key){
    long long max = 0, min = key;
    for(auto &i : list){
        if(max < i ) max = i;
        if(min > i) min = i;
    }
    return min + max;
}