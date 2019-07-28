#include <iostream>
#include <vector>

std::vector<int> rotate(std::vector<int> myVector, int direction, int count);
std::vector<int> rotate(std::vector<int> myVector, int direction);
void print(std::vector<int> rotatedVector);


int main(){

    // Array to rotate
    int arr[5] = {1,2,3,4,5};

    // Times to rotate
    const int count = 2;


    int n = sizeof(arr) / sizeof(arr[0]); 
    std::vector<int> myVector(arr, arr + n); 

    enum direction  {left = -1, right = 1};

    myVector = rotate(myVector, left, count);

    print(myVector);


    return 0 ;
}

void print(const std::vector<int> &rotatedVector) {
    for (int v: rotatedVector){
        std::cout << v << '\n';
    }
}

std::vector<int> rotate(std::vector<int> myVector, int direction, int count){

    while(count > 0){
        myVector = rotate( myVector,  direction);
        --count;
    }

    return myVector;
}

std::vector<int> rotate(const std::vector<int> myVector, int direction){

    const int length = myVector.size();

    std::vector<int> rotatedVector(length);

    for(int i = 0; i < myVector.size(); i++){
        rotatedVector.at(i) = myVector.at((length+i-direction)%length);
    }

    return rotatedVector;
}