#include <iostream> 
using namespace std; 
struct Node 
{ 
    string data; 
    Node *next; 
}; 
Node *front = NULL; 
Node *back = NULL; 
bool isEmpty() 
{ 
    return (front == NULL); 
} 
void enqueueAntrian(string data) 
{ 
    Node *temp = new Node(); 
    temp->data = data; 
    temp->next = NULL; 
    if (front == NULL && back == NULL) 
    { 
        front = back = temp; 
        return; 
    } 
    back->next = temp; 
    back = temp; 
} 
void dequeueAntrian() 
{ 
    if (isEmpty()) 
    { 
        cout << "antrian kosong" << endl; 
        return; 
    } 
    Node *temp = front; 
    if (front == back) 
    { 
        front = back = NULL; 
    } 
    else 
    { 
        front = front->next; 
    } 
    delete temp; 
} 
int countQueue() 
{ 
    int count = 0; 
    Node *temp = front; 
    while (temp != NULL) 
    { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 
void clearQueue() 
{ 
    if (isEmpty()) 
    { 
        cout << "antrian kosong" << endl; 
        return; 
    } 
    Node *temp = front; 
    while (temp != NULL) 
    { 
        front = front->next; 
        delete temp; 
        temp = front; 
    } 
} 
void viewQueue() 
{ 
    cout << "data antrian teller : " << endl; 
    Node *temp = front; 
    int i = 1; 
    while (temp != NULL) 
    { 
        cout << i << "." << temp->data << endl; 
        i++; 
        temp = temp->next; 
    } 
} 
int main() 
{ 
    enqueueAntrian("Dani"); 
    enqueueAntrian("Daffa"); 
enqueueAntrian("John Cena"); 
viewQueue(); 
cout << "jumlah antrian = " << countQueue() << endl; 
dequeueAntrian(); 
viewQueue(); 
cout << "jumlah antrian = " << countQueue() << endl; 
clearQueue(); 
viewQueue(); 
cout << "jumlah antrian = " << countQueue() << endl; 
return 0; 
}  