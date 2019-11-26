//Coding reference: https://www.tutorialspoint.com/Floyd-Warshall-Algorithm

#include<iostream>
#include<iomanip>
#define NODE 6
#define INF 999
#define matwidth 7
using namespace std;

//Cost matrix of the graph
int costMat[NODE][NODE] = {
   {0, 4, 5, INF, INF, 10},
   {-3, 0,INF, 3, INF, INF},
   {9,INF, 0, INF, INF, 4},
   {INF, -2, INF, 0, 12,3},
   {INF, INF, 2, -5, 0, INF},
   {INF, 3, INF, INF, 4, 0},
};

void printMat(int a[NODE][NODE]){
    for(int i = 0; i<NODE; i++) {
      for(int j = 0; j<NODE; j++)
         a[i][j]==INF?cout<<setw(matwidth)<<"INF":cout << setw(matwidth) << a[i][j];
      cout << endl;
   }
} 

void floydWarshal() {
    cout<<"Original Matrix\n";
    printMat(costMat);
    
   int cost[NODE][NODE];    //defind to store shortest distance from any node to any node
   for(int i = 0; i<NODE; i++)
      for(int j = 0; j<NODE; j++)
         cost[i][j] = costMat[i][j];     //copy costMatrix to new matrix

   for(int k = 0; k<NODE; k++) {
      for(int i = 0; i<NODE; i++){
         for(int j = 0; j<NODE; j++)
            if(cost[i][k]+cost[k][j] < cost[i][j])
               cost[i][j] = cost[i][k]+cost[k][j];
      }
      cout<<k<<endl;
      printMat(cost);
        cout<<endl;
   }
   
   

   cout << "The matrix:" << endl;
    printMat(cost);
}

int main() {
   floydWarshal();
}
