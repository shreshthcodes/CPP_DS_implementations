#include <iostream>
#include<cstring>
using namespace std;
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, string val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }
};
template <typename T>
class hashtable
{
    Node<T> **table; // this will be pointing to array of pointers i.e each pointer in this array points to a linked list of 'Node'
    int table_size;
    int current_size;
    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

public:
    hashtable(int ts)
    {
        table_size = ts;
        current_size = 0;
        table = new Node<T> *[table_size];
        for (int i = 0; i < table_size; i++)
            table[i] = NULL;
    }
    void insert(string key, T val)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key,val);
        n->next = table[idx];
        table[idx] = n;
        current_size++;
    }
    void print()
    {
        for (int i = 0; i < table_size - 1; i++)
        {
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    hashtable<int> obj(7);
    obj.insert("burger", 45);
    obj.insert("maggi", 85);
    obj.insert("pepsi", 35);
    obj.insert("fries", 100);
    obj.insert("thali", 335);
    obj.print();
    return 0;
}