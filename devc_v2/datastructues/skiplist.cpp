#include <iostream>
using namespace std;

class SkipList {
struct Node {
    int key;
    vector<Node*> next;
    Node(int key, int level) : key(key), next(level, nullptr) {}
    };

    Node* head;
    int maxLevel;
    int currentLevel;

    public:
        SkipList(int maxLvl = 6) : currentLevel(1), maxLevel(maxLvl) {
            head = new Node(-1, maxLevel);
        }

        bool insertWithLevel(int key, int lvl) {
            if (lvl < 1) lvl = 1;
            if (lvl > maxLevel) lvl = maxLevel;

            Node* cur = head;
            vector<Node*> update(maxLevel, nullptr);

            for(int i = currentLevel-1; i>=0; i--) {
                while(cur->next[i] && cur->next[i]->key < key) {
                    cur = cur->next[i];
                }
                update[i] = cur;
            }
            cur = update[0]->next[0];

            if (cur && cur->key == key) {
                cout<<"Key Already Exists"<<endl;
                return false;
            }

            if (lvl > currentLevel) {
                for (int i=currentLevel; i<lvl;i++){
                    update[i]=head;
                }
                currentLevel = lvl;
            }

            Node* node = new Node(key, lvl);

            for (int i=0;i<lvl;i++) {
                node->next[i] = update[i]->next[i];
                update[i]->next[i] = node;
            }
            cout<<"Insert key "<<key<<endl;
            return true;
        }

        bool search(int key) {
            Node* cur = head;
            for(int i=currentLevel-1; i>=0; i--) {
                while(cur->next[i] && cur->next[i]->key < key) {
                    cur = cur->next[i];
                }
            }
            cur = cur->next[0];
            if (cur && cur->key == key) {
                cout<<"Key Found!!!!"<<endl;
                return true;
            }
            cout<<"Key not Found!!!!"<<endl;
            return false;
        }

        bool erase(int key) {
            Node* cur = head;
            vector<Node*> update(maxLevel, nullptr);
            for(int i=currentLevel-1; i>=0; i--) {
                while(cur->next[i] && cur->next[i]->key < key) {
                    cur = cur->next[i];
                }
                update[i] = cur;
            }
            cur = update[0]->next[0];
            if (!cur || cur->key!=key) {
                cout<<"Key to erase not found!!!"<<endl;
                return false;
            }

            for (int i=0; i<currentLevel; i++) {
                if (update[i]->next[i] != cur) break;
                update[i]->next[i] = cur->next[i];
            }

            delete cur;

            cout<<"Key to be erased deleted!!!"<<endl;

            while(currentLevel>1 && head->next[currentLevel-1] == nullptr) {
                currentLevel--;
            }
            return true;
        }

        void printSkipList() const {
        std::cout << "\n--- SKIP LIST --- (top to bottom)\n";
        for (int i = currentLevel - 1; i >= 0; --i) {
            std::cout << "L" << i << ": ";
            Node* cur = head->next[i];
            while (cur) {
                std::cout << cur->key << " ";
                cur = cur->next[i];
            }
            std::cout << "\n";
        }
    }

};

int main() {
    SkipList sl;

    // Force levels so the structure is easy to reason about:
    // lvl=1 => only level0
    // lvl=2 => level0+level1
    // lvl=3 => level0+level1+level2
    // lvl=4 => level0+level1+level2+level3
    sl.insertWithLevel(1, 1);
    sl.insertWithLevel(3, 2);
    sl.insertWithLevel(6, 4);
    sl.insertWithLevel(7, 1);
    sl.insertWithLevel(9, 2);
    sl.insertWithLevel(12, 3);
    sl.insertWithLevel(19, 4);

    sl.printSkipList();

    // Now your question: why insert 10 at level 2?
    // Here we force it to lvl=2 (exists at L0 and L1).
    sl.insertWithLevel(10, 2);

    sl.printSkipList();

    sl.search(9);
    sl.erase(6);
    sl.printSkipList();
    return 0;
}