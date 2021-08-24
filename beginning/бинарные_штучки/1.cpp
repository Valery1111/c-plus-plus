
#include <iostream>

#include <iostream>
#include <memory>


class A: public std::enable_shared_from_this<A>
{
public:
    // �����������
    A(int key): key(key) {}
    /* ����������, ������ ������������� ���������� �����
       ��������� ��������� ��� �������� ������ */
    ~A()
    {
        /* ��� ������ ������� �� �����, ����� ���� �����,
           ��� ���� �������� */
        std::cout << "Destructor" << std::endl;
    }
    // ���������� ��������� �� ����� �������
    void addLeft(std::shared_ptr<A> &lChild)
    {
        leftChild = lChild;
        leftChild->setParent(shared_from_this());
    }
    // ���������� ��������� �� ������ �������
    void addRight(std::shared_ptr<A> &rChild)
    {
        rightChild = rChild;
        rightChild->setParent(shared_from_this());
    }
    // ���������� ��������� �� ������������ ����
    void setParent(std::shared_ptr<A> parent)
    {
        this->parent = parent;
    }
    std::shared_ptr<A> leftChild; // ��������� �� ����� ����-�������
    std::shared_ptr<A> rightChild; // ��������� �� ������ ����-�������
    std::weak_ptr<A> parent; // ��������� �� ����-��������
    /* ��������� �� ����-�������� ������ weak_ptr, ����� ��������
       ����������� ������������, ����� ������ ����� ��������� ���������
       �� �������� */

    int key; // ���������� ��� �������� �������� � ���� ������
};

// ������� ���������� ���� � ������
std::shared_ptr<A> insert(std::shared_ptr<A> node, int key)
{
    /* ���� ����� ������ (���� ��� �����������, ���� �� �����,
       ���� ��������� ����� ����. ����������� ����� ����� ���
       ������� ���������� �����) */
    if (node == nullptr)
    {
        // TODO: ������� ��������� ������ A, � ����������� �������� key
        //A a1(key);
        A* a1 = new A(key);
        // TODO: ������� shared_ptr � ���������� ����������
        std::shared_ptr<A> ptr1(a1);
        //std::shared_ptr<A> ptr1(&a1);
        // TODO: ������� ���� shared_ptr
        return ptr1;
    }

    // ����������� ����� ����� ��� ������� � �������, ���� �����
    if (key < node->key)
    {
        /* TODO: ����������� ����� ������� insert, ������� ����������
           shared_ptr �� ����� ������� � node */
        A* a2 = new A(key);
        std::shared_ptr<A> ptr2(a2);
        insert(ptr2, key);
        // TODO: �������� � node ����� ������� � ������� ������� addLeft
        node->addLeft(ptr2);
        // TODO: ������� node ������������ ����� ��� ������ �������
    }
    else if (key > node->key)
    {
        /* TODO: ����������� ����� ������� insert, ������� ����������
           shared_ptr �� ������ ������� � node */
        // TODO: �������� � node ������ ������� � ������� ������� addLeft
        // TODO: ������� node ������������ ����� ��� ������� �������
    }

    return node;
}

// ������������ ����� ������
void inorder(std::shared_ptr<A> root)
{
    if (root != nullptr)
    {
        inorder(root->leftChild);
        std::cout << "Node " << root->key;
        if (root->parent.lock() == nullptr)
            std::cout << " Parent: NULL" << std::endl;
        else
            std::cout << " Parent:" << root->parent.lock()->key << std::endl;
        inorder(root->rightChild);
    }
}

int main()
{
    A* root = new A(50); // ������� ������ ������
    std::shared_ptr<A> rootPtr(root); // ������� shared_ptr �� ������
    /* ������� ��������� ������:
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
    */
    // ��� ���������� ������� ���������� ���� �������� ������� insert
    insert(rootPtr, 30);
    insert(rootPtr, 20);
    insert(rootPtr, 40);
    insert(rootPtr, 70);
    insert(rootPtr, 60);
    insert(rootPtr, 80);

    // ������� ������ �� �����, ������������ �����
    inorder(rootPtr);

    /* ��� ������ ���������� ��� ������:
       Node 20 Parent: 30
       Node 30 Parent: 50
       Node 40 Parent: 30
       Node 50 Parent: NULL
       Node 60 Parent: 70
       Node 70 Parent: 50
       Node 80 Parent: 70
       Destructor
       Destructor
       Destructor
       Destructor
       Destructor
       Destructor
       Destructor
    */

    /* � ����� ��������� ��� ���� ������������� ���������,
       ���������� ����������� */
    return 0;
}

