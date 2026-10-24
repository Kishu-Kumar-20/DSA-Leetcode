class Node {
public:
    string url;
    Node* next;
    Node* prev;
    Node() {
        url = "";
        next = NULL;
        prev = NULL;
    }
    Node(string s) {
        url = s;
        next = NULL;
        prev = NULL;
    }
    Node(string s, Node* next1, Node* prev1) {
        url = s;
        next = next1;
        prev = prev1;
    }
};
class BrowserHistory {
public:
    Node* pos;
    BrowserHistory(string homepage) {
        pos = new Node(homepage);
    }

    void visit(string url) {
        Node* p = new Node(url);
        p->prev = pos;
        pos->next = p;
        pos = p;
    }

    string back(int steps) {
        while (steps) {
            if (pos->prev)
                pos = pos->prev;
            else
                break;
            steps--;
        }
        return pos->url;
    }

    string forward(int steps) {
        while (steps) {
            if (pos->next)
                pos = pos->next;
            else
                break;
            steps--;
        }
        return pos->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */