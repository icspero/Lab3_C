#include <iostream>
#include "SinLinList.h"
#include "header.h"
#include <string>

using namespace std;

int main(){

    SinglyLinkedList list;

    list.LONEPUSH_head(elem1);
    list.LONEPUSH_tail(elem2);
    list.LONEPUSH_tail(elem3);

    int size = list.Size();

    cout << size << endl;

    list.LONE_read();

}