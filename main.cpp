//HW1 by Dane Brazinski
//SU Net ID: dbbrazin SUID: 533140379
//Implement the three member functions new_reverse, new_sort and removeAll.

//Linked List Operations
#include <iostream>//cin and cout
using namespace std;
class Node {
public:
    int value;
    Node* next;
    Node() { next = nullptr; }//default constructor
    Node(int i) { value = i; next = nullptr; }//constructor

};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }
    void makeList(int m, int n);//create a linked list of m nodes with
    //values randomly distrubuted in 0..n-1
    void printList();
    void new_reverse(); //You are only allowed to modify "values" of nodes, but not "next"
    //You have to directly work on the linked list.  You are not allowed to use
    //external structures such as array or linked list to perform operations.

    void new_sort();//Sorting -- Only modify pointers (next or temporary pointers).
    //Changes of values of nodes are not allowed.
    //You are not allowed to use external structures such as array or linked list
    //to perform operations and transfer the values back to the linked list.

    void removeAll(int k);//Remove all nodes with value k


};
void LinkedList::makeList(int m, int n) {
    for (int i = 0; i < m; i++) {
        Node* p = new Node(rand() % n);
        p->next = head;
        head = p;
    }
}

void LinkedList::printList() {
    Node* p = head;
    cout << endl;
    while (p) { cout << p->value << " ";  p = p->next; }
}

void LinkedList::new_reverse() {
//You need to implement this function.
    if (!head || !head->next) return;//if 0 or 1 node, return;
    Node* p1 = head, *p2 = head;
    int p1Value, temp, size = 0;
    while(p1->next != nullptr){ //loop to calculate the size of the LinkedList
        p1 = p1->next;
        size++;
    }
    p1 = head;
    p1Value = p1->value;
    int j = size;
    while(size != j/2){
        for(int i = 0; i < size; i++){
            p2 = p2->next;
        }
        temp = p2->value;
        p2->value = p1Value;
        p1->value = temp;
        p1 = p1->next;
        p1Value = p1->value;
        p2 = head;
        size--;
    }

}
void LinkedList::new_sort() { //selection sort
//You need to implement this function.
    if (!head || !head->next) return;//if 0 or 1 node, return;
    Node* p1 = head, * p2, * p3, *p4;
    int min, cMin = -1, count;
    Node* p_min = nullptr, *cP_min = nullptr;
    bool skip = false;
   // while(unsorted) {
        while (p1) { //find min value
            min = p1->value;
            p_min = p1;
            p2 = p1->next;
            while (p2) {
                if (p2->value < min) {
                    min = p2->value;
                    p_min = p2;
                }
                p2 = p2->next;
            }
            cMin = min; //set current min
            cP_min = p_min; //current pointer min
            break;
        }
        if(cP_min != head){
            p3 = head;
            head = cP_min;
            cP_min->next = p3;
            count = 0;
            p1 = head;
            while (p1) {
                if (p1->next == cP_min->next) {
                    p1->next = nullptr;
                    break;
                }
                p1 = p1->next;
            }
        }
//        p3 = head;
//        head = p_min;
//        head->next = p3;

        p1 = head->next;
        while (cP_min->next) {
            min = p1->value;
            if (cMin == min) {
                p1 = p1->next;
                continue;
            }
            p_min = p1;
            p2 = p1->next;
            while (p2) {
                if (p2->value < min && p2->value >= cMin) {
                    min = p2->value;
                    p_min = p2;
                }
                p2 = p2->next;
            }

            if (cP_min->next != p_min ){ //not already pointing to next value
                if (p_min->next != nullptr) { //not pointing to null
                    p3 = p_min->next;

                    while (p3->next) {
                        p3 = p3->next;
                    }
                    p4 = cP_min->next;
                    p3->next = p4;
                }
                else {
                    p3 = p_min;
                    p4 = cP_min->next;
                    p3->next = p4;
                }
            cP_min->next = p_min;
            //p_min = p_min->next;
            p1 = head;
            count = 0;
            while (p1) {
                if (p1->next == cP_min->next && count++ == 1) {
                    p1->next = nullptr;
                    break;
                }
                p1 = p1->next;
            }
        }
            cMin = min;
            cP_min = p_min;
            p2 = p_min;
            p1 = p2->next;
        }
    }
//}

void LinkedList::removeAll(int k) {
//You need to implement this function.
    while (true) {
        if (!head) return;//if 0 node in the linked list
        Node *p1 = head, *p2, *p3;
        if (head->value == k) {
            head = head->next;
            delete p1;
            continue;
        }
        p2 = p1->next;
        while (p2) {
            if (p2->value == k) {
                p1->next = p2->next;
                p3 = p2;
                delete p3;
                p2 = p2->next;
                continue;
            }
            p1 = p2;
            p2 = p2->next;
        }
        break;
    }
}

//Different test cases will be used during grading
//Need to pay special attention to bounary cases



int main() {
    LinkedList L1;
    L1.makeList(9, 60);
    L1.printList();
    L1.new_reverse();
    L1.printList();
    L1.new_sort();
    L1.printList();
    L1.removeAll(38);
    L1.printList();
    return 0;
}

