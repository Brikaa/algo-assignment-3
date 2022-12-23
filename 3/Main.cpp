#include <iostream>
#include <string>
#include "Human.h"

Human* intialize(int& k, int& n, Human* arr){
        std::cout << "Please enter the size of the array : ";
        while(true){
            while(!(std::cin >> n)){
                std::cin.clear();
                std::cin.ignore(100,'\n');
                std::cout << "Please enter a valid numeric input : ";
            }
            if(n >= 0)
               break;
            else
               std::cout << "Please enter a value greater than or equal to zero : ";

        }
        std::cout << "Please enter the unit range for the policemen : ";
        while(true){
            while(!(std::cin >> k)){
                std::cin.clear();
                std::cin.ignore(100,'\n');
                std::cout << "Please enter a valid numeric input : ";
            }
            if(k >= 0)
               break;
            else
               std::cout << "Please enter a value greater than or equal to zero : ";

        }
        
    std::string choice;
    arr = new Human[n];
    for (int i = 0; i<n; i++){
        std::cout << "Please enter the P for policeman and T for thief : ";
        std::cin >> choice;
        while(true){
           if(choice == "P" || choice == "p") {
             arr[i].type = "police";
             break;
           }else if (choice == "T" || choice == "t") {
             arr[i].type = "thief";
             break;
           }else {
              std::cout << "please enter a valid choice : ";
              std:: cin >> choice;
           }

        }

    }

    return arr;
}
int main() {
    int k, n, max = 0;
    Human* arr;
    arr = intialize(k,n, arr);
    std::cout << "\n";

    if(n == 0 || n == 1){
        std::cout << "Maximum Number of thieves to be caught = 0 \n";
        return 0;
    }

    for (int i=0; i<n; i++){
        if(arr[i].type != "police")
           continue;

        int targetIndex1, distance1 = -1, targetIndex2, distance2 = -1;
        Human* larr = new Human[i];
        Human* rarr = new Human[n-(i+1)];

        for(int a = 0; a<i; a++){
            larr[a] = arr[a];
        }

        for (int b=0; b<(n-(i+1)); b++){
            int index = b + (i + 1);
            rarr[b]= arr[index];
        }

        for(int j=0; j<i; j++){
            if(larr[j].type == "thief" && larr[j].isActive == true && k >= (i-j)){
               targetIndex1 = j;
               distance1 = i-j;
               break;
            }
        }

        for(int l = (n-(i+2)); l>=0; l--){

            if((n-(i+1)) == 0)
               break;
            if((rarr[l].type == "thief" && rarr[l].isActive == true && k >= (l+1))){
                if((l != 0) && ((l != 0 && rarr[l-1].type == "police" && rarr[l-1].isActive == true) || (l != (n-(i+2)) && rarr[l+1].type == "police" && rarr[l+1].isActive == true))){
                    continue;
                }
                else{
                    targetIndex2 = l+(i+1);
                    distance2 = l+(i+1)-i;
                    break;
                }
            }
        }

        if(distance1 == -1 && distance2 == -1){
            // can't catch anyone
            continue;
        }else if(distance1 == -1){
            // no left
            arr[targetIndex2].isActive = false;
        }else if(distance2 == -1){
            // no right
            arr[targetIndex1].isActive = false;
        }else{
            // both avaliable picks furthest first
            if(distance1 >= distance2){
               arr[targetIndex1].isActive = false;
            }
            else{
               arr[targetIndex2].isActive = false;
            }
        }
        arr[i].isActive = false;
    }

    for (int i = 0 ; i<n; i++){
        if(arr[i].type == "thief" && arr[i].isActive == false)
           max++;
    }

    std::cout<< "Maximum number of thieves to be caught = "<< max <<"\n";
    return 0;
}
