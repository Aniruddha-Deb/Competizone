#include <iostream>

using namespace std;

template<class T>
struct Node {

    int key;
    T value;
    Node* next;

};

template<class T>
class HashMap {

private:
    static const int SIZE = 1007;

    Node<T>* list[SIZE];

    static const int hash(int s) {
        return s%1007;
    }

public:

    HashMap(): list{} {}

    T& operator[](int i) {
        // access
        int pos = hash(i);

        auto n = list[pos];
        while (n != nullptr and n->key != i) {
            n = n->next;
        }

        if (n == nullptr) {
            // create a new node
            Node<T>* a = list[pos];
            n = new Node<T>();
            n->key = i;
            n->next = a;
            list[pos] = n;
        }

        return n->value;
    }

    void remove(int k) {
        int pos = hash(k);

        auto n = list[pos];
        auto n_prev = n;
        int idx = 0;
        while (n != nullptr and n->key != k) {
            n_prev = n;
            n = n->next;
            idx++;
        }

        if (n != nullptr) {
            if (idx == 0) list[pos] = n->next;
            else n_prev->next = n->next;
            delete n;
        }
    }

    bool contains(int k) {
        int pos = hash(k);

        auto n = list[pos];
        while (n != nullptr and n->key != k) {
            n = n->next;
        }

        return (n != nullptr);
    }
};

// now testing

int main() {

    HashMap<string> strs;

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        int k;
        string s;
        cin >> k >> s;
        strs[k] = s;
    }

    for (int i=0; i<q; i++) {
        int k;
        cin >> k;
        cout << strs[k] << endl;
    }

    return 0;
}