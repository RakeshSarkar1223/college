#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int p;
    int d;
    struct Node *next;
};

// this is wrong
//  int position(struct Node * head, struct Node * tail){
//      struct Node * temp = head;
//      int i = 1;
//      while(1){
//          if(temp == tail){
//              if(temp->d < temp->p){
//                  printf("%d",i);
//              }
//              break;
//          }
//          else {
//              if(temp->d < temp->p){
//                  printf("%d",i);
//                  break;
//              }
//          }
//          i++;
//          temp = temp->next;
//      }
//  }