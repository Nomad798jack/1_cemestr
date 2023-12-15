//Ввести последовательность натуральных чисел.
//Если в последовательности нет чисел, начинающихся цифрой 7, упорядочить последовательность по возрастанию
//.В противном случае удалить из последовательности простые числа и продублировать четные числа.
//Последовательность хранить в односвязном списке.


#include <iostream>
#include <cmath>

struct Node {
    int data;
    Node* next;
};

void Add(Node*& root, int data)
{
    if (root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->next = nullptr;
        return;
    }
    Node* p = new Node;
    p->data = data;
    p->next = root->next;
    root->next = p;
}

void AddBack(Node* root, int data)
{
    Node* q = root;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    Add(q, data);
}

bool Prime(int val) {
    if (val <= 1)
        return false;
    else
    {
        for (int d = 2; d <= sqrt(val); d++)
            if (val % d == 0)
                return false;
        return true;
    }
}

bool FirstNumber7(int data)
{
    int first = 0;
    while (data > 0)
    {
        first = data % 10;
        data = data / 10;
    }
    if (first == 7) {
        return true;
    }
    else {
        return false;
    }
}

bool MaySort(Node* root)
{
    Node* p = root;
    while (p != nullptr)
    {
        if (FirstNumber7(p->data))
            return false;
        p = p->next;
    }
    return true;
}

void Sort(Node* root)
{
    Node* p = root->next;
    while (p != nullptr)
    {
        Node* q = root->next;
        while (q != nullptr)
        {
            if (p->data < q->data)
                std::swap(p->data, q->data);
            q = q->next;
        }
        p = p->next;
    }

}

void DeletePrime(Node* root)
{
    Node* q = root;
    Node* p = root->next;
    while (p != nullptr)
    {
        if (Prime(p->data))
        {
            q->next = p->next;
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
} 

void Duplicate(Node* root)
{

    Node* p = root->next;
    while (p != nullptr) {
        if ((p->data)%2==0) {
            Add(p, p->data);
            p = p->next;
        }
        p = p->next;
    }
}

void Print(Node* root)
{
    Node* p = root->next;
    while (p != nullptr)
    {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

void Erase(Node* root)
{
    Node* p = root->next;
    Node* q = p;
    while (p != nullptr)
    {
        q = p->next;

        delete q;
        p = p->next;
    }
    delete root;
}


int main()
{
    Node* root = new Node;
    root->next = nullptr;

    AddBack(root, 701);
    AddBack(root, 40);
    AddBack(root, 244);
    AddBack(root, 63);
    AddBack(root, 13);
    AddBack(root, 17);

    if (MaySort(root))
    {
        Sort(root);
    }
    else
    {
        DeletePrime(root);
        Duplicate(root);
    }

    Print(root);
    Erase(root);
    return 0;



}