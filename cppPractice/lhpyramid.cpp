//NOT WHAT I WANTED! RETRY LATER!!!!



// #include <iostream>

// void spaces(int iteration){
//     if (iteration == 0){
//         return;
//     }
//     else{
//         std::cout<< " ";
//         spaces(iteration-1);
//     }
// }

// void stars(int iteration){
//     if (iteration == 0){
//         return;
//     }
//     else{
//         std::cout<< "*";
//         stars(iteration-1);
//     }
// }

// void lhPyramid(int rows, int presentRow){
//     if (presentRow>rows){
//         return;
//     }
//     else{
//         stars(rows-presentRow);
//         spaces(rows-presentRow);
//         std::cout<< "\n";
//         lhPyramid(rows, presentRow+1);
//     }
// }

// int main(){
//     int rows;
//     std::cout<< "Enter the number of rows: ";
//     std::cin>> rows;
//     lhPyramid(rows, 1);
//     return 0;
// }