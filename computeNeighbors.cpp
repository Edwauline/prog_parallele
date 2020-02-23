#include <iostream>
#include <vector>
#include "computeNeighbors.hpp"

int power(int base, int exposant){
  int cpt=0;
  int res=1;
  while(cpt<exposant){
    res=res*2;
    cpt+=1;
  }
  return res;
}

int logarithme(int node){
  int p=0;
  while(power(2,p+1)<=node){
    p+=1;
  }
  return p;
}

// messages are received from node with highest 1-bit flipped to 0
int computePredecessor(int node) {
  if(node==0){
    return 0;
  }
  else{
    int tours=logarithme(node);
    int pred=node-power(2,tours);
    return pred;
  }
  return -1;
}

// compute neighbors to communicate to
std::vector<int> computeOutNeighbors(int node, int numberNodes) {
  std::vector<int> neighbors;

  // first bit to flip
  int flipbit = (node - computePredecessor(node)) * 2;
  //std::cout << "log: " << logarithme(node) << std::endl;
  int cpt=1;

  // TODO
  int next_pow=logarithme(node);
  //std::cout <<"next_pow="<<node+power(2,next_pow) << std::endl;
  while (node+power(2,next_pow)<numberNodes){
    if(node==0 || cpt>1){
      neighbors.push_back(node+power(2,next_pow));
    }
    next_pow+=1;
    cpt+=1;
  }

  return neighbors;
}

// print neighbor list for debugging
void printNeighbors(std::vector<int> neighbors) {
  for (std::vector<int>::iterator iter = neighbors.begin();
       iter != neighbors.end(); iter++) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
}
